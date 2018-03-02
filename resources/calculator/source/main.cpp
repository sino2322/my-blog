#include <iostream>
#include "Calculator.h"
using namespace std;

int main() {
    Calculator cal;
    cal.inputOperand(1);
    cal.inputOperator('+');
    cal.inputOperand(2);
    cal.inputOperator('x');
    cal.inputOperand(3);
    cal.inputOperator('/');
    cal.inputOperand(4);
    cal.inputOperator('-');
    cal.inputOperand(5);
    cout << cal.getResult() << endl;
    return 0;
}