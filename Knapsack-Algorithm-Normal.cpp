#include <iostream>
using namespace std;

int knapsack(int W, int wt[], int val[], int n){
    
    // check if knapsack is empty then val[] == 0
    if(n == 0 || W == 0){
        return 0;
    }
    
    // check if n-1th weight is bigger than total weight of knapsack
    if(wt[n-1]>W){
        return knapsack(W,wt,val,n-1);
    }
    
    // maximizing the final output by comparing to 2 different output
    return max(val[n-1]+knapsack(W-wt[n-1],wt,val,n-1),knapsack(W,wt,val,n-1));
}

int main(){
    int val[]={60,100,120};
    int wt []={10,20,30};
    int W= 50;
    int n=sizeof(val)/sizeof(val[0]);
    
    cout<< "Maximum value of knapsack can be: "<<knapsack(W,wt,val,n)<< endl;
    
    return 0;
}