// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> l,r;
        int mini = prices[0];
        int a = 0;
        for(int i=0;i<n;i++){
            if(prices[i] < mini){
                mini = prices[i];
                l.push_back(a);
            }
            else{
                a = max(a,prices[i]-mini);
                l.push_back(a);
            }
        }

        reverse(prices.begin(),prices.end());
        a = prices[0];
        int maxi = prices[0];
        for(int i=0;i<n;i++){
            if(prices[i] > maxi){
                maxi = prices[i];
                r.push_back(-a);
            }
            else{
                a = min(a,prices[i]-maxi);
                r.push_back(-a);
            }
        }
        reverse(r.begin(),r.end());
        
        int ans = 0;
        for(int i=0;i<n;i++){
            if(i == n-1) ans = max(l[n-1],ans);
            else{
                ans = max(ans,l[i]+r[i+1]);
            }
        }
        return ans;
    }
};