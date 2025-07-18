// https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    int n,m;
    vector<vector<int>> dirs{{0,1},{0,-1},{1,0},{-1,0}};

    bool valid(int i,int j,vector<vector<char>>& grid){ 
        if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == '1')
            return true;
        return false;
    }

    void solve(int x,int y,vector<vector<bool>>& visited,vector<vector<char>>& grid){
        visited[x][y] = true;
        for(auto dir : dirs){
            int i = x + dir[0];
            int j = y + dir[1];
            if(valid(i,j,grid) && !visited[i][j]){
                solve(i,j,visited,grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    solve(i,j,visited,grid);
                    count++;
                }
            }
        }

        return count;
    }
};