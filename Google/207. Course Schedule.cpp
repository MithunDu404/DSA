// https://leetcode.com/problems/course-schedule/

class Solution {
public:
    int n;

    bool solve(int u,vector<bool>& visited,vector<bool>& inRecurs,unordered_map<int,vector<int>>& adj){
        visited[u] = true;
        inRecurs[u] = true;
        
        for(auto& v : adj[u]){
            if(!visited[v]){
                if(solve(v,visited,inRecurs,adj)) return true;
            }
            else if(inRecurs[v]) return true;   
        }

        inRecurs[u] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;

        unordered_map<int,vector<int>> adj;
        for(auto& v : prerequisites)
            adj[v[1]].push_back(v[0]);

        vector<bool> visited(n,false);
        vector<bool> inRecurs(n,false);

        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            if(solve(i,visited,inRecurs,adj)) return false;
        }

        return true;
    }
};