// https://leetcode.com/problems/maximize-subarrays-after-removing-one-conflicting-pair/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& cp) {
        long long ans = 0;
        map<int,vector<int>> mp;
        for(auto& v : cp){
            int a = min(v[0],v[1]);
            int b = max(v[0],v[1]);
            mp[b].push_back(a);
        }

        int maxConf = 0;
        int secConf = 0;
        vector<long long> extra(n+1,0);

        for(int i=1;i<=n;i++){
            for(auto& v : mp[i]){
                if(v >= maxConf){
                    secConf = maxConf;
                    maxConf = v;
                }
                else if(v > secConf){
                    secConf = v;
                }
            }

            ans += i - maxConf;
            extra[maxConf] += maxConf-secConf;
        }

        return ans + *max_element(extra.begin(),extra.end());
    }
};