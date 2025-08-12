#include<bits/stdc++.h>
using namespace std;
int mod = 1e9+7;

int main(){
    int n;cin>>n;
    int x;cin>>x;
    vector<int> a(n);for(int i=0;i<n;i++) cin>>a[i];

    vector<int> dp(x+1,0);
    dp[0] = 1;
    for(int sum = 0;sum<=x;sum++){
        for(int& v : a){
            if(sum + v <= x) dp[sum + v] = (dp[sum+v]+dp[sum])%mod;
        }
    }

    cout<< dp[x];
}