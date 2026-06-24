#include <iostream>
#include <cstring>
using namespace std;

bool isNumeric(char input[]) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (!(input[i] >= '0' && input[i] <= '9'))
            return false;
    }
    return true;
}

void checkNumeric() {
    char input[100];
    cout << "Enter input: ";
    cin >> input;
    if (isNumeric(input))
        cout << "Numeric Constant" << endl;
    else
        cout << "Not Numeric" << endl;
}

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' ||
            ch == '/' || ch == '%' || ch == '=');
}

void checkOperator() {
    char input[100];
    cout << "Enter expression: ";
    cin >> input;

    int count = 0;
    bool found = false;

    for (int i = 0; input[i] != '\0'; i++) {
        if (isOperator(input[i])) {
            count++;
            cout << "Operator" << count << ": " << input[i] << endl;
            found = true;
        }
    }
    if (!found)
        cout << "No Operator Found" << endl;
}

void checkComment() {
    char input[5000];
    cout << "Enter input: ";
    cin.ignore();
    cin.getline(input, 5000);

    int len = strlen(input);
    bool found = false;

    for (int i = 0; i < len - 1; i++) {

        if (input[i] == '/' && input[i + 1] == '/') {
            cout << "Single Line Comment found at position " << i << endl;

            found = true;
            break;
        }

        if (input[i] == '/' && input[i + 1] == '*') {
            for (int j = i + 2; j < len - 1; j++) {
                if (input[j] == '*' && input[j + 1] == '/') {
                    cout << "Multi Line Comment found at position " << i << endl;

                    found = true;
                    break;
                }
            }
            if (found) break;
        }
    }

    if (!found)
        cout << "No Comment Found" << endl;
}

bool isIdentifier(char input[]) {
    if (!((input[0] >= 'A' && input[0] <= 'Z') ||
          (input[0] >= 'a' && input[0] <= 'z') ||
          (input[0] == '_')))
        return false;

    for (int i = 1; input[i] != '\0'; i++) {
        if (!((input[i] >= 'A' && input[i] <= 'Z') ||
              (input[i] >= 'a' && input[i] <= 'z') ||
              (input[i] >= '0' && input[i] <= '9') ||
              (input[i] == '_')))
            return false;
    }
    return true;
}

void checkIdentifier() {
    char input[1000];
    cout << "Enter input: ";
    cin >> input;
    if (isIdentifier(input))
        cout << "Valid Identifier" << endl;
    else
        cout << "Invalid Identifier" << endl;
}

void arrayAverage() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    double arr[n];
    double sum = 0;

    for (int i = 0; i < n; i++) {
        cout << "Enter the " << i + 1 << " No element of the array: " << endl;
        cin >> arr[i];
        sum += arr[i];
    }

    double average = sum / n;
    cout << "Sum     = " << sum << endl;
    cout << "Average = " << average << endl;
}

void arrayMinMax() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    double arr[n];
    cout << "Enter " << n << " elements with space : " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    double min = arr[0];
    double max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < min){
            min = arr[i];}
        if (arr[i] > max){
         max = arr[i];}
    }

    cout << "Minimum = " << min << endl;
    cout << "Maximum = " << max << endl;
}

void fullName() {
    char firstName[50], lastName[50], fullName[100];

    cout << "Enter First Name: ";
    cin >> firstName;
    cout << "Enter Last Name: ";
    cin >> lastName;

    strcpy(fullName, firstName);
    strcat(fullName, " ");
    strcat(fullName, lastName);

    cout << "Full Name = " << fullName << endl;
}

int main() {
    int choice;


    cout << "1. Numeric Constant Check"<< endl;
    cout << "2. Operator Check"<< endl;
    cout << "3. Comment Line Check"<< endl;
    cout << "4. Identifier Check"<< endl;
    cout << "5. Array Average"<< endl;
    cout << "6. Array Min & Max"<< endl;
    cout << "7. Full Name Concatenation"<< endl;
    cout << "Enter your choice (1-7):";
    cin  >> choice;


    switch (choice) {
        case 1:
             checkNumeric();
          break;
        case 2:

             checkOperator();
         break;
        case 3:
            checkComment();
         break;
        case 4:
            checkIdentifier();
         break;
        case 5:
             arrayAverage();
         break;
        case 6:
             arrayMinMax();
         break;
        case 7:
             fullName();
        break;
        default:
             cout << "Invalid" << endl;
    }

    return 0;
}
