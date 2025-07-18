// Given a number N, what is the smallest perfect pallindrome just greater than N.
// Perfect pallindrome is a number in which digit i appears i times and is also a pallindrome

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve2(int sum,int n,vector<int>& curr,set<int>& st,vector<ll>& ans){
    if(sum > n) return;
    if(sum == n){
        int odd = 0, even = 0;
        for(int v : curr){
            if(v&1) odd++;
            else even++;
        }
        string t = "";
        if(n&1){
            if(odd != 1) return;
            if(curr.back()%2==0) return;
            int m = curr.size();
            for(int i=0;i<m-1;i++){
                for(int j=0;j<curr[i]/2;j++){
                    t += to_string(curr[i]);
                }
            }
            for(int i=0;i<curr[m-1];i++) t += to_string(curr[m-1]);
            for(int i=m-2;i>=0;i--){
                for(int j=0;j<curr[i]/2;j++){
                    t += to_string(curr[i]);
                }
            }
        }
        else{
            if(odd != 0) return;
            int m = curr.size();
            for(int i=0;i<m;i++){
                for(int j=0;j<curr[i]/2;j++){
                    t += to_string(curr[i]);
                }
            }
            for(int i=m-1;i>=0;i--){
                for(int j=0;j<curr[i]/2;j++){
                    t += to_string(curr[i]);
                }
            }
        }
        if(t.empty()) return;
        ans.push_back(stoll(t));
        return;
    }

    for(int i=1;i<=9;i++){
        if(st.find(i) == st.end() && sum+i <= n){
            st.insert(i);
            curr.push_back(i);
            solve2(sum+i,n,curr,st,ans);

            st.erase(i);
            curr.pop_back();
        }
    }
}

vector<ll> solve(int n){
    vector<ll> ans;
    vector<int> curr;
    set<int> st;
    solve2(0,n,curr,st,ans);
    return ans;
}

int main(){
    ll n;cin>>n;
    int bits = (int)log10(n)+1;
    vector<ll> a = solve(bits);
    int id = upper_bound(a.begin(),a.end(),n) - a.begin();
    if(id < (int)a.size()){
        cout<<a[id]<<endl;
        return 0;
    }
    vector<ll> b = solve(bits+1);
    cout<<b[0]<<endl;
}