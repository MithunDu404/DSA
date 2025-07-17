// Given an array of length n, find the number of subsequence with length of 3 and not all three numbers are odd or even.
// 1 <= n <= 10^6

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int M = 1e9+7;

ll power(ll base, ll exp) {
    ll ans = 1;
    base %= M;
    while (exp > 0) {
        if (exp % 2 == 1) ans = (ans * base) % M;
        base = (base * base) % M;
        exp /= 2;
    }
    return ans;
}

ll mmi(int n){
    return power(n,M-2);
}

ll solve(ll n){
    ll ans = (n*(n-1))%M;
    ans = (ans*mmi(2))%M;
    return ans;
}

int main(){
    ll n;cin>>n;
    ll odd = 0, even = 0;
    for(int i=0;i<n;i++){
        int v;cin>>v;
        if(v&1) odd++;
        else even++;
    }

    if(odd == 0 || even == 0){
        cout<<0<<endl;
        return 0;
    }
    ll ans = 0;
    if(odd >= 1 && even >= 2) ans = (ans + (odd*solve(even))%M)%M;
    if(even >= 1 && odd >= 2) ans = (ans + (even*solve(odd))%M)%M;
    cout<<ans<<endl;
    return 0;
}
