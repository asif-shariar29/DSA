#include <iostream>
using namespace std;
int max(int a, int b) { return (a > b) ? a : b; }
int knapsack(int maxCapacity, int weights[], int values[], int itemCount) {
    int dp[100][100]; 

    for (int i = 0; i <= itemCount; i++) {
        for (int w = 0; w <= maxCapacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[itemCount][maxCapacity];
}
int main() {
    int itemCount, maxCapacity;
    cout << "Enter the number of items: ";
    cin >> itemCount;
    int weights[100], values[100];

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < itemCount; i++) {
        cin >> weights[i];
    }

    cout << "Enter the values of the items: ";
    for (int i = 0; i < itemCount; i++) {
        cin >> values[i];
    }

    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> maxCapacity;

    cout << "Maximum value in Knapsack = " << knapsack(maxCapacity, weights, values, itemCount) << endl;
    return 0;
}
