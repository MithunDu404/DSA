// https://leetcode.com/problems/minimum-time-to-reach-destination-in-directed-graph/

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        int ans = INT_MAX;
        vector<vector<vector<int>>> graph(n);
        for(const auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int start = edge[2];
            int end = edge[3];
            graph[u].push_back({v, start, end});
        }
        vector<int> dist(n,INT_MAX);
        dist[0] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        
        while(!pq.empty()){
            auto [curr,u] = pq.top();
            pq.pop();
            
            if(u == n-1) return curr;
            
            if(curr > dist[u]) continue;
            
            for(const auto& edge : graph[u]){
                int v = edge[0];
                int start = edge[1];
                int end = edge[2];
                
                int departure = max(curr, start);
                if(departure <= end){
                    int arrival = departure + 1;
                    if(arrival < dist[v]){
                        dist[v] = arrival;
                        pq.push({arrival,v});
                    }
                }
            }
        }
        
        return -1;
    }
};