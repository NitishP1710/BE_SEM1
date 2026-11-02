#include <bits/stdc++.h>
using namespace std;

// Print array
void printArray(vector<int>& a) {
    for (int x : a)
        cout << x << " ";
    cout << endl;
}

// Deterministic Quick Sort
int partitionDet(vector<int>& a, int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);

    cout << "Pivot: " << pivot << " | Array: ";
    printArray(a);

    return i + 1;
}

void deterministicQuickSort(vector<int>& a, int low, int high) {
    if (low < high) {
        int p = partitionDet(a, low, high);

        deterministicQuickSort(a, low, p - 1);
        deterministicQuickSort(a, p + 1, high);
    }
}

// Randomized Quick Sort
int partitionRandom(vector<int>& a, int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);

    swap(a[randomIndex], a[high]);

    return partitionDet(a, low, high);
}

void randomizedQuickSort(vector<int>& a, int low, int high) {
    if (low < high) {
        int p = partitionRandom(a, low, high);
        randomizedQuickSort(a, low, p - 1);
        randomizedQuickSort(a, p + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> original(n);

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> original[i];

    vector<int> a = original;
    vector<int> b = original;

    cout << "Deterministic Quick Sort"<<endl;
    deterministicQuickSort(a, 0, n - 1);

    cout << "Final Sorted Array: ";
    printArray(a);

    cout << "\n--- Randomized Quick Sort ---\n";
    randomizedQuickSort(b, 0, n - 1);

    cout << "Final Sorted Array: ";
    printArray(b);

    return 0;
}