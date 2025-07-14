// Super Tunnels (Graph Problem)
// Context: You're bidding on a railway tunnel maintenance project in hilly terrain. Some tunnels are "super tunnels" - if they collapse, other connected tunnels become unreachable.
// Problem: Find which tunnels are super tunnels and calculate the total maintenance cost.
// Input Format:

// First line: n (number of tunnels, 0 to n-1)
// Next n lines: connectivity matrix (1 = connected, 0 = not connected)
// Last line: n space-separated maintenance costs for tunnels 0 to n-1

// Output: Total maintenance cost of all super tunnels

// 1 < n < 100
// 0 < costs < 10^6

// 9
// 0 1 1 1 0 0 1 0 0
// 1 0 1 0 0 0 0 0 0
// 1 1 0 0 0 0 0 0 0
// 1 0 0 0 1 1 1 0 0
// 0 0 0 1 0 1 0 0 0
// 0 0 0 1 1 0 0 0 0
// 1 0 0 1 0 0 0 1 1
// 0 0 0 0 0 0 1 0 1
// 0 0 0 0 0 0 1 1 0
// 3 7 10 5 11 15 18 9 2

// Example Output: 26

#include <bits/stdc++.h>
using namespace std;

class DSU{
private:
    vector<int> parent;
    vector<int> rank;
    int count;

public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n, 0);
        count = n;
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }
    int find(int x){
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int u,int v){
        int parent_u = find(u);
        int parent_v = find(v);
        if(parent_u != parent_v){
            if(rank[parent_u] > rank[parent_v]){
                parent[parent_v] = parent_u;
            }
            else if(rank[parent_u] < rank[parent_v]){
                parent[parent_u] = parent_v;
            }
            else{
                parent[parent_u] = parent_v;
                rank[parent_v]++;
            }
            count--;
        } 
    }

    int getComponents(){
        return count;
    }
};

int main(){
    int n;cin>>n;
    unordered_map<int,vector<int>> adj;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int t;cin>>t;
            if(t == 1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<int> costs(n); for(int i=0;i<n;i++) cin>>costs[i];

    int total_cost = 0;
    for(int i=0;i<n;i++){
        DSU dsu(n);
        for(int j=0;j<n;j++){
            if(j == i) continue;
            for(auto& v : adj[j]){
                if(v == i) continue;
                dsu.unite(j,v);
            }
        }
        if(dsu.getComponents() > 2){
            total_cost += costs[i];
        }
    }

    cout<<total_cost<<endl;
}
