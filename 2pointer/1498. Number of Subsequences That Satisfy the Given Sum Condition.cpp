// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/


// With binary search
class Solution {
public:
    int M = 1e9+7;
    
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<int> power(n);
        power[0] = 1;
        for(int i=1;i<n;i++){
            power[i] = (power[i-1] + power[i-1])%M;
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            int v = target - nums[i];
            if(v < nums[i]) break;
            int id = upper_bound(nums.begin(),nums.end(),v) - nums.begin() - 1;
            int k = id - i;
            ans = (int)(ans + power[k]) % M;
        }

        return ans;
    }
};

// With two pointer

class Solution {
public:
    int M = 1e9+7;
    
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<int> power(n);
        power[0] = 1;
        for(int i=1;i<n;i++){
            power[i] = (power[i-1] + power[i-1])%M;
        }

        int ans = 0;
        int l = 0;
        int r = n-1;
        while(l <= r){
            if(nums[l] + nums[r] > target) r--;
            else{
                ans = (ans + power[r-l]) % M;
                l++;
            }
        }

        return ans;
    }
};