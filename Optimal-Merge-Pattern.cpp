#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int optimalmergepattern (vector<int>& files){
    
    // initiated priority_queue 
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    
    // this will automatically add files in ascending order
    for( int file : files){
        minHeap.push(file);
    }
    
    // initiated totalcost=0
    int totalcost=0;
    
    //at last size of minHeap will be zero when final output will be presented
    while(minHeap.size()>1){
        
        //selected 1st and 2nd element of minHeap
        int first = minHeap.top();
        minHeap.pop();
        int second = minHeap.top();
        minHeap.pop();
        
        //initiated mergecost as the sum of 1st and 2nd element of minHeap
        int mergecost= first + second;
        
        //totalcost calculated by using mergecost
        totalcost = totalcost + mergecost;
        
        //laterly added mergecost back to minHeap
        minHeap.push(mergecost);
    }
    
    //returned totalcost
    return totalcost;
}

int main(){
    vector<int> files = {2,5,10, 11, 6, 10};
    
    int cost = optimalmergepattern(files);
    cout<< "Minimum cost to merge files is: "<< cost << endl;
    
    return 0;
}
