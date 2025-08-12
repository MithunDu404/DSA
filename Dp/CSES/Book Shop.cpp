#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;cin>>n>>x;
    vector<int> price(n);for(int i=0;i<n;i++) cin>>price[i];
    vector<int> page(n);for(int i=0;i<n;i++) cin>>page[i];

    vector<int> dp(x+1,0);
    for(int i=0;i<n;i++){
        for(int sum = x;sum>=0;sum--){
            if(sum+price[i] <= x) dp[sum+price[i]] = max(dp[sum+price[i]],dp[sum] + page[i]);
        }
    }

    cout<<*max_element(dp.begin(),dp.end());
}