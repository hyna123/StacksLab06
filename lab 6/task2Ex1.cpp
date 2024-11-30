#include <iostream>
using namespace std;

// Function to convert decimal to binary
void dectobin(int num) {
    if (num == 0) {
        cout << "Binary: 0" << endl;
        return;
    }

    int binary[32];  // Array to store binary digits
    int i = 0;

    while (num > 0) {
        binary[i] = num % 2;  // Get remainder (0 or 1)
        num /= 2;
        i++;
    }

    // Print binary digits in reverse order
    cout << "Binary: ";
    for (int j = i - 1; j >= 0; j--) {
        cout << binary[j];
    }
    cout << endl;
}

// Function to convert decimal to octal
void dectooct(int num) {
    if (num == 0) {
        cout << "Octal: 0" << endl;
        return;
    }

    int octal[32];  // Array to store octal digits
    int i = 0;

    while (num > 0) {
        octal[i] = num % 8;  // Get remainder (0 to 7)
        num /= 8;
        i++;
    }

    // Print octal digits in reverse order
    cout << "Octal: ";
    for (int j = i - 1; j >= 0; j--) {
        cout << octal[j];
    }
    cout << endl;
}

int main() {
    int number;
    cout << "Enter a decimal number: ";
    cin >> number;

    // Call the conversion functions
    dectobin(number);
    dectooct(number);

    return 0;
}
