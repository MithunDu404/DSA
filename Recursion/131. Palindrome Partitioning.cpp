// https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:
    bool isPalindrome(string& s){
        string t = s;
        reverse(t.begin(),t.end());
        return s == t;
    }

    void solve(int id,string& s,vector<string>& curr, vector<vector<string>>& ans){
        int n = s.size();

        if(id == n){
            ans.push_back(curr);
            return;
        }
        
        string t = "";
        for(int i=id;i<n;i++){
            t += s[i];
            if(isPalindrome(t)){
                curr.push_back(t);
                solve(i+1,s,curr,ans);
                curr.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        solve(0,s,curr,ans);
        return ans;
    }
};