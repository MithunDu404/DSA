// https://leetcode.com/problems/minimum-increments-to-equalize-leaf-paths/

class Solution {
    public:
        long long solve(int node,unordered_map<int, vector<int>>& adj,unordered_map<int, int>& parent,vector<int>& cost,int& ans){
            vector<long long> path_sums;
            for(auto v : adj[node]){
                if(v == parent[node]) continue;
                parent[v] = node;
                path_sums.push_back(solve(v,adj,parent,cost,ans));
            }
    
            int n = path_sums.size();
            if(n == 0) return cost[node];
            long long maxi = *max_element(path_sums.begin(),path_sums.end());
            for(int i=0;i<n;i++) ans += (maxi - path_sums[i] > 0)? 1 : 0;
    
            return cost[node] + maxi;
        }
        
        int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
            unordered_map<int, vector<int>> adj;
            for (const auto& edge : edges) {
                int u = edge[0], v = edge[1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
    
            unordered_map<int, int> parent;
            parent[0] = -1; 
            int ans = 0;
            solve(0,adj,parent,cost,ans);
            return ans;
        }
    };