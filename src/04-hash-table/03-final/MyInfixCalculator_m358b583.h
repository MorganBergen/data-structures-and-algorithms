#ifndef __MYINFIXCALCULATOR_H__
#define __MYINFIXCALCULATOR_H__

#include <algorithm>
#include <string>

#include "MyStack_m358b583.h"
#include "MyVector_m358b583.h"

class MyInfixCalculator{

    public:

        MyInfixCalculator() { }

        ~MyInfixCalculator() { }

        double calculate(const std::string& s) {
            MyVector<std::string> infix;
            MyVector<std::string> postfix;
            tokenize(s, infix);
            infixToPostfix(infix, postfix);
            return calPostfix(postfix);
        }

    private:

        void printStack(MyStack<std::string> stack) {
            if (stack.empty()) {
                std::cout << "the stack is currently empty" << std::endl;
                return;
            }
            while (!stack.empty()) {
                std::cout << stack.top() << std::endl;
                stack.pop();
            }
            std::cout << "end stack" << std::endl;
        }
        bool isFloat( const std::string & maybeNum ) const {
            try {
                std::stof( maybeNum );
                return true;
            }catch(...) {
                return false;
            }
        }

        void printTokens(MyVector<std::string> tokens) {
            std::string tokeString= "";
            for (int i = 0; i < tokens.size(); i++) {
                tokeString += tokens[i] + " ";
            }
            std::cout << tokeString << std::endl;
        }

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
            size_t string_length = s.length();
            char c;
            std::string tok = "";
            int i = 0;
            while (i < string_length) {
                c = s[ i ];
                tok = "";

                if (( c == '-' && operatorPrec(s[ i - 1 ]) != -1) || (i == 1 && s[ i - 1 ] == '-')  || (i == 0 && c == '-')) {
                    tok += '-';
                    c = s[ i + 1 ];
                    i++;
                }
                if ( c == '-' && s[i-1] == '(' ) {
                    tok += '-';
                    c = s[ i + 1 ];
                    i++;
                }
                if (isDigit(c) || c == '.') {

                    while (i < string_length && (isDigit(s[i]) || s[i] == '.')) {
                        tok += c;
                        i++;
                        if (i != string_length) { 
                            c = s[i]; 
                        }
                    }
                    tokens.push_back(tok);
                }

                else if ((i < lenStr) && (operatorPrec(c) != -1 || c == '(' || c == ')')) {
                    tok = c;
                    i++;
                    tokens.push_back(tok);
                }
            }
        }

        // converts a set of infix tokens to a set of postfix tokens
        void infixToPostfix(MyVector<std::string>& infix_tokens, MyVector<std::string>& postfix_tokens) {
            size_t token_length = infix_tokens.size();
            std::string token = "";
            MyStack<std::string> stack;
            int i = 0;

            while (i < token_length) {
                token = infix_tokens[ i ];
                if (token == "(") {
                    stack.push( token );
                }
                else if (isFloat(token)) {
                    postfix_tokens.push_back(token);
                }
                else if (token == ")") {
                    while (!stack.empty() && stack.top() != "(") {
                        postfix_tokens.push_back( stack.top() );
                        stack.pop();
                    }
                    stack.pop(); 
                }
                else if (token == "+" || token == "-" || token == "*" || token == "/") {
                    if (stack.empty()) {
                        stack.push( token );
                    }
                    else if (operatorPrec(stack.top()[0]) > operatorPrec(token[0])) {
                        stack.push( token );
                    }
                    else {
                        while (!stack.empty() && operatorPrec(stack.top()[0]) <= operatorPrec(token[0]) && stack.top() != "(") {
                            postfix_tokens.push_back(stack.top());
                            stack.pop();			            
                        }
                        stack.push(token);                    		            
                    }
                }	        
                i++;
            }
            while(!stack.empty()) {
                postfix_tokens.push_back( stack.top() );
                stack.pop();
            }	 
        }
        // calculates the final result from postfix tokens
        double calPostfix(const MyVector<std::string>& postfix_tokens) const {
            MyStack<std::string> stack;
            int i = 0;
            std::string cur;
            std::string oprnd1, oprnd2;
            while (i < postfix_tokens.size()) {
                cur = postfix_tokens[ i ];
                if (isFloat(cur)) {
                    stack.push( cur );
                }
                else {
                    oprnd2 = stack.top();
                    stack.pop();
                    oprnd1 = stack.top();
                    stack.pop();
                    double temp = computeBinaryOperation(oprnd1, oprnd2, cur);
                    stack.push(std::to_string(temp));
                }
                i++;
            }
            double result = std::stod( stack.top() );
            stack.pop();
            return result;
        }
};

#endif
