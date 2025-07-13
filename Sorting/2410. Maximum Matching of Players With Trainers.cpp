// https://leetcode.com/problems/maximum-matching-of-players-with-trainers/

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = players.size();
        int m = trainers.size();
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());

        int i = 0;
        int j = 0;
        int ans = 0;
        while(i<n && j<m){
            int v = players[i];
            while(j<m && trainers[j]<v){
                j++;
            }
            if(j == m) break;
            ans++;
            j++;
            i++;
        }

        return ans;
    }
};