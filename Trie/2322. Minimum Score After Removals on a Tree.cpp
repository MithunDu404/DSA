// https://leetcode.com/problems/minimum-score-after-removals-on-a-tree/

class Solution {
public:
    void solve(int u,int p,int& timer,vector<int>& nums,unordered_map<int,vector<int>>& adj,vector<int>& subXor,vector<int>& inTime,vector<int>& outTime){
        inTime[u] = timer;
        timer++;
        subXor[u] = nums[u];
        for(auto& v : adj[u]){
            if(v == p) continue;
            solve(v,u,timer,nums,adj,subXor,inTime,outTime);
            subXor[u] ^= subXor[v];
        }

        outTime[u] = timer;
        timer++;
    }

    bool isAncester(int u,int v,vector<int>& inTime,vector<int>& outTime){
        return inTime[u] <= inTime[v] && outTime[u] >= outTime[v];
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();

        unordered_map<int,vector<int>> adj;
        for(auto& e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> subXor(n,0);
        vector<int> inTime(n,0);
        vector<int> outTime(n,0);
        int timer = 0;

        solve(0,-1,timer,nums,adj,subXor,inTime,outTime);

        int ans = INT_MAX;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<n;j++){
                int a,b,c;
                if(isAncester(i,j,inTime,outTime)){
                    a = subXor[j];
                    b = subXor[i]^a;
                    c = subXor[0]^a^b;
                }
                else if(isAncester(j,i,inTime,outTime)){
                    a = subXor[i];
                    b = subXor[j]^a;
                    c = subXor[0]^a^b;
                }
                else{
                    a = subXor[i];
                    b = subXor[j];
                    c = subXor[0]^a^b;
                }

                ans = min(ans,max({a,b,c})-min({a,b,c}));
            }
        }

        return ans;
    }
};