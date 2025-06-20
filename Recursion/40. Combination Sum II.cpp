// https://leetcode.com/problems/combination-sum-ii/

class Solution {
public:
    void solve(int id, int sum,vector<int>& curr,vector<vector<int>>& ans,vector<int>& nums,int k){
        if(sum == k){
            ans.push_back(curr);
            return;
        }
        if(id >= nums.size()) return;

        for(int i=id;i<nums.size();i++){
            if(sum+nums[i] > k) continue;
            if(id != i && nums[i] == nums[i-1]) continue;

            curr.push_back(nums[i]);
            solve(i+1,sum+nums[i],curr,ans,nums,k);

            curr.pop_back(); //backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());

        vector<vector<int>> ans;
        vector<int> curr;
        solve(0,0,curr,ans,candidates,target);
        return ans;
    }
};