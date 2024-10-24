#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Function to find the optimal merge pattern
int optimalMergePattern(vector<int>& files) {
    // Create a priority queue (min-heap)
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Insert all file sizes into the min-heap
    for (int file : files)
        minHeap.push(file);

    int totalCost = 0;

    // Repeat the process until there is only one file left
    while (minHeap.size() > 1) {
        // Extract the two smallest files
        int first = minHeap.top();
        minHeap.pop();
        int second = minHeap.top();
        minHeap.pop();

        // Merge them and calculate the cost
        int mergeCost = first + second;
        totalCost += mergeCost;

        // Push the merged file back into the heap
        minHeap.push(mergeCost);
    }

    return totalCost;
}

int main() {
    vector<int> files = {4, 3, 2, 6};  // Example file sizes

    int minCost = optimalMergePattern(files);
    cout << "Minimum cost to merge files: " << minCost << endl;

    return 0;
}
