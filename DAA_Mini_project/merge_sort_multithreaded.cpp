
#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>
#include <random>
using namespace std;
using namespace chrono;

const int THRESHOLD = 2048;

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    temp.reserve(right - left + 1);

    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while (i <= mid)
        temp.push_back(arr[i++]);

    while (j <= right)
        temp.push_back(arr[j++]);

    for (int k = 0; k < (int)temp.size(); k++)
        arr[left + k] = temp[k];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

void parallelMergeSort(vector<int>& arr, int left, int right,
                       int depth) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    // Use sequential sorting for small subarrays
    if (right - left + 1 <= THRESHOLD || depth <= 0) {
        mergeSort(arr, left, right);
        return;
    }

    // Sort left half in a separate thread
    thread leftThread([&arr, left, mid, depth]() {
        parallelMergeSort(arr, left, mid, depth - 1);
    });

    // Sort right half in the current thread
    parallelMergeSort(arr, mid + 1, right, depth - 1);

    // Wait for left half to finish
    leftThread.join();

    // Merge the sorted halves
    merge(arr, left, mid, right);
}

int main() {
    int n, choice;

    cout << "Enter number of elements: ";
    cin >> n;

    if (!cin || n <= 0) {
        cout << "Invalid input!" << endl;
        return 0;
    }

    cout << "\n1. Sorted input";
    cout << "\n2. Reverse sorted input";
    cout << "\n3. Random input";
    cout << "\nEnter choice: ";
    cin >> choice;

    if (!cin || choice < 1 || choice > 3) {
        cout << "Invalid choice!" << endl;
        return 0;
    }

    vector<int> arr(n);

    if (choice == 1) {
        for (int i = 0; i < n; i++)
            arr[i] = i + 1;
    } else if (choice == 2) {
        for (int i = 0; i < n; i++)
            arr[i] = n - i;
    } else {
        mt19937 rng(random_device{}());
        uniform_int_distribution<int> dist(1, 1000000);

        for (int& x : arr)
            x = dist(rng);
    }

    unsigned int cores = thread::hardware_concurrency();
    if (cores == 0)
        cores = 2;

    int depth = 0;
    while ((1u << depth) < cores && depth < 20)
        depth++;

    auto start = steady_clock::now();

    parallelMergeSort(arr, 0, n - 1, depth);

    auto end = steady_clock::now();

    double elapsed =
        duration<double, milli>(end - start).count();

    cout << "\nSorted array:\n";
    if (n <= 100) {
        for (int x : arr)
            cout << x << " ";
        cout << endl;
    } else {
        cout << "Array too large to display (" << n
             << " elements)." << endl;
    }

    cout << "Array sorted correctly: "
         << (is_sorted(arr.begin(), arr.end()) ? "Yes" : "No")
         << endl;

    cout << "Hardware concurrency reported: " << cores << endl;
    cout << "Execution time: " << elapsed << " ms" << endl;

    return 0;
}
