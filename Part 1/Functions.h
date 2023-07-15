#include <string>

bool isOperator(char ch);
int getPrecedence(char op);
std::string infixToPostfix(const std::string& expression);
bool isBalancedParentheses(const std::string& expression);
