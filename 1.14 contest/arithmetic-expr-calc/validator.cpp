#include <bits/stdc++.h>
#include "testlib.h"

bool isValid(const std::string &expr) {
    std::stack<char> st;
    bool lastWasOperator = true;  // 用于检查表达式开头
    bool lastWasDigit = false;    // 用于检查连续数字

    for (size_t i = 0; i < expr.length(); i++) {
        char c = expr[i];
        
        // 处理@结束符
        if (c == '@') {
            if (i != expr.length() - 1) return false;  // @必须在最后
            continue;
        }

        // 检查字符是否合法
        if (!strchr("0123456789+-*/^()", c)) return false;

        // 检查括号匹配
        if (c == '(') {
            st.push(c);
            lastWasOperator = true;
            lastWasDigit = false;
        }
        else if (c == ')') {
            if (st.empty() || lastWasOperator) return false;
            st.pop();
            lastWasOperator = false;
            lastWasDigit = false;
        }
        // 检查数字
        else if (isdigit(c)) {
            lastWasOperator = false;
            lastWasDigit = true;
        }
        // 检查运算符
        else {
            if (lastWasOperator) return false;  // 不允许连续运算符
            lastWasOperator = true;
            lastWasDigit = false;
        }
    }

    return st.empty() && !lastWasOperator;  // 确保括号匹配且不以运算符结尾
}

bool hasZeroDivision(const std::string &expr) {
    std::stack<int> nums;
    std::stack<char> ops;
    
    for (size_t i = 0; i < expr.length() && expr[i] != '@'; i++) {
        char c = expr[i];
        
        if (isdigit(c)) {
            nums.push(c - '0');
        }
        else if (c == '(') {
            ops.push(c);
        }
        else if (c == ')') {
            while (!ops.empty() && ops.top() != '(') {
                char op = ops.top();
                ops.pop();
                
                if (nums.size() < 2) continue;
                
                int b = nums.top(); nums.pop();
                int a = nums.top(); nums.pop();
                
                if (op == '/' && b == 0) return true;
                
                // 计算结果并压回栈中
                int result;
                switch (op) {
                    case '+': result = a + b; break;
                    case '-': result = a - b; break;
                    case '*': result = a * b; break;
                    case '/': result = a / b; break;
                    case '^': result = pow(a, b); break;
                    default: result = 0;
                }
                nums.push(result);
            }
            if (!ops.empty()) ops.pop();  // 弹出'('
        }
        else if (strchr("+-*/^", c)) {
            while (!ops.empty() && ops.top() != '(' && 
                   ((c != '^' && (ops.top() == '*' || ops.top() == '/' || ops.top() == '^')) ||
                    (c != '^' && (ops.top() == '+' || ops.top() == '-')))) {
                char op = ops.top();
                ops.pop();
                
                if (nums.size() < 2) continue;
                
                int b = nums.top(); nums.pop();
                int a = nums.top(); nums.pop();
                
                if (op == '/' && b == 0) return true;
                
                // 计算结果并压回栈中
                int result;
                switch (op) {
                    case '+': result = a + b; break;
                    case '-': result = a - b; break;
                    case '*': result = a * b; break;
                    case '/': result = a / b; break;
                    case '^': result = pow(a, b); break;
                    default: result = 0;
                }
                nums.push(result);
            }
            ops.push(c);
        }
    }
    
    while (!ops.empty()) {
        char op = ops.top();
        ops.pop();
        
        if (nums.size() < 2) continue;
        
        int b = nums.top(); nums.pop();
        int a = nums.top(); nums.pop();
        
        if (op == '/' && b == 0) return true;
        
        // 计算结果并压回栈中
        int result;
        switch (op) {
            case '+': result = a + b; break;
            case '-': result = a - b; break;
            case '*': result = a * b; break;
            case '/': result = a / b; break;
            case '^': result = pow(a, b); break;
            default: result = 0;
        }
        nums.push(result);
    }
    
    return false;
}

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);

    std::string expr = inf.readToken("[0123456789+\\-*/^()@]*");
    inf.readEoln();

    ensuref(isValid(expr), "The expression is not a valid infix expression.");
    ensuref(hasZeroDivision(expr) == false, "The expression has zero division.");

    inf.readEof();
}