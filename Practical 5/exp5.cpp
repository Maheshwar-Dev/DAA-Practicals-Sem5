#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    srand(time(0));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100000;

    auto start = chrono::high_resolution_clock::now();
    quickSort(arr, 0, n - 1);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> duration = end - start;
    cout << "Time taken: " << duration.count() << " ms\n";
    return 0;
}
