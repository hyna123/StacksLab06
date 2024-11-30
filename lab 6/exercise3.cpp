#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

// Function to check if parentheses are balanced
bool isValidParentheses(const string& expr) {
    stack<char> s;  // Stack to store opening brackets

    for (char c : expr) {
        // Push opening brackets onto the stack
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        }
        // Check closing brackets
        else if (c == ')' || c == '}' || c == ']') {
            if (s.empty())  // No matching opening bracket
                return false;

            char top = s.top();  // Check the top of the stack
            if ((c == ')' && top == '(') || 
                (c == '}' && top == '{') || 
                (c == ']' && top == '[')) {
                s.pop();  // Remove matched opening bracket
            } else {
                return false;  // Mismatch found
            }
        }
    }

    return s.empty();  // Valid if stack is empty
}

int main() {
    ifstream inFile("expression.txt");  // Open input file
    if (!inFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string expression;
    getline(inFile, expression);  // Read the expression
    inFile.close();

    // Check if parentheses are valid
    if (isValidParentheses(expression)) {
        cout << "Valid parentheses!" << endl;
    } else {
        cout << "Invalid parentheses!" << endl;
    }

    return 0;
}
