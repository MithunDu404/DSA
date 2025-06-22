// https://leetcode.com/problems/inverse-coin-change/

class Solution {
    public:
        int countWays(int num, vector<int>& coins) {
            vector<int> dp(num + 1, 0);
            dp[0] = 1;
            
            for (int s : coins) {
                for (int i = s; i <= num; ++i) {
                    dp[i] += dp[i - s];
                }
            }
            
            return dp[num];
        }
        
        vector<int> findCoins(vector<int>& numWays) {
            int n = numWays.size();
            vector<int> nA,A,used;
            
            // if(numWays[0] == 1) used.push_back(1);
            // else if(numWays[0] != 0) return {};
            
            for(int i=0;i<n;i++){
                int v = i+1;
    
                int exp = countWays(v,used);
    
                if(exp > numWays[i]) return {};
                else if(exp == numWays[i]-1) used.push_back(v);
                else if(exp == numWays[i]) continue;
                else return {};
            }
    
            return used;
        }
    };