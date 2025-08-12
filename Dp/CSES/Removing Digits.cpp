#include<bits/stdc++.h>
using namespace std;
int mod = 1e9+7;

int main(){
    int n;cin>>n;
    vector<int> dp(n+1,INT_MAX-1);
    dp[n]= 0;
    for(int i=n;i>=0;i--){
        for(char& d : to_string(i)){
            int v = d-'0';
            if(i-v >= 0) dp[i-v] = min(dp[i-v],dp[i]+1);
        }
    }

    cout<< dp[0];
}