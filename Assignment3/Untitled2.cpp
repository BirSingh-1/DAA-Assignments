#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n = 4;  // Number of items
    int w[] = {2,3,4,5};  // Weights of items
    int p[] = {1,2,5,6};  // Profits of items
    int cap = 8;  // Knapsack capacity

    int k[n + 1][cap + 1];

    // Step 1: Build DP table
    for (int i = 0; i <= n; i++) {
        for (int currentWeight = 0; currentWeight <= cap; currentWeight++) {
            if (i == 0 || currentWeight == 0) {
                k[i][currentWeight] = 0;
            } else if (w[i - 1] <= currentWeight) {
                k[i][currentWeight] = max(k[i - 1][currentWeight], 
                                          p[i - 1] + k[i - 1][currentWeight - w[i - 1]]);
            } else {
                k[i][currentWeight] = k[i - 1][currentWeight];
            }
        }
    }

    // Step 2: Find selected items
    int i = n, j = cap;
    int selected[n] = {0};

    while (i > 0 && j > 0) {
        if (k[i][j] != k[i - 1][j]) {  // Item was included
            selected[i - 1] = 1;
            j -= w[i - 1];  // Reduce remaining weight
        }
        i--;
    }

    // Step 3: Print selected items and total profit
    cout << "Selected items: ";
    int totalProfit = 0;
    for (int i = 0; i < n; i++) {
        if (selected[i]) {
            cout << "Item " << i + 1 << " ";
            totalProfit += p[i];
        }
    }
    cout << endl << "Maximum Profit: " << totalProfit << endl;

    return 0;
}
