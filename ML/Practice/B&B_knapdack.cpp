
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int weight, profit;
    double ratio;
};

struct Node {
    int level;
    int profit;
    int weight;
    double bound;
};

bool cmp(Item a, Item b) {
    return a.ratio > b.ratio;
}

// Calculate upper bound using fractional knapsack
double calculateBound(Node u, int n, int W,
                      vector<Item>& items) {

    if (u.weight >= W)
        return 0;

    double profitBound = u.profit;
    int totalWeight = u.weight;

    int j = u.level + 1;

    // Add complete items
    while (j < n &&
           totalWeight + items[j].weight <= W) {

        totalWeight += items[j].weight;
        profitBound += items[j].profit;
        j++;
    }

    // Add fractional part of next item
    if (j < n) {
        profitBound +=
            (W - totalWeight) * items[j].ratio;
    }

    return profitBound;
}

int knapsack(int W, vector<Item>& items, int n) {

    sort(items.begin(), items.end(), cmp);

    queue<Node> q;

    Node root;
    root.level = -1;
    root.profit = 0;
    root.weight = 0;

    root.bound = calculateBound(root, n, W, items);

    q.push(root);

    int maxProfit = 0;

    while (!q.empty()) {

        Node u = q.front();
        q.pop();

        if (u.bound <= maxProfit)
            continue;

        int next = u.level + 1;

        if (next >= n)
            continue;

        // Branch 1: Include current item
        Node v;

        v.level = next;
        v.weight = u.weight + items[next].weight;
        v.profit = u.profit + items[next].profit;

        if (v.weight <= W) {

            maxProfit = max(maxProfit, v.profit);

            v.bound = calculateBound(v, n, W, items);

            if (v.bound > maxProfit)
                q.push(v);
        }

        // Branch 2: Exclude current item
        Node w;

        w.level = next;
        w.weight = u.weight;
        w.profit = u.profit;

        w.bound = calculateBound(w, n, W, items);

        if (w.bound > maxProfit)
            q.push(w);
    }

    return maxProfit;
}

int main() {

    int n = 4;
    int W = 7;

    vector<Item> items = {
        {1, 1, 0},
        {3, 4, 0},
        {4, 5, 0},
        {5, 7, 0}
    };

    for (auto &item : items)
        item.ratio = (double)item.profit / item.weight;

    cout << "Maximum Profit: "
         << knapsack(W, items, n);

    return 0;
}
