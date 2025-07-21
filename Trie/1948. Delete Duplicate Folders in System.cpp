// https://leetcode.com/problems/delete-duplicate-folders-in-system/

class Solution {
public:
    struct Node{
        string val;
        string subFolder;
        unordered_map<string,Node*> childrens;
    };

    Node* getNode(const string& s){
        Node* temp = new Node();
        temp->val = s;
        temp->subFolder = "";
        return temp;
    }

    void insert(vector<string>& path,Node* root){
        for(auto& s : path){
            if(!root->childrens.count(s)){
                root->childrens[s] = getNode(s);
            }

            root = root->childrens[s];
        }
    }

    string populate(Node* root,unordered_map<string,int>& subFoldersCount){
        vector<pair<string,string>> subPaths; // pair for sorting purpose by childName

        for(auto& [childName,child] : root->childrens){
            string s = populate(child,subFoldersCount);
            subPaths.push_back({childName,s});
        }

        sort(subPaths.begin(),subPaths.end());

        string completePath = "";
        for(auto& [childName,child] : subPaths){
            completePath += "(" + childName + child + ")";
        }

        root->subFolder = completePath;

        if(!completePath.empty()) subFoldersCount[completePath]++;

        return completePath;
    }

    void remove(Node* root,unordered_map<string,int>& subFoldersCount){
        for(auto it = root->childrens.begin();it!=root->childrens.end();){
            string name = it->first;
            Node* child = it->second;

            if(!child->subFolder.empty() && subFoldersCount[child->subFolder]>1){
                it = root->childrens.erase(it);
            }
            else{
                remove(child,subFoldersCount);
                it++;
            }
        }
    }

    void solve(Node* root, vector<string>& curr, vector<vector<string>>& ans){
        for(auto& [childName, child] : root->childrens){
            curr.push_back(childName);
            ans.push_back(curr);
            solve(child, curr, ans);
            curr.pop_back();
        }
    }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node* Root = getNode("*");

        // Creating the trie
        for(auto& path : paths) insert(path,Root);

        // Assigning the subFolders to each folder
        unordered_map<string,int> subFoldersCount;
        populate(Root,subFoldersCount);

        // Removing the duplicate folders
        remove(Root,subFoldersCount);

        // Putting the current folders to ans
        vector<vector<string>> ans;
        vector<string> curr;
        solve(Root,curr,ans);

        return ans;
    }
};