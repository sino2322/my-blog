'use strict';

const stack = require("./linked_stack");

const CALC = {
    waiting: 0,
    calculatable: 1
}

function Calculator() {
    let operators = stack.new();
    let operands = stack.new();
    let status = CALC.waiting;
    let pendingOperator = '';

    this.init = function() {
        operators.init();
        operands.init();
        status = CALC.waiting;
        pendingOperator = '';
    }
    this.inputOperand = function(op) {
        pushOperand(op);
    }
    this.inputOperator = function inputOperator(op) {
        pendingOperator = op;
        while (1) {
            checkOperator(op);
            if (status != CALC.calculatable)
                return;
            calculate();
        }
    }
    this.getResult = function() {
        status = CALC.calculatable;
        while (1) {
            calculate();
            if (operators.len() == 0)
                return operands.getTop();
        }
    }

    function checkCalculatable() {
        if (status == CALC.calculatable) return true;
        return false
    }

    function pushOperand(op) {
        operands.push(op);
    }

    function pushOperator(op) {
        operators.push(op);
    }

    function calculate() {
        if (!checkCalculatable()) return;
        let B = operands.pop();
        let A = operands.pop();
        let op = operators.pop();
        let C;
        switch (op) {
            case "+":
                C = A + B;
                break;
            case "-":
                C = A - B;
                break;
            case "x":
                C = A * B;
                break;
            case "/":
                C = A / B;
                break;
        }
        pushOperand(C);
    }

    function checkOperator(op) {
        let top = operators.getTop();
        if (operators.len() == 0) {
            pushOperator(op);
            status = CALC.waiting;
            pendingOperator = '';
        } else if (op === "+" || op === "-") {
            status = CALC.calculatable;
        } else if (top === "-" || top === "+") {
            pushOperator(op);
            status = CALC.waiting;
            pendingOperator = '';
        } else {
            status = CALC.calculatable;
        }
    }
}

module.exports.new = () => new Calculator();

// let cal = new Calculator();
// cal.inputOperand(1);
// cal.inputOperator("+");
// cal.inputOperand(2);
// cal.inputOperator("x");
// cal.inputOperand(3);
// cal.inputOperator("/");
// cal.inputOperand(4);
// cal.inputOperator("-");
// cal.inputOperand(5);
// let res = cal.getResult();