#include <iostream>
using namespace std;

// Function to check if a number is a palindrome
bool isPalindrome(int x) {
    // Case 1: Negative numbers are never palindromes
    if (x < 0) {
        return false;
    }

    // Case 2: If number ends with 0 but is not 0, it can't be a palindrome
    // Example: 10 → reverse is 01 (not equal)
    if (x % 10 == 0 && x != 0) {
        return false;
    }

    // Reverse only half of the number to avoid overflow
    int reversedHalf = 0;
    while (x > reversedHalf) {
        int lastDigit = x % 10;            // Extract last digit
        reversedHalf = reversedHalf * 10 + lastDigit; 
        x /= 10;                           // Remove last digit
    }

    // Check if original half equals reversed half
    // Case A: Even digits → x should equal reversedHalf
    // Case B: Odd digits  → x should equal reversedHalf/10
    return (x == reversedHalf || x == reversedHalf / 10);
}

int main() {
    int num;

    // Input from user
    cout << "Enter an integer: ";
    cin >> num;

    // Check palindrome and print result
    if (isPalindrome(num)) {
        cout << num << " is a palindrome." << endl;
    } else {
        cout << num << " is not a palindrome." << endl;
    }

    return 0;
}
