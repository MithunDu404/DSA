// https://leetcode.com/contest/biweekly-contest-160/problems/minimum-cost-path-with-alternating-directions-ii/

class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector<vector<long long>> a(m,vector<long long>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                a[i][j] = (long long)(i+1)*(long long)(j+1);
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i == 0 && j == 0) continue;
                if(!(i==m-1 && j==n-1)) a[i][j] += waitCost[i][j];

                long long l = 1e18,r = 1e18;
                if(i-1 >= 0){
                    l = a[i-1][j];
                }
                if(j-1 >= 0){
                    r = a[i][j-1];
                }

                a[i][j] += min(l,r);
            }
        }

        return a[m-1][n-1];
    }
};