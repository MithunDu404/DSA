/* 
1. Bipartite graph : each node has different color than it's adjacent nodes
Only two color can be used

2. A graph is bipartite if the nodes can be partitioned into two independent sets A and B 
such that every edge in the graph connects a node in set A and a node in set B.
*/

#include<bits/stdc++.h>
using namespace std;

// Using DFS
class Solution {
public:
    bool DFS(int u,int curr_color,vector<int>& color,vector<vector<int>>& graph){
        color[u] = curr_color;
        
        for(auto& v : graph[u]){
            if(color[v] == curr_color) return false;
            else if(color[v] == -1){
                if(DFS(v,curr_color^1,color,graph) == false)
                    return false;
            }
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                if(DFS(i,0,color,graph) == false) return false;
            }
        }
        
        return true;
    }
};

// Using BFS
class Solution {
public:
    bool BFS(int curr,int curr_color,vector<int>& color,vector<vector<int>>& graph){
        color[curr] = curr_color;
        queue<int> que;
        que.push(curr);
        
        while(!que.empty()){
            int u = que.front();
            que.pop();
            
            for(auto& v : graph[u]){
                if(color[v] == color[u]) return false;
                else if(color[v] == -1){
                    que.push(v);
                    color[v] = color[u]^1;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        
        for(int i=0;i<n;i++){
            if(color[i] == -1 && BFS(i,0,color,graph) == false)
                return false;
        }
        return true;
    }
};