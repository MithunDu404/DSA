#include<bits/stdc++.h>
using namespace std;

// Kahn's Algorithm

//DFS
class Solution {
public:
    //Function to return list containing vertices in Topological order.
    vector<int> topoSort(int N, vector<int> adj[])  {
        queue<int> que;
        vector<int> indegree(N, 0);
        int count = 0; // To check for cycle

        for(int u = 0; u<N; u++) {
            for(int &v : adj[u]) {
                indegree[v]++;
            }
        }

        //Fill que, indegree with 0
        for(int i = 0; i<N; i++) {
            if(indegree[i] == 0) {
                que.push(i);
                count++;
            }
        }

        //Simple BFS
        vector<int> result;
        while(!que.empty()) {
            int u = que.front();
            result.push_back(u);
            que.pop();

            for(int &v : adj[u]) {
                indegree[v]--;

                if(indegree[v] == 0) {
                    que.push(v);
                    count++;
                }
            }
        }
        
        if(count != N) return {}; // Can't able to visit all nodes Or cycle exist
        
        return result;
    }
};

//BFS
class Solution {
public:
    bool hasCycle;
    
    void DFS(vector<int> adj[], int u, vector<bool>& visited, stack<int>& st,vector<bool>& inRecursion) {
        visited[u] = true;
        inRecursion[u] = true;

        //pehle mere ('u' ke node ke ) bachho ko daalo
        for(int &v : adj[u]) {
            if(!visited[v])
                DFS(adj, v, visited, st, inRecursion);
            else if(inRecursion[v]){
                hasCycle = true;
                return;
            }    
        }

        //ab mujhe daalo stack me
        st.push(u);
    }

    //Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<bool> inRecursion(V,false);
        stack<int> st;

        for(int i = 0; i<V; i++) {
            if(!visited[i])
                DFS(adj, i, visited, st,inRecursion);
        }
        
        if(hasCycle) return {}; // graph has cycle so can't have topological sort
        
        vector<int> result;
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        return result;
    }
};

