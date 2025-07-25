// https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();

        map<int,int> mp;
        for(int i=0;i<n;i++) mp[arr[i]] = i;

        set<int> st(arr.begin(),arr.end());

        vector<vector<int>> dp(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                dp[i][j] = 2;
            }
        }

        int ans = 0;
        for(int i=2;i<n;i++){
            int v = arr[i];

            for(int j=i-1;j>=1;j--){
                int x = arr[j];
                int y = v - x;
                if(x <= y) break;

                int k = mp[y];
                
                if(st.find(v-x) != st.end()){
                    dp[j][i] = max(dp[k][j]+1,dp[j][i]);
                    ans = max(ans,dp[j][i]);
                }
            }
        }

        return (ans >= 3)? ans : 0;
    }
};