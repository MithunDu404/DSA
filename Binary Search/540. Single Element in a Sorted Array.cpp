// https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution {
    public:
        int singleNonDuplicate(vector<int>& nums) {
            int n = nums.size();
            int l = 0;
            int r = n-1;
            while(l < r){
                int mid = l + (r-l)/2;
                
                int left,right;
                if(mid > 0 && nums[mid] == nums[mid-1]){
                    left = mid-1;
                    right = n-mid-1;
                }
                else if(mid < n-1 && nums[mid] == nums[mid+1]){
                    left = mid;
                    right = n-mid-2;
                }
                else return nums[mid];
                
                if(left&1){
                    r = left-1;
                }
                else l = n-right;
            }
    
            return nums[l];
        }
    };