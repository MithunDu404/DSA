// https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/

class Solution {
public:
    int longestAlternatingSubsequence(vector<int>& nums){
        int n = nums.size();

        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i]) == mp.end()){
                mp[nums[i]] = mp.size();
            }
        }
        int k = mp.size();

        vector<vector<int>> dp(k,vector<int>(k,0));
        int ans = 1;

        for(int i=0;i<n;i++){
            int x = mp[nums[i]];

            for(int y=0;y<k;y++){

                if(x == y) dp[x][x]++; // xxxxx...
                else dp[y][x] = dp[x][y] + 1;// xyxyx... or yxyxy...

                ans = max(ans,dp[y][x]);
            }
        }

        return ans;
    }

    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            nums[i] %= k;
            mp[nums[i]]++;
        }

        return longestAlternatingSubsequence(nums);
    }
};