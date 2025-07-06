// https://leetcode.com/problems/finding-pairs-with-a-certain-sum/

class FindSumPairs {
private:
    vector<int> n1,n2;
    unordered_map<int,int> mp;
    int n,m;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();
        n1.resize(n);
        n1 = nums1;
        n2.resize(m);
        n2 = nums2;
        for(int i=0;i<m;i++) mp[n2[i]]++;
    }
    
    void add(int index, int val) {
        mp[n2[index]]--;
        n2[index] += val;
        mp[n2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for(int i=0;i<n;i++){
            int v = tot-n1[i];
            ans += mp[v];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */