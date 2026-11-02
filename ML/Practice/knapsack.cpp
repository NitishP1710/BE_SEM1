
#include <bits/stdc++.h>
using namespace std;

int knapsack(int capacity, const vector<int>& weights, const vector<int>& values, int n) {
    
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0)); 

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int n = 4, W = 7;

    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {1, 4, 5, 7};

    cout << "Maximum Profit: "
         << knapsack(W, wt, val, n);

    return 0;
}
