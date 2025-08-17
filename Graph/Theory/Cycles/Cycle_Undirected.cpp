#include<bits/stdc++.h>
using namespace std;

// DFS
bool solve(int i,int p,int n,vector<int>& visited,unordered_map<int,vector<int>>& adj){
    visited[i] = 1;
    for(int v : adj[i]){
        if(v == p) continue;
        else if(visited[v]) return true;
        else if(solve(v,i,n,visited,adj)) return true;
    }

    return false;
}

bool isCyclic(vector<vector<int>>& g, int n) {
    unordered_map<int,vector<int>> adj;
    for(auto& p : g){
        int u = p[0];
        int v = p[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> visited(n,0);
    for(int i=0;i<n;i++){
        if(!visited[i] && solve(i,-1,n,visited,adj)) return true;
    }
    return false;
}



// BFS
bool solve_bfs(int i,vector<int>& visited,unordered_map<int,vector<int>>& adj){
    visited[i] = 1;
    queue<pair<int,int>> que;
    que.push({i,-1});
    while(!que.empty()){
        auto p = que.front();
        que.pop();
        int u = p.first;
        int parent = p.second;

        for(int& v : adj[u]){
            if(v == parent) continue;
            if(visited[v]) return true;
            
            visited[v] = 1;
            que.push({v,u});
        }

        return false;
    }
}

bool isCyclic(vector<vector<int>>& g, int n) {
    unordered_map<int,vector<int>> adj;
    for(auto& p : g){
        int u = p[0];
        int v = p[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> visited(n,0);
    for(int i=0;i<n;i++){
        if(!visited[i] && solve_bfs(i,visited,adj)) return true;
    }
    return false;
}