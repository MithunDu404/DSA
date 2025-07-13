// https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-ii/

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();

        vector<int> g;
        int l = 0;
        for(int i=0;i<n;i++){
            g.push_back(startTime[i]-l);
            l = endTime[i];
        }
        g.push_back(eventTime-l);

        sort(g.begin(),g.end());
        int m = g.size();

        int ans = 0;
        for(int i=0;i<n;i++){
            int total_gap = 0;
            if(i == 0){
                int w = endTime[0]-startTime[0];

                int g1 = startTime[0];
                int g2 = startTime[1]-endTime[0];
                total_gap += (g1+g2);
                
                int x = 0;
                if(g1 >= w) x++;
                if(g2 >= w) x++;
                
                int id = lower_bound(g.begin(),g.end(),w)-g.begin();
                if(m-id > x) total_gap += w;
                
                ans = max(ans,total_gap);
            }
            else if(i == n-1){
                int w = endTime[i]-startTime[i];

                int g1 = startTime[i]-endTime[i-1];
                int g2 = eventTime-endTime[i];
                total_gap += (g1+g2);

                int x = 0;
                if(g1 >= w) x++;
                if(g2 >= w) x++;
                
                int id = lower_bound(g.begin(),g.end(),w)-g.begin();
                if(m-id > x) total_gap += w;
                
                ans = max(ans,total_gap);
            }
            else{
                int w = endTime[i]-startTime[i];

                int g1 = startTime[i]-endTime[i-1];
                int g2 = startTime[i+1]-endTime[i];
                total_gap += (g1+g2);

                int x = 0;
                if(g1 >= w) x++;
                if(g2 >= w) x++;
                
                int id = lower_bound(g.begin(),g.end(),w)-g.begin();
                if(m-id > x) total_gap += w;
                
                ans = max(ans,total_gap);
            }
        }
        return ans;
    }
};