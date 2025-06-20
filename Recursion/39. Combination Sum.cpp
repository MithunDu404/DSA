// https://leetcode.com/problems/combination-sum/

class Solution {
public:
    void solve(int sum,int id, vector<int>& curr, vector<vector<int>>& ans,vector<int>& nums, int k){
        if(sum > k) return;
        if(sum == k){
            ans.push_back(curr);
            return;
        }

        for(int i=id;i<nums.size();i++){
            if(sum+nums[i] > k) continue;
            curr.push_back(nums[i]);
            solve(sum+nums[i],i,curr,ans,nums,k);
            
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0,0,curr,ans,candidates,target);
        return ans;
    }
};