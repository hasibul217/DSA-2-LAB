#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the common prefix between two strings
string commonPrefix(const string& str1, const string& str2) {
    int minLength = min(str1.length(), str2.length());
    for (int i = 0; i < minLength; i++) {
        if (str1[i] != str2[i]) {
            return str1.substr(0, i);
        }
    }
    return str1.substr(0, minLength);
}

// Function to find the longest common prefix using divide and conquer
string longestCommonPrefix(vector<string>& strs, int left, int right) {
    if (left == right) {
        return strs[left];
    }

    int mid = (left + right) / 2;
    string leftPrefix = longestCommonPrefix(strs, left, mid);
    string rightPrefix = longestCommonPrefix(strs, mid + 1, right);

    return commonPrefix(leftPrefix, rightPrefix);
}

int main() {
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;
    cin.ignore(); // Ignore the newline character after the integer input
    
    vector<string> strs(n);
    cout << "Enter the strings:" << endl;
    for (int i = 0; i < n; ++i) {
        getline(cin, strs[i]);
    }

    if (n == 0) {
        cout << "No common prefix" << endl;
    } else {
        string lcp = longestCommonPrefix(strs, 0, n - 1);
        if (lcp.empty()) {
            cout << "No common prefix" << endl;
        } else {
            cout << lcp << endl;
        }
    }

    return 0;
}
