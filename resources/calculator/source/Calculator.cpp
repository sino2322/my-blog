//
// Created by Sino on 2018/2/8.
//

#include "Calculator.h"

Calculator::Calculator() {
    this->operators = new(LinkedStack<char>);
    this->operands = new(LinkedStack<double>);
    this->status = WAITING;
}

Calculator::~Calculator() {
    delete this->operators;
    delete this->operands;
}

void Calculator::init() {
    delete this->operators;
    delete this->operands;
    this->operators = new(LinkedStack<char>);
    this->operands = new(LinkedStack<double>);
}

bool Calculator::checkCalculatable() {
    if (this->status == CALCULATABLE) return true;
    return false;
}

void Calculator::pushOperand(double op) {
    this->operands->push(op);
}

void Calculator::pushOperator(char op) {
    this->operators->push(op);
}

void Calculator::inputOperand(double op) {
    this->pushOperand(op);
}

void Calculator::inputOperator(char op) {
    this->pendingOperator = op;
    while (1) {
        this->checkOperator(op);
        if (this->status != CALCULATABLE)
            return;
        this->calculate();
    }
}

// 检查符号栈的排列并更新计算状态
void Calculator::checkOperator(char op) {
    char top = this->operators->getTop();
    // 如果符号栈为空则直接入栈
    if (this->operators->getLen() == 0)
    {
        this->pushOperator(op);
        this->status = WAITING;
        this->pendingOperator = '\0';
    }// 如果符号栈不为空且输入的是 +/- 则表明可以计算前一个符号
    else if (op == '+' || op == '-')
    {
        this->status = CALCULATABLE;
    }// 如果符号栈不为空且输入的为 x// 且前一个输入的符号为 +/- 则不能计算，继续等待
    else if (top == '-' || top == '+')
    {
        this->pushOperator(op);
        this->status = WAITING;
        this->pendingOperator = '\0';
    }// 如果符号栈不为空且输入的为 x// 且前一个输入的符号为 x// 则可以计算钱一个符号
    else
    {
        this->status = CALCULATABLE;
    }
}

void Calculator::calculate() {
    if (!this->checkCalculatable()) return;
    double A = 0, B = 0, C = 0;
    B = this->operands->pop();
    A = this->operands->pop();
    char op = '\0';
    op = this->operators->pop();

    switch (op) {
        case '+':
            C = A + B;
            break;
        case '-':
            C = A - B;
            break;
        case 'x':
            C = A * B;
            break;
        case '/':
            C = A / B;
            break;
    }
    this->pushOperand(C);
}

// 循环计算栈内数据，直到符号栈为空
double Calculator::getResult() {
    this->status = CALCULATABLE;
    while (1) {
        this->calculate();
        if (this->operators->getLen() == 0)
            return this->operands->getTop();
    }
}
