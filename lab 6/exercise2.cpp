#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

int main() {
    ifstream inFile("input.txt");   // Open input file
    ofstream outFile("output.txt"); // Open output file

    if (!inFile || !outFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string str;
    getline(inFile, str); // Read string from file

    stack<char> charStack;
    for (char c : str) {
        charStack.push(c); // Push each character onto the stack
    }

    while (!charStack.empty()) {
        outFile << charStack.top(); // Write characters in reverse order
        charStack.pop();
    }

    cout << "String reversed and saved to output.txt" << endl;
    return 0;
}
