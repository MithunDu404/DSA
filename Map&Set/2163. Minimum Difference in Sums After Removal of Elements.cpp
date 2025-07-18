// https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/

class Solution {
public:
    struct cmp {
        bool operator()(const pair<int,int>& a,const pair<int,int>& b) const {
            if(a.first != b.first)
                return a.first < b.first;
            return a.second < b.second;
        }
    };

    long long minimumDifference(vector<int>& nums) {
        int n = nums.size();

        set<pair<int,int>,cmp> st;
        for(int i=0;i<2*(n/3);i++) st.insert({nums[i],i});

        set<pair<int,int>> a;
        long long sa = 0;
        for(int i=0;i<(n/3);i++){
            auto [v,id] = *st.begin();
            st.erase(*st.begin());
            a.insert({v,id});
            sa += v;
        } 
    
        set<pair<int,int>> b;
        long long sb = 0; 
        for(int i=2*(n/3);i<n;i++){
            b.insert({nums[i],i});
            sb += nums[i];
        }

        long long ans = sa - sb;
        for(int i=2*(n/3)-1;i>=(n/3);i--){
            int v = nums[i];
            st.erase({v,i});

            int t = (*b.begin()).first;;
            if(v > t){
                sb -= t;
                sb += v;
                b.erase(*b.begin());
                b.insert({v,i});
            }

            if(a.find({v,i}) != a.end()){
                a.erase({v,i});
                sa -= v; 
                a.insert(*st.begin());
                sa += (*st.begin()).first;
                st.erase(*st.begin());
            }

            ans = min(ans,sa-sb);
        }

        return ans;

    }
};