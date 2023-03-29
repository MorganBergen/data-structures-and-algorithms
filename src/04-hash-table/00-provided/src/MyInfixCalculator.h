#ifndef __MYINFIXCALCULATOR_H__
#define __MYINFIXCALCULATOR_H__

#include <algorithm>
#include <string>

#include "MyStack.h"
#include "MyVector.h"

class MyInfixCalculator {

  public:
    
    MyInfixCalculator() {
    }

    ~MyInfixCalculator() {
    }

    double calculate(const std::string& s) {
        MyVector<std::string> infix_tokens;
        tokenize(s, infix_tokens);
        MyVector<std::string> postfix_tokens;
        infixToPostfix(infix_tokens, postfix_tokens);
        return calPostfix(postfix_tokens);
    }

  private:

    // returns operator precedance; the smaller the number the higher precedence
    // returns -1 if the operator is invalid
    // does not consider parenthesis
    int operatorPrec(const char c) const {
        switch(c) {
            case '*': 
                return 2;
            case '/':
                return 2;
            case '+':
                return 3;
            case '-':
                return 3;
            default:
                return -1;
        }
    }

    // checks if a character corresponds to a valid parenthesis
    bool isValidParenthesis(const char c) const {
        switch(c) {
            case '(':
                return true;
            case ')':
                return true;
            default:
                return false;
        }
    }

    // checks if a character corresponds to a valid digit
    bool isDigit(const char c) const {
        if(c >= '0' && c <= '9')
            return true;
        return false;
    }

    // computes binary operation given the two operands and the operator in their string form
    double computeBinaryOperation(const std::string& ornd1, const std::string& ornd2, const std::string& opt) const {
        double o1 = std::stod(ornd1);
        double o2 = std::stod(ornd2);
        switch(opt[0]) {
            case '+':
                return o1 + o2;
            case '-':
                return o1 - o2;
            case '*':
                return o1 * o2;
            case '/':
                return o1 / o2;
            default:
                std::cout << "Error: unrecognized operator: " << opt << std::endl;
                return 0.0;
        }
    }


    // tokenizes an infix string s into a set of tokens (operands or operators)
    void tokenize(const std::string& s, MyVector<std::string>& tokens) {
        std::string token;
        for (char c : s) {
            if (c == ' ') {
                continue;
            } else if (operatorPrec(c) != -1 || isValidParenthesis(c)) {
                if (!token.empty()) {
                    tokens.push_back(token);
                    token.clear();
                }
                tokens.push_back(std::string(1, c));
            } else {
                token += c;
            }
        }
        if (!token.empty()) {
            tokens.push_back(token);
        }
    }

    // converts a set of infix tokens to a set of postfix tokens
    void infixToPostfix(MyVector<std::string>& infix_tokens, MyVector<std::string>& postfix_tokens) {
        MyStack<std::string> opStack;
        for (const std::string& token : infix_tokens) {
            if (operatorPrec(token[0]) != -1) {
                while (!opStack.empty() && operatorPrec(opStack.top()[0]) <= operatorPrec(token[0])) {
                    postfix_tokens.push_back(opStack.top());
                    opStack.pop();
                }
                opStack.push(token);
            } else if (isValidParenthesis(token[0])) {
                if (token[0] == '(') {
                    opStack.push(token);
                } else {
                    while (!opStack.empty() && opStack.top() != "(") {
                        postfix_tokens.push_back(opStack.top());
                        opStack.pop();
                    }
                    opStack.pop(); // Remove the '('
                }
            } else {
                postfix_tokens.push_back(token);
            }
        }
        while (!opStack.empty()) {
            postfix_tokens.push_back(opStack.top());
            opStack.pop();
        }
    }

    // calculates the final result from postfix tokens
    double calPostfix(const MyVector<std::string>& postfix_tokens) const {
        MyStack<double> valStack;
        for (const std::string& token : postfix_tokens) {
            if (operatorPrec(token[0]) != -1) {
                double val2 = valStack.top();
                valStack.pop();
                double val1 = valStack.top();
                valStack.pop();
                valStack.push(computeBinaryOperation(std::to_string(val1), std::to_string(val2), token));
            } else {
                valStack.push(std::stod(token));
            }
        }
        return valStack.top();
    }
};

#endif // __MYINFIXCALCULATOR_H__
