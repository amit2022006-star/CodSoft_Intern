#include <iostream>
using namespace std;

int main() {
    double num1, num2, result;
    char op;

    cout << "Simple Calculator" << endl;
    cout << "-----------------" << endl;

    // Taking input from the user
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    cout << "Enter an operator (+, -, *, /): ";
    cin >> op;

    // Performing operation based on user choice
    switch(op) {
        case '+':
            result = num1 + num2;
            cout << "Result: " << result << endl;
            break;

        case '-':
            result = num1 - num2;
            cout << "Result: " << result << endl;
            break;

        case '*':
            result = num1 * num2;
            cout << "Result: " << result << endl;
            break;

        case '/':
            if (num2 != 0)
                result = num1 / num2;
            else {
                cout << "Error! Division by zero is not allowed." << endl;
                return 0;
            }
            cout << "Result: " << result << endl;
            break;

        default:
            cout << "Invalid operator! Please use +, -, *, or /." << endl;
    }

    return 0;
}
