//
// Created by Sino on 2018/2/8.
//

#ifndef CALCULATOR_CALCULATOR_H
#define CALCULATOR_CALCULATOR_H

#include "LinkedStack.h"

class Calculator {
    enum {
        WAITING = 0,
        CALCULATABLE
    };
public:
    Calculator();

    ~Calculator();

    // init 初始化状态及运算符和运算数
    void init();

    // getResult 输入等号
    double getResult();

    // inputOperator 输入运算符
    void inputOperator(char op);

    // inputOperand 输入运算数
    void inputOperand(double op);

private:
    // operators 运算符栈
    LinkedStack<char> *operators;

    // operands 运算数栈
    LinkedStack<double> *operands;

    // status 计算状态，WAITING 时不能计算，CALCULATABLE 时可计算
    int status;

    // pendingOperator 待入栈的运算符
    char pendingOperator;

    // checkCalculatable 检查是否可计算，可计算则返回真
    bool checkCalculatable();

    // checkOperator 检查待入栈运算符的优先级，并修改计算器状态
    void checkOperator(char op);

    // pushOperator 压入运算符栈
    void pushOperator(char op);

    // pushOperand 压入运算数栈
    void pushOperand(double op);

    // calculate 进行阶段性计算
    void calculate();
};

#endif //CALCULATOR_CALCULATOR_H
