
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

// Deterministic Quick Sort: last element as pivot
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
    return i + 1;
}

void deterministicQuickSort(vector<int>& a, int low, int high) {
    if (low < high) {
        int p = partitionDet(a, low, high);
        deterministicQuickSort(a, low, p - 1);
        deterministicQuickSort(a, p + 1, high);
    }
}

// Randomized Quick Sort: random element as pivot
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
    srand(time(nullptr));

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input!" << endl;
        return 0;
    }

    vector<int> original(n);

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> original[i];
    }

    vector<int> a = original;
    vector<int> b = original;

    deterministicQuickSort(a, 0, n - 1);
    randomizedQuickSort(b, 0, n - 1);

    cout << "\nDeterministic Quick Sort:\n";
    for (int x : a)
        cout << x << " ";

    cout << "\n\nRandomized Quick Sort:\n";
    for (int x : b)
        cout << x << " ";

    cout << endl;
    return 0;
}
