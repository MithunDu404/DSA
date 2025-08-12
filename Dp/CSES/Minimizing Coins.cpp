#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    int x;cin>>x;
    vector<int> a(n);for(int i=0;i<n;i++) cin>>a[i];

    vector<int> dp(x+1,INT_MAX-1);
    dp[0] = 0;
    for(int sum = 0;sum<=x;sum++){
        for(int& v : a){
            if(sum + v <= x) dp[sum + v] = min(dp[sum+v],dp[sum]+1);
        }
    }

    cout<< ((dp[x]==INT_MAX-1)? -1: dp[x]);
}