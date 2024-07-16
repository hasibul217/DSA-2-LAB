#include <iostream>
#include <vector>
using namespace std;

// Function to perform partition
int partition(vector<int>& arr, int p, int r) {
    int x = arr[r]; // Pivot
    int i = p - 1;

    for (int j = p; j < r; j++) {
        if (arr[j] >= x) { // Note: >= for descending order
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

// Function to perform quicksort
void quicksort(vector<int>& arr, int p, int r) {
    if (p < r) {
        int q = partition(arr, p, r);
        quicksort(arr, p, q - 1);
        quicksort(arr, q + 1, r);
    }
}

int main() {
    int N;
    cout << "Enter the number of elements: ";
    cin >> N;
    vector<int> arr(N);

    cout << "Enter the elements: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    quicksort(arr, 0, N - 1);

    cout << "Sorted array in descending order: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}