// Parse a mathematical expression string containing integers and operators (+, -, *, /)
// Remove all alphabetic characters to get a pure mathematical expression
// Evaluate the expression using BODMAS (order of operations)
// Output the integer result

// 1 <= N <= 100
// Input doesn't contains any whitespaces

// Problem Breakdown:
// Input: "27a+2zx-20"
// After removing alphabets: "27+2-20"
// Evaluation: 27 + 2 - 20 = 9
// Output: 9
// Key Points:

// Remove all alphabetic characters (a-z, A-Z)
// Keep integers and operators (+, -, *, /)
// Follow BODMAS: Multiplication and Division first, then Addition and Subtraction
// Handle single alphabets as value 1 (if isolated)

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string str;
    cin >> str;
    
    string cleanStr = "";
    int n = str.size();
    int i = 0;
    while(i < n){
        if(isalpha(str[i])) {
            string temp = "";
            while(i < n && isalpha(str[i])) {
                temp += str[i];
                i++;  
            }
            if(!temp.empty()) {
                if(!cleanStr.empty()) cleanStr += "*1";
                else cleanStr += "1";
            }
        }
        else {
            cleanStr += str[i];
            i++;
        }
    }
    // cout<< cleanStr << endl;
    
    vector<int> numbers;
    vector<char> operators;
    
    string currentNum = "";
    for (char c : cleanStr) {
        if (isdigit(c)) currentNum += c;
        else {
            if (!currentNum.empty()) {
                numbers.push_back(stoi(currentNum));
                currentNum = "";
            }
            operators.push_back(c);
        }
    }
    if (!currentNum.empty()) numbers.push_back(stoi(currentNum));
    
    // Handle multiplication and division
    for (int i = 0; i < operators.size(); i++) {
        if (operators[i] == '*' || operators[i] == '/') {
            if (operators[i] == '*') numbers[i] = numbers[i] * numbers[i + 1];
            else numbers[i] = numbers[i] / numbers[i + 1];

            numbers.erase(numbers.begin() + i + 1);
            operators.erase(operators.begin() + i);
            i--;
        }
    }
    
    // Handle addition and subtraction
    int result = numbers[0];
    for (int i = 0; i < operators.size(); i++) {
        if (operators[i] == '+') result += numbers[i + 1];
        else if (operators[i] == '-') result -= numbers[i + 1];
    }
    
    cout << result << endl;
    return 0;
}  