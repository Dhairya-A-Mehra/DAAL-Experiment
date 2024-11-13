#include <iostream>
#define INF 999999
using namespace std;
#define V 10  // number of vertices are 10

// Adjacency matrix creation which will be used for printing
int S[V][V], n=3;

int G[V][V] = {
    {0, 1, 2},
    {1, 0, 3},
    {2, 3, 0}
};

int prims() {
    int cost[V][V], i, j, ne;
    int min_dist[V], temp_min_dist, visited[V];
    int from_parent[V], u_present, v_to_be_added;
    int min_cost_to_return = 0;

    // Creation of Cost function and spanning tree
    for(i =0; i<n; i++) {
        for (j =0; j<n ; j++){
            if(G[i][j]==0){
                cost[i][j]= INF;
            }
            else{
                cost[i][j]= G[i][j];
            }
            S[i][j]=0;
            
        }
    }
    
    // initialize visited[], min_dist[], from_parent[]
    // source node = 0
    visited[0]=1;
    min_dist[0]=0;
    for(i =1; i<n; i++){
        min_dist[i]= cost[0][i];
        from_parent[i]=0;
        visited[i]=0;
    }
    ne = n -1;
    while(ne>0){
        
        // finding min_dist 
        temp_min_dist = INF;
        for(i=1; i<n; i++){
            if(visited[i]==0 && min_dist[i]< temp_min_dist){
                temp_min_dist= min_dist[i];
                v_to_be_added = i;
            }
        }
        u_present = from_parent[v_to_be_added];
        
        // insert edge in spanning tree & edge decrement & set visited[v]
        ne --;
        S[u_present][v_to_be_added] = min_dist[v_to_be_added];
        S[v_to_be_added][u_present] = min_dist[v_to_be_added];
        visited[v_to_be_added]=1;
        
        // update min_dist[]
        for(i=1; i<n; i++){
            if(visited[i]==0 && cost[i][v_to_be_added]< min_dist[i]){
                min_dist[i]= cost[i][v_to_be_added];
                from_parent[i]= v_to_be_added;
            }
        }
        min_cost_to_return= min_cost_to_return + cost[u_present][v_to_be_added];
    }
    return min_cost_to_return;
}

int main(){
    int cost= prims();
    int i,j;
    cout << "Spanning tree" << endl;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            cout << S[i][j] << " " << endl;
        }
    }
    
    cout<< "Minimum Cost of Spanning Tree = "<<cost<<endl;
    
    return 0;
    
}