// https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/

// TC -> O(100 * n * log(n))
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        sort(folder.begin(),folder.end());

        set<string> st;
        vector<string> ans;
        for(int i=0;i<n;i++){
            bool find = false;
            string s = "";
            int m = folder[i].size();
            
            for(int j=0;j<m;j++){
                if((folder[i][j] == '/' || j == m-1)  && !s.empty()){
                    if(j == m-1) s += folder[i][j];
                    if(st.find(s) != st.end()){
                        find = true;
                        break;
                    }
                }
                s += folder[i][j];
            }
            
            if(!find){
                st.insert(folder[i]);
                ans.push_back(folder[i]);
            }
        }

        return ans;
    }   
};

// TC -> O(100 * n)
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        sort(folder.begin(),folder.end());

        vector<string> ans;
        for(auto& s : folder){
            if(ans.empty() || s.find(ans.back()+'/') != 0)
                ans.push_back(s);
        }
        return ans;
    }   
};