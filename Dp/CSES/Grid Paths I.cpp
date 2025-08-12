#include<bits/stdc++.h>
using namespace std;
int mod = 1e9+7;

int main(){
    int n;cin>>n;
    vector<string> a(n);for(int i=0;i<n;i++) cin>>a[i];
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    if(a[0][0] == '*'){
        cout<<0;
        return 0;
    }
    else dp[0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i+1 < n && a[i+1][j] == '.') dp[i+1][j] = (dp[i+1][j] + dp[i][j])%mod;
            if(j+1 < n && a[i][j+1] == '.') dp[i][j+1] = (dp[i][j+1] + dp[i][j])%mod;
        }
    }
    cout<<dp[n-1][n-1];
}