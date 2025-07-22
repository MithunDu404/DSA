// https://leetcode.com/problems/maximum-erasure-value/

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        int sum = 0;
        int ans = 0;
        int i = 0;
        int j = 0;
        while(i < n){
            while(j < i && nums[j] != nums[i]){
                st.erase(nums[j]);
                sum -= nums[j];
                j++;
            }
            if(j < i && nums[j] == nums[i]){
                st.erase(nums[j]);
                sum -= nums[j];
                j++;
            }
            while(i < n && st.find(nums[i]) == st.end()){
                sum += nums[i];
                ans = max(ans,sum);
                st.insert(nums[i]);
                i++;
            }
        }

        return ans;
    }
};