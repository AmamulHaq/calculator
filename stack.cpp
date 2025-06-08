#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <stdexcept>
#include <cmath>
#include <map>
using namespace std;

// Token structure to hold components of the expression
struct Token {
    string value;
    bool isOperator;
    bool isVariable;
    bool isNumber;

    Token(string val, bool isOp, bool isVar, bool isNum)
        : value(val), isOperator(isOp), isVariable(isVar), isNumber(isNum) {}
};

// Tokenize the input expression
vector<Token> tokenize(const string& expr) {
    vector<Token> tokens;
    string current;
    bool expectUnary = true;

    for (size_t i = 0; i < expr.size();) {
        if (isspace(expr[i])) { 
            ++i; 
            continue; 
        }

        if (expectUnary && (expr[i] == '+' || expr[i] == '-')) {
            string op = (expr[i] == '-') ? "u-" : "u+";
            tokens.emplace_back(op, true, false, false);
            ++i;
            continue;
        }

        if (isdigit(expr[i])) {
            current += expr[i++];
            while (i < expr.size() && (isdigit(expr[i]) || expr[i] == '.')) {
                current += expr[i++];
            }
            tokens.emplace_back(current, false, false, true);
            current.clear();
            expectUnary = false;
            continue;
        }

        if (isalpha(expr[i])) {
            tokens.emplace_back(string(1, expr[i]), false, true, false);
            ++i;
            expectUnary = false;
            continue;
        }

        if (expr[i] == '^' || expr[i] == '*' || expr[i] == '/' ||
            expr[i] == '+' || expr[i] == '-' || expr[i] == '(' || expr[i] == ')') {
            tokens.emplace_back(string(1, expr[i]), true, false, false);
            ++i;
            expectUnary = (expr[i-1] == '(' || expr[i-1] == '+' || expr[i-1] == '-' ||
                          expr[i-1] == '*' || expr[i-1] == '/' || expr[i-1] == '^');
            continue;
        }

        ++i;
    }

    return tokens;
}

// Convert infix tokens to postfix notation
vector<Token> infixToPostfix(const vector<Token>& tokens) {
    vector<Token> output;
    stack<Token> opStack;

    auto precedence = [](const string& op) {
        if (op == "u-" || op == "u+") return 5;
        if (op == "^") return 4;
        if (op == "*" || op == "/") return 3;
        if (op == "+" || op == "-") return 2;
        return 0;
    };

    auto isRightAssoc = [](const string& op) { return op == "^"; };

    for (const Token& token : tokens) {
        if (!token.isOperator) {
            output.push_back(token);
        } else if (token.value == "(") {
            opStack.push(token);
        } else if (token.value == ")") {
            while (!opStack.empty() && opStack.top().value != "(") {
                output.push_back(opStack.top());
                opStack.pop();
            }
            if (!opStack.empty()) opStack.pop();
        } else {
while (!opStack.empty() && opStack.top().value != "(" &&
       (precedence(opStack.top().value) > precedence(token.value) ||
       (precedence(opStack.top().value) == precedence(token.value) && 
        !isRightAssoc(token.value)))) {  // <-- added missing ')'
    output.push_back(opStack.top());
    opStack.pop();
}
opStack.push(token);

        }
    }

    while (!opStack.empty()) {
        output.push_back(opStack.top());
        opStack.pop();
    }
    return output;
}

// Format a number to string, removing trailing zeros
string formatNumber(double num) {
    ostringstream oss;
    if (num == static_cast<int>(num)) {
        oss << static_cast<int>(num);
    } else {
        oss.precision(3);
        oss << fixed << num;
        string s = oss.str();
        size_t last = s.find_last_not_of('0') + 1;
        if (s[last-1] == '.') last--;
        s.erase(last, string::npos);
        return s;
    }
    return oss.str();
}

// Simplify the expression tokens
vector<Token> simplify(const vector<Token>& tokens) {
    struct ExprPart {
        vector<Token> expr;
        bool isNumber;
        double numValue;
        ExprPart(const vector<Token>& e, bool isNum = false, double num = 0) : expr(e), isNumber(isNum), numValue(num) {}
    };

    stack<ExprPart> st;

    auto isZero = [](const ExprPart& part) {
        return part.isNumber && abs(part.numValue) < 1e-10;
    };

    auto isOne = [](const ExprPart& part) {
        return part.isNumber && abs(part.numValue - 1.0) < 1e-10;
    };

    for (const Token& tok : tokens) {
        if (!tok.isOperator) {
            if (tok.isNumber) {
                double num = stod(tok.value);
                st.push(ExprPart({tok}, true, num));
            } else {
                st.push(ExprPart({tok}));
            }
        } else {
            if (tok.value == "u-") {
                if (st.empty()) continue;
                ExprPart a = st.top(); st.pop();
                if (a.isNumber) {
                    st.push(ExprPart({Token(formatNumber(-a.numValue), false, false, true)}, true, -a.numValue));
                } else {
                    vector<Token> newExpr;
                    newExpr.emplace_back("u-", true, false, false);
                    newExpr.insert(newExpr.end(), a.expr.begin(), a.expr.end());
                    st.push(ExprPart(newExpr));
                }
            } else {
                if (st.size() < 2) continue;
                ExprPart b = st.top(); st.pop();
                ExprPart a = st.top(); st.pop();
                vector<Token> newExpr;

                if (tok.value == "+") {
                    if (isZero(a)) {
                        st.push(b);
                    } else if (isZero(b)) {
                        st.push(a);
                    } else if (a.isNumber && b.isNumber) {
                        double num = a.numValue + b.numValue;
                        st.push(ExprPart({Token(formatNumber(num), false, false, true)}, true, num));
                    } else {
                        newExpr = a.expr;
                        newExpr.insert(newExpr.end(), b.expr.begin(), b.expr.end());
                        newExpr.emplace_back("+", true, false, false);
                        st.push(ExprPart(newExpr));
                    }
                } else if (tok.value == "-") {
                    if (isZero(b)) {
                        st.push(a);
                    } else if (a.isNumber && b.isNumber) {
                        double num = a.numValue - b.numValue;
                        st.push(ExprPart({Token(formatNumber(num), false, false, true)}, true, num));
                    } else {
                        newExpr = a.expr;
                        newExpr.insert(newExpr.end(), b.expr.begin(), b.expr.end());
                        newExpr.emplace_back("-", true, false, false);
                        st.push(ExprPart(newExpr));
                    }
                } else if (tok.value == "*") {
                    if (isZero(a) || isZero(b)) {
                        st.push(ExprPart({Token("0", false, false, true)}, true, 0.0));
                    } else if (isOne(a)) {
                        st.push(b);
                    } else if (isOne(b)) {
                        st.push(a);
                    } else if (a.isNumber && b.isNumber) {
                        double num = a.numValue * b.numValue;
                        st.push(ExprPart({Token(formatNumber(num), false, false, true)}, true, num));
                    } else {
                        newExpr = a.expr;
                        newExpr.insert(newExpr.end(), b.expr.begin(), b.expr.end());
                        newExpr.emplace_back("*", true, false, false);
                        st.push(ExprPart(newExpr));
                    }
                } else if (tok.value == "/") {
                    if (isZero(a)) {
                        st.push(ExprPart({Token("0", false, false, true)}, true, 0.0));
                    } else if (isZero(b)) {
                        throw runtime_error("Division by zero");
                    } else if (isOne(b)) {
                        st.push(a);
                    } else if (a.isNumber && b.isNumber) {
                        double num = a.numValue / b.numValue;
                        st.push(ExprPart({Token(formatNumber(num), false, false, true)}, true, num));
                    } else {
                        newExpr = a.expr;
                        newExpr.insert(newExpr.end(), b.expr.begin(), b.expr.end());
                        newExpr.emplace_back("/", true, false, false);
                        st.push(ExprPart(newExpr));
                    }
                } else if (tok.value == "^") {
                    if (isZero(b)) {
                        st.push(ExprPart({Token("1", false, false, true)}, true, 1.0));
                    } else if (isOne(b)) {
                        st.push(a);
                    } else if (isZero(a)) {
                        st.push(ExprPart({Token("0", false, false, true)}, true, 0.0));
                    } else if (a.isNumber && b.isNumber) {
                        double num = pow(a.numValue, b.numValue);
                        st.push(ExprPart({Token(formatNumber(num), false, false, true)}, true, num));
                    } else {
                        newExpr = a.expr;
                        newExpr.insert(newExpr.end(), b.expr.begin(), b.expr.end());
                        newExpr.emplace_back("^", true, false, false);
                        st.push(ExprPart(newExpr));
                    }
                } else {
                    newExpr = a.expr;
                    newExpr.insert(newExpr.end(), b.expr.begin(), b.expr.end());
                    newExpr.emplace_back(tok.value, true, false, false);
                    st.push(ExprPart(newExpr));
                }
            }
        }
    }

    if (st.empty()) return {Token("0", false, false, true)};
    return st.top().expr;
}

// Differentiate the expression with respect to a variable
vector<Token> differentiate(const vector<Token>& postfix, char var) {
    struct TermDeriv {
        vector<Token> term;
        vector<Token> deriv;
    };

    stack<TermDeriv> diffStack;

    for (const Token& token : postfix) {
        if (!token.isOperator) {
            vector<Token> deriv;
            if (token.isVariable) {
                if (token.value.size() == 1 && token.value[0] == var) {
                    deriv = {Token("1", false, false, true)};
                } else {
                    deriv = {Token("0", false, false, true)};
                }
            } else if (token.isNumber) {
                deriv = {Token("0", false, false, true)};
            } else {
                deriv = {Token("0", false, false, true)};
            }
            diffStack.push({{token}, deriv});
        } else {
            if (token.value == "u-") {
                TermDeriv a = diffStack.top(); diffStack.pop();
                vector<Token> new_deriv = a.deriv;
                new_deriv.emplace_back("u-", true, false, false);
                diffStack.push({{}, new_deriv});
            } else if (token.value == "+" || token.value == "-") {
                TermDeriv b = diffStack.top(); diffStack.pop();
                TermDeriv a = diffStack.top(); diffStack.pop();
                vector<Token> new_deriv = a.deriv;
                new_deriv.insert(new_deriv.end(), b.deriv.begin(), b.deriv.end());
                new_deriv.emplace_back(token.value, true, false, false);
                diffStack.push({{}, new_deriv});
            } else if (token.value == "*") {
                TermDeriv b = diffStack.top(); diffStack.pop();
                TermDeriv a = diffStack.top(); diffStack.pop();
                vector<Token> term1 = a.deriv;
                term1.insert(term1.end(), b.term.begin(), b.term.end());
                term1.emplace_back("*", true, false, false);

                vector<Token> term2 = a.term;
                term2.insert(term2.end(), b.deriv.begin(), b.deriv.end());
                term2.emplace_back("*", true, false, false);

                vector<Token> new_deriv;
                new_deriv.insert(new_deriv.end(), term1.begin(), term1.end());
                new_deriv.insert(new_deriv.end(), term2.begin(), term2.end());
                new_deriv.emplace_back("+", true, false, false);

                diffStack.push({{}, new_deriv});
            } else if (token.value == "^") {
                TermDeriv exponent = diffStack.top(); diffStack.pop();
                TermDeriv base = diffStack.top(); diffStack.pop();

                vector<Token> derivTerm;
                if (exponent.term.size() == 1 && exponent.term[0].isNumber) {
                    double exponentValue = stod(exponent.term[0].value);
                    double newExponentValue = exponentValue - 1;
                    string newExponentStr = formatNumber(newExponentValue);

                    vector<Token> part1 = exponent.term;
                    part1.insert(part1.end(), base.term.begin(), base.term.end());
                    part1.emplace_back(newExponentStr, false, false, true);
                    part1.emplace_back("^", true, false, false);
                    part1.emplace_back("*", true, false, false);
                    part1.insert(part1.end(), base.deriv.begin(), base.deriv.end());
                    part1.emplace_back("*", true, false, false);

                    derivTerm = part1;
                } else {
                    derivTerm = {Token("0", false, false, true)};
                }

                vector<Token> new_term;
                new_term.insert(new_term.end(), base.term.begin(), base.term.end());
                new_term.insert(new_term.end(), exponent.term.begin(), exponent.term.end());
                new_term.emplace_back("^", true, false, false);

                diffStack.push({new_term, derivTerm});
            }
        }
    }

    if (diffStack.empty()) 
        return {Token("0", false, false, true)};

    vector<Token> result = simplify(diffStack.top().deriv);
    return result;
}

// Convert tokens to a readable string expression
string tokensToString(const vector<Token>& tokens) {
    struct ExprInfo {
        string expr;
        int precedence;
        bool isUnary;
    };
    stack<ExprInfo> exprStack;

    auto getPrecedence = [](const string& op) {
        if (op == "u-" || op == "u+") return 5;
        if (op == "^") return 4;
        if (op == "*" || op == "/") return 3;
        if (op == "+" || op == "-") return 2;
        return 0;
    };

    for (const Token& token : tokens) {
        if (!token.isOperator) {
            exprStack.push({token.value, 0, false});
        } else {
            if (token.value == "u-" || token.value == "u+") {
                if (exprStack.empty()) continue;
                ExprInfo operand = exprStack.top();
                exprStack.pop();
                int current_prec = getPrecedence(token.value);
                string op = (token.value == "u-") ? "-" : "+";
                bool needParen = operand.precedence < current_prec || (operand.isUnary && operand.precedence == current_prec);
                string expr;
                if (needParen) {
                    expr = op + "(" + operand.expr + ")";
                } else {
                    expr = op + operand.expr;
                }
                exprStack.push({expr, current_prec, true});
            } else {
                if (exprStack.size() < 2) continue;
                ExprInfo right = exprStack.top();
                exprStack.pop();
                ExprInfo left = exprStack.top();
                exprStack.pop();

                int current_prec = getPrecedence(token.value);
                bool isRightAssoc = (token.value == "^");
                string op = token.value;

                string left_expr = left.expr;
                if (left.precedence != 0 && (left.precedence < current_prec || (left.precedence == current_prec && !isRightAssoc))) {
                    left_expr = "(" + left_expr + ")";
                }

                string right_expr = right.expr;
                if (right.precedence != 0 && (right.precedence < current_prec || (right.precedence == current_prec && isRightAssoc))) {
                    right_expr = "(" + right_expr + ")";
                }

                string combined = left_expr + " " + op + " " + right_expr;
                exprStack.push({combined, current_prec, false});
            }
        }
    }

    if (exprStack.empty()) return "0";
    string result = exprStack.top().expr;

    size_t start = 0;
    while (start < result.size() && result[start] == ' ') start++;
    size_t end = result.size();
    while (end > 0 && result[end-1] == ' ') end--;
    result = result.substr(start, end - start);

    if (result.size() >= 2 && result.front() == '(' && result.back() == ')') {
        bool hasMatching = true;
        size_t balance = 1;
        for (size_t i = 1; i < result.size() - 1; ++i) {
            if (result[i] == '(') balance++;
            else if (result[i] == ')') balance--;
            if (balance == 0) {
                hasMatching = false;
                break;
            }
        }
        if (hasMatching && balance == 1) {
            result = result.substr(1, result.size() - 2);
        }
    }
    return result.empty() ? "0" : result;
}

// Evaluate postfix expression with step-by-step display
void evaluatePostfixWithSteps(const vector<Token>& postfix, const map<char, double>& variables) {
    stack<double> operands;
    int step = 1;

    for (const Token& token : postfix) {
        if (!token.isOperator) {
            double value;
            if (token.isNumber) {
                value = stod(token.value);
            } else if (token.isVariable) {
                char var = token.value[0];
                if (variables.find(var) == variables.end()) {
                    cout << "Error: Variable '" << var << "' not defined." << endl;
                    return;
                }
                value = variables.at(var);
            } else {
                cout << "Error: Invalid token '" << token.value << "'" << endl;
                return;
            }
            operands.push(value);
            cout << "Step " << step++ << ": Push " << value << " (stack: ";
            stack<double> temp = operands;
            vector<double> tempVec;
            while (!temp.empty()) {
                tempVec.push_back(temp.top());
                temp.pop();
            }
            reverse(tempVec.begin(), tempVec.end());
            for (size_t i = 0; i < tempVec.size(); ++i) {
                cout << tempVec[i];
                if (i < tempVec.size() - 1) cout << ", ";
            }
            cout << ")" << endl;
        } else {
            if (token.value == "u-") {
                if (operands.size() < 1) {
                    cout << "Error: Insufficient operands for unary operator." << endl;
                    return;
                }
                double operand = operands.top(); operands.pop();
                double result = -operand;
                operands.push(result);
                cout << "Step " << step++ << ": Apply unary - to " << operand << " = " << result << " (stack: ";
                stack<double> temp = operands;
                vector<double> tempVec;
                while (!temp.empty()) {
                    tempVec.push_back(temp.top());
                    temp.pop();
                }
                reverse(tempVec.begin(), tempVec.end());
                for (size_t i = 0; i < tempVec.size(); ++i) {
                    cout << tempVec[i];
                    if (i < tempVec.size() - 1) cout << ", ";
                }
                cout << ")" << endl;
            } else {
                if (operands.size() < 2) {
                    cout << "Error: Insufficient operands for binary operator." << endl;
                    return;
                }
                double operand2 = operands.top(); operands.pop();
                double operand1 = operands.top(); operands.pop();
                double result;
                string opStr = token.value;

                if (token.value == "+") {
                    result = operand1 + operand2;
                } else if (token.value == "-") {
                    result = operand1 - operand2;
                } else if (token.value == "*") {
                    result = operand1 * operand2;
                } else if (token.value == "/") {
                    if (operand2 == 0) {
                        cout << "Error: Division by zero." << endl;
                        return;
                    }
                    result = operand1 / operand2;
                } else if (token.value == "^") {
                    result = pow(operand1, operand2);
                } else {
                    cout << "Error: Unknown operator '" << token.value << "'" << endl;
                    return;
                }

                operands.push(result);
                cout << "Step " << step++ << ": Apply " << opStr << " to " << operand1 << " and " << operand2 << " = " << result << " (stack: ";
                stack<double> temp = operands;
                vector<double> tempVec;
                while (!temp.empty()) {
                    tempVec.push_back(temp.top());
                    temp.pop();
                }
                reverse(tempVec.begin(), tempVec.end());
                for (size_t i = 0; i < tempVec.size(); ++i) {
                    cout << tempVec[i];
                    if (i < tempVec.size() - 1) cout << ", ";
                }
                cout << ")" << endl;
            }
        }
    }

    if (operands.size() != 1) {
        cout << "Error: Malformed expression." << endl;
        return;
    }

    cout << "Final Result: " << operands.top() << endl;
}

// Main function with menu
int main() {
    int choice;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Evaluate Expression\n";
        cout << "2. Differentiate Expression\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0) {
            break;
        } else if (choice == 1) {
            string expr;
            cout << "Enter expression: ";
            cin.ignore();
            getline(cin, expr);

            vector<Token> tokens = tokenize(expr);
            vector<Token> postfix = infixToPostfix(tokens);

            map<char, double> variables;
            for (const Token& token : tokens) {
                if (token.isVariable && variables.find(token.value[0]) == variables.end()) {
                    double value;
                    cout << "Enter value for " << token.value[0] << ": ";
                    cin >> value;
                    variables[token.value[0]] = value;
                }
            }

            evaluatePostfixWithSteps(postfix, variables);
        } else if (choice == 2) {
            string expr;
            char var;
            cout << "Enter expression: ";
            cin.ignore();
            getline(cin, expr);
            cout << "Enter variable to differentiate with respect to: ";
            cin >> var;

            vector<Token> tokens = tokenize(expr);
            vector<Token> postfix = infixToPostfix(tokens);
            vector<Token> derivative = differentiate(postfix, var);
            derivative = simplify(derivative);

            cout << "Derivative with respect to " << var << ": " << tokensToString(derivative) << endl;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}