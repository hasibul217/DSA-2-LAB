#include <bits/stdc++.h>     
using namespace std;

// Function to find the maximum sum of a subarray that crosses the midpoint
int maxCrossingSum(const vector<int>& arr, int left, int mid, int right) {
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = mid; i >= left; i--) {
        sum += arr[i];
        if (sum > left_sum) {
            left_sum = sum;
        }
    }

    sum = 0;
    int right_sum = INT_MIN;
    for (int i = mid + 1; i <= right; i++) {
        sum += arr[i];
        if (sum > right_sum) {
            right_sum = sum;
        }
    }

    return left_sum + right_sum;
}

// Function to find the maximum sum subarray using divide and conquer
int findMaxSumSubarray(const vector<int>& arr, int left, int right) {
    if (left == right) {
        return arr[left];
    }

    int mid = (left + right) / 2;

    int left_max = findMaxSumSubarray(arr, left, mid);
    int right_max = findMaxSumSubarray(arr, mid + 1, right);
    int cross_max = maxCrossingSum(arr, left, mid, right);

    return max({left_max, right_max, cross_max});
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int max_sum = findMaxSumSubarray(arr, 0, n - 1);
    cout << "The maximum sum subarray has sum " << max_sum << endl;

    return 0;
}
