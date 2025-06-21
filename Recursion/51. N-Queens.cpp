// https://leetcode.com/problems/n-queens/

class Solution {
    public:
        void solve(int row, int n, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2, vector<string>& curr, vector<vector<string>>& ans) {
            if(row == n) {
                ans.push_back(curr);
                return;
            }
    
            for(int col=0;col<n;col++) {
                int d1 = row + col;
                int d2 = row - col + n - 1;
    
                if(cols[col] || diag1[d1] || diag2[d2]) continue;
    
                curr[row][col] = 'Q';
                cols[col] = diag1[d1] = diag2[d2] = true;
    
                solve(row+1, n, cols, diag1, diag2, curr, ans);
    
                curr[row][col] = '.';
                cols[col] = diag1[d1] = diag2[d2] = false;
            }
        }
    
        vector<vector<string>> solveNQueens(int n) {
            vector<vector<string>> ans;
            vector<string> curr(n, string(n, '.'));
            vector<bool> cols(n, false);
            vector<bool> diag1(2*n-1, false); // row + col
            vector<bool> diag2(2*n-1, false); // row - col + n - 1
    
            solve(0, n, cols, diag1, diag2, curr, ans);
            return ans;
        }
    };
    