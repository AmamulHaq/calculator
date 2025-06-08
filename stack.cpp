#include <iostream>
#include <cmath>
#include <stack>
#include <vector>
#include <sstream>
#include <map>
#include <cctype>
using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == 'r'; // 'r' for root
}

// Function to get precedence of operators
int precedence(char op) {
    if (op == '^' || op == 'r') 
        return 4;
    if (op == '*' || op == '/') 
        return 3;
    if (op == '+' || op == '-') 
        return 2;
    return 0;
}

// Function to check associativity
bool isLeftAssociative(char op) {
    return (op != '^'); // Exponentiation is right-associative
}

// Function to convert infix to postfix
string infixToPostfix(const string& infix) {
    stack<char> operators;
    string postfix = "";
    
    for (char c : infix) {
        if (c == ' ') continue; // Skip spaces
        
        if (isalnum(c)) { // Operand (letter or digit)
            postfix += c;
        }
        else if (c == '(') {
            operators.push(c);
        }
        else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            if (!operators.empty()) operators.pop(); // Remove '('
        }
        else if (isOperator(c)) { // Operator
            while (!operators.empty() && operators.top() != '(') {
                char topOp = operators.top();
                if (precedence(topOp) > precedence(c) || 
                   (precedence(topOp) == precedence(c) && isLeftAssociative(c))) {
                    postfix += topOp;
                    operators.pop();
                }
                else break;
            }
            operators.push(c);
        }
    }
    
    // Pop remaining operators
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }
    
    return postfix;
}

// Function to print stack contents
void printStack(stack<double> s) {
    if (s.empty()) return;
    
    vector<double> elements;
    while (!s.empty()) {
        elements.push_back(s.top());
        s.pop();
    }
    
    for (int i = elements.size() - 1; i >= 0; --i) {
        cout << elements[i];
        if (i > 0) cout << ", ";
    }
}

// Function to evaluate postfix expression with steps
void evaluatePostfixWithSteps(const string& postfix, const map<char, double>& variables) {
    stack<double> operands;
    int step = 1;

    for (char token : postfix) {
        if (isalnum(token)) { // Operand
            double value;
            if (isdigit(token)) {
                value = token - '0';
            } else {
                if (variables.find(token) == variables.end()) {
                    cout << "Error: Variable '" << token << "' not defined." << endl;
                    return;
                }
                value = variables.at(token);
            }
            
            operands.push(value);
            cout << "Step " << step++ << ": Push " << value << " (stack: ";
            printStack(operands);
            cout << ")" << endl;
        }
        else { // Operator
            if (operands.size() < 2) {
                cout << "Error: Insufficient operands for operator." << endl;
                return;
            }
            
            double operand2 = operands.top(); operands.pop();
            double operand1 = operands.top(); operands.pop();
            
            double result;
            string opStr;
            switch (token) {
                case '+': 
                    result = operand1 + operand2; 
                    opStr = "+"; 
                    break;
                case '-': 
                    result = operand1 - operand2; 
                    opStr = "-"; 
                    break;
                case '*': 
                    result = operand1 * operand2; 
                    opStr = "×"; 
                    break;
                case '/': 
                    if (operand2 == 0) {
                        cout << "Error: Division by zero." << endl;
                        return;
                    }
                    result = operand1 / operand2; 
                    opStr = "÷"; 
                    break;
                case '^': 
                    result = pow(operand1, operand2); 
                    opStr = "^"; 
                    break;
                case 'r': // root operation
                    if (operand1 < 0 && fmod(operand2, 2) == 0) {
                        cout << "Error: Even root of negative number." << endl;
                        return;
                    }
                    result = pow(operand1, 1.0 / operand2); 
                    opStr = "√"; 
                    break;
                default:
                    cout << "Error: Unknown operator '" << token << "'" << endl;
                    return;
            }
            
            operands.push(result);
            cout << "Step " << step++ << ": Apply " << opStr << " to " << operand1 
                 << " and " << operand2 << " = " << result << " (stack: ";
            printStack(operands);
            cout << ")" << endl;
        }
    }
    
    if (operands.size() != 1) {
        cout << "Error: Malformed expression" << endl;
        return;
    }
    
    cout << "Final Result: " << operands.top() << endl;
}

// Main function with menu
int main() {
    int choice;
    
    while (true) {
        cout << "\n1. Evaluate Expression\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        if (choice == 0) {
            break;
        }
        else if (choice == 1) {
            string infix;
            cout << "Enter infix expression (e.g., (A+B)*C): ";
            cin.ignore();
            getline(cin, infix);
            
            string postfix = infixToPostfix(infix);
            cout << "Postfix expression: " << postfix << endl;
            
            map<char, double> variables;
            for (char c : infix) {
                if (isalpha(c) && variables.find(c) == variables.end()) {
                    cout << "Enter value for " << c << ": ";
                    cin >> variables[c];
                }
            }
            
            evaluatePostfixWithSteps(postfix, variables);
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    
    return 0;
}
