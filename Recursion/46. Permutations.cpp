// https://leetcode.com/problems/permutations/

class Solution {
public:
    void solve(vector<bool>& used,vector<int>& nums,vector<int>& curr,vector<vector<int>>& ans){
        int n = nums.size();
        if(curr.size() == n){
            ans.push_back(curr);
            return;
        }

        for(int i=0;i<n;i++){
            if(used[i]) continue;

            curr.push_back(nums[i]);
            used[i] = true;
            solve(used,nums,curr,ans);

            curr.pop_back(); // backtrack
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> used(nums.size(),false);
        solve(used,nums,curr,ans);
        return ans;
    }
};