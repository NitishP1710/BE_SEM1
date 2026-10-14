
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int value;
    double ratio;
};
bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}
double fractionalKnapsack(int capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;

    for (int i = 0; i < items.size(); i++) {
        if (capacity == 0)
            break;

        if (items[i].weight <= capacity) {
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            double fraction = (double)capacity / items[i].weight;
            totalValue += items[i].value * fraction;
            capacity = 0;
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input!" << endl;
        return 0;
    }

    vector<Item> items(n);

    cout << "Enter weight and value of each item:\n";

    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].value;

        if (items[i].weight <= 0 || items[i].value < 0) {
            cout << "Invalid input!" << endl;
            return 0;
        }

        items[i].ratio =
            (double)items[i].value / items[i].weight;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    if (capacity < 0) {
        cout << "Invalid capacity!" << endl;
        return 0;
    }

    cout << "Maximum value: "
         << fractionalKnapsack(capacity, items) << endl;

    return 0;
}
