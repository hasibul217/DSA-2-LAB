#include <iostream>
#include <vector>
using namespace std;

// Function to merge two halves and count good pairs
int mergeAndCount(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int i = left; 
    int j = mid + 1; 
    int k = left; 
    int count = 0; // Count of good pairs

    while ((i <= mid) && (j <= right)) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
           
            count += (mid - i + 1);
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return count;
}

// Function to use merge sort and count inversions
int mergeSortAndCount(vector<int>& arr, vector<int>& temp, int left, int right) {
    int mid, count = 0;
    if (right > left) {
        mid = (right + left) / 2;

        count += mergeSortAndCount(arr, temp, left, mid);
        count += mergeSortAndCount(arr, temp, mid + 1, right);

        count += mergeAndCount(arr, temp, left, mid, right);
    }
    return count;
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

    vector<int> temp(n);
    int goodPairsCount = mergeSortAndCount(arr, temp, 0, n - 1);

    cout << "The number of good pairs is: " << goodPairsCount << endl;

    return 0;
}
