// https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();

        vector<int> p(n,0);
        for(int i=0;i<n;i++) p[i] = endTime[i]-startTime[i];
        for(int i=1;i<n;i++) p[i] += p[i-1];

        if(k >= n) return eventTime - p[n-1];

        int l = 0;
        int r = k+1;
        int ans = 0;
        while(r < n){
            int temp = endTime[r]-startTime[l]-p[r];
            if(l > 0) temp += p[l-1];
            ans = max(ans,temp);
            r++;
            l++;
        }
        
        ans = max(ans,endTime[k]-p[k]);
        ans = max(ans,eventTime-endTime[n-k-1] -(p[n-1]-p[n-k-1]));
        
        return ans;
    }
};