#include <iostream>
#include <string>
#include "functions.h"

using namespace std;

int main() {
    string infixExpression;
    cout << "Enter an infix expression: ";
    getline(cin, infixExpression);

    if (!isBalancedParentheses(infixExpression)) {
        cout << "Invalid expression: Unbalanced parentheses." << endl;
        return 0;
    }

    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix expression: " << postfixExpression << endl;

    return 0;
}
