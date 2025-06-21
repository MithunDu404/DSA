// https://leetcode.com/problems/sudoku-solver/

class Solution {
    public:
        vector<vector<char>> ans = vector<vector<char>>(9,vector<char>(9,'.'));
        bool f = false;
    
        void solve(int count,vector<vector<bool>>& rows,vector<vector<bool>>& cols,vector<vector<vector<bool>>>& block,vector<vector<char>>& board) {
            if(count == 81){
                ans = board;
                f = true;
                return;
            }
    
            int i = count/9;
            int j = count%9;
    
            if(board[i][j] != '.'){
                solve(count + 1,rows,cols,block,board);
                return;
            }
    
            for(int n=0;n<9;n++){
                if(rows[i][n] || cols[j][n] || block[i/3][j/3][n]) continue;
    
                rows[i][n] = cols[j][n] = block[i/3][j/3][n] = true;
                board[i][j] = '1'+n;
    
                solve(count+1,rows,cols,block,board);
                if(f) return;
    
                rows[i][n] = cols[j][n] = block[i/3][j/3][n] = false;
                board[i][j] = '.';
            }
        }
    
        void solveSudoku(vector<vector<char>>& board) {
            vector<vector<bool>> rows(9,vector<bool>(9,false));
            vector<vector<bool>> cols(9,vector<bool>(9,false));
            vector<vector<vector<bool>>> block(3,vector<vector<bool>>(3,vector<bool>(9,false)));
    
            int count = 0;
    
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    if (board[i][j] != '.'){
                        count++;
                        int num = board[i][j]-'1';  
                        rows[i][num] = true;
                        cols[j][num] = true;
                        block[i/3][j/3][num] = true;
                    }
                }
            }
    
            solve(0,rows,cols,block,board);  
            board = ans;
        }
    };
    