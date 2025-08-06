// https://leetcode.com/problems/fruits-into-baskets-iii/

class Solution {
public:
    void build(int i,int l,int r,vector<int>& buskets,vector<int>& segmentTree){
        if(l == r){
            segmentTree[i] = buskets[l];
            return;
        }

        int m = l + (r-l)/2;
        build(2*i+1,l,m,buskets,segmentTree);
        build(2*i+2,m+1,r,buskets,segmentTree);

        segmentTree[i] = max(segmentTree[2*i+1],segmentTree[2*i+2]);
    }

    bool check(int i,int l,int r,vector<int>& segmentTree,int fruit){
        if(segmentTree[i] < fruit) return false;
        if(l == r){
            segmentTree[i] = -1;
            return true;
        }

        int m = l + (r-l)/2;
        bool f = false;

        if(segmentTree[2*i+1] >= fruit) 
            f = check(2*i+1,l,m,segmentTree,fruit);
        else f = check(2*i+2,m+1,r,segmentTree,fruit);

        segmentTree[i] = max(segmentTree[2*i+1],segmentTree[2*i+2]);

        return f;
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<int> segmentTree(4*n,-1);
        build(0,0,n-1,baskets,segmentTree);

        int ans = 0;
        for(int i=0;i<n;i++){
            if(!check(0,0,n-1,segmentTree,fruits[i])) ans++;
        }
        return ans;
    }
};