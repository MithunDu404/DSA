// https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/

class Solution {
public:
    int enf = INT_MAX;
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();

        vector<vector<int>> maxRange(n,vector<int>(n,enf));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(i == j) maxRange[i][j] = jobDifficulty[i];
                else maxRange[i][j] = max(maxRange[i][j-1],jobDifficulty[j]);
            }
        }

        vector<vector<int>> dp(d,vector<int>(n,enf));
        dp[0][0] = jobDifficulty[0];

        for(int i=0;i<d;i++){
            for(int j=i;j<n;j++){
                if(i == 0){
                    dp[0][j] = maxRange[0][j];
                    continue;
                }
                for(int k=0;k<j;k++){
                    if(dp[i-1][k] < enf) 
                        dp[i][j] = min(dp[i][j],dp[i-1][k] + maxRange[k+1][j]);
                }
            }
        }

        return (dp[d-1][n-1] == enf)? -1 : dp[d-1][n-1];
    }
};