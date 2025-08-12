#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int mod = 1e9+7;

int main(){
    int n;cin>>n;
    vector<int> dp(n+1,0);
    dp[0] = 1;
    for(int sum=0;sum<=n;sum++){
        for(int k=1;k<=6;k++){
            if(sum+k <= n) dp[sum+k] = (dp[sum+k] + dp[sum])%mod;
        }
    }
    cout<< dp[n];
}