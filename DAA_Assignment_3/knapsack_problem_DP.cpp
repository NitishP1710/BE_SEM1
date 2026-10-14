
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(int capacity, vector<int>& weight,
             vector<int>& value, int n) {

    vector<vector<int>> dp(n + 1,
                           vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            dp[i][w] = dp[i - 1][w];
            if (weight[i - 1] <= w) {
                dp[i][w] = max(
                    dp[i][w],
                    value[i - 1] +
                    dp[i - 1][w - weight[i - 1]]
                );
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input!" << endl;
        return 0;
    }

    vector<int> weight(n), value(n);

    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
        if (weight[i] <= 0) {
            cout << "Invalid weight!" << endl;
            return 0;
        }
    }

    cout << "Enter values of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> value[i];
        if (value[i] < 0) {
            cout << "Invalid value!" << endl;
            return 0;
        }
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    if (capacity < 0) {
        cout << "Invalid capacity!" << endl;
        return 0;
    }

    cout << "Maximum value: "
         << knapsack(capacity, weight, value, n)
         << endl;

    return 0;
}
