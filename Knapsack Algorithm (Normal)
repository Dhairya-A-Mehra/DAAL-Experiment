#include <iostream>
using namespace std;

int knapsack(int W, int wt[], int val[], int n) {
    // Base Case
    if (n == 0 || W == 0)
        return 0;

    // If weight of the nth item is more than capacity W, it cannot be included
    if (wt[n - 1] > W)
        return knapsack(W, wt, val, n - 1);

    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    else
        return max(val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1), knapsack(W, wt, val, n - 1));
}

int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << "Maximum value in Knapsack = " << knapsack(W, wt, val, n) << endl;
    return 0;
}
