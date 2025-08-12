#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

int main(){
    int n,m;cin>>n>>m;
    vector<int> a(n);for(int i=0;i<n;i++) cin>>a[i];
    vector<vector<int>> dp(n,vector<int>(m+1,0));
    if(a[0] == 0){
        for(int i=1;i<=m;i++) dp[0][i] = 1;
    }
    else dp[0][a[0]] = 1;

    for(int i=0;i<n-1;i++){
        for(int v=1;v<=m;v++){
            for(int y : {v-1,v,v+1}){
                if(y >= 1 && y <= m){
                    if(a[i+1] != 0 && a[i+1] != y) continue;
                    dp[i+1][y] = (dp[i+1][y] + dp[i][v])%mod;
                }
            }
        }
    }

    if(a[n-1] == 0){
        int ans = 0;
        for(int i=1;i<=m;i++) ans = (ans + dp[n-1][i])%mod;
        cout<<ans;
    }
    else cout<<dp[n-1][a[n-1]];
}