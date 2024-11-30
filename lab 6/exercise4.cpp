#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

// Function to evaluate a postfix expression
int evaluatePostfix(const string& expr) {
    stack<int> s;  // Stack to store numbers

    for (char c : expr) {
        if (c >= '0' && c <= '9') {
            // If the character is a number, push it onto the stack
            s.push(c - '0');  // Convert char to integer
        } else {
            // If it's an operator, pop two numbers and apply the operator
            int operand2 = s.top(); s.pop();
            int operand1 = s.top(); s.pop();

            if (c == '+') s.push(operand1 + operand2);
            else if (c == '-') s.push(operand1 - operand2);
            else if (c == '*') s.push(operand1 * operand2);
            else if (c == '/') s.push(operand1 / operand2);
        }
    }

    return s.top();  // The result is the only number left in the stack
}

int main() {
    ifstream inFile("postfix.txt");  // Open the file containing the postfix expression
    if (!inFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string expression;
    getline(inFile, expression);  // Read the postfix expression from the file
    inFile.close();

    // Evaluate the postfix expression
    int result = evaluatePostfix(expression);

    // Output the result
    cout << "The result of the postfix expression is: " << result << endl;

    return 0;
}
