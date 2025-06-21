// https://leetcode.com/problems/permutation-sequence/

// using unordered_set to track used numbers   ->    TLE !!!!!!
class Solution {
public:
    void solve(int& p,string& curr,unordered_set<int>& st,int n,int k,string& ans){
        if(curr.size() == n){
            p++;
            if(p == k) ans = curr;
            return;
        }

        for(int i=1;i<=n;i++){
            if(st.find(i) != st.end()) continue;

            curr += to_string(i);
            st.insert(i);
            solve(p,curr,st,n,k,ans);
            if(ans != "") return;
            curr.pop_back();
            st.erase(i);
        }
    }

    string getPermutation(int n, int k) {
        string curr = "";
        string ans = "";
        int p = 0;
        unordered_set<int> st;
        solve(p,curr,st,n,k,ans);
        return ans;
    }
};

// using the vector<bool> to track used numbers     ->   Accepted
class Solution {
public:
    void solve(int& p,string& curr,vector<bool>& use,int n,int k,string& ans){
        if(curr.size() == n){
            p++;
            if(p == k) ans = curr;
            return;
        }

        for(int i=1;i<=n;i++){
            if(use[i]) continue;

            curr += to_string(i);
            use[i] = true;
            solve(p,curr,use,n,k,ans);
            if(ans != "") return;
            curr.pop_back();
            use[i] = false;
        }
    }

    string getPermutation(int n, int k) {
        string curr = "";
        string ans = "";
        int p = 0;
        vector<bool> use(n+1,false);
        solve(p,curr,use,n,k,ans);
        return ans;
    }
};