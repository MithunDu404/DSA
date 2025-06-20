class Solution {
public:
    void solve(int id, int n, vector<int>& nums, vector<int>& curr, set<vector<int>>& st){
        st.insert(curr);
        if(id >= n) return;
        curr.push_back(nums[id]);
        solve(id+1,n,nums,curr,st);
        curr.pop_back();
        solve(id+1,n,nums,curr,st);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>> st;
        vector<int> curr;
        solve(0,n,nums,curr,st);
        vector<vector<int>> ans;
        for(auto& v : st) ans.push_back(v);
        return ans;
    }
};