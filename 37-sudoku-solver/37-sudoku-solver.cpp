class Solution {
public:
    bool isItSafe(vector<vector<char>> &board, int i, int j, char val)
{
    //checking row and col
        for(int k=0;k<9;k++){
            if(board[i][k]==val || board[k][j]==val){
                return false;
            }
        }   
        // checking 3x 3 subgrid
        int si=i-i%3;
        int sj=j-j%3;
        for(int i=si;i<si+3;i++){
            for(int j=sj;j<sj+3;j++){
                if(board[i][j]==val){
                    return false;
                }
            }
        }
        return true;
}
bool solveSudoku(vector<vector<char>> &board, int i, int j)
{
    if(i==board.size()) return true;
    if(j==board.size()) return solveSudoku(board, i+1, 0);
    if(board[i][j] != '.') return solveSudoku(board, i, j+1);

    for(char c='1'; c<='9'; c++)
    {
        if(isItSafe(board, i, j, c)==true)
        {
            board[i][j] = c;
            if(solveSudoku(board, i, j+1)==true) return true;
            //otherwise backtrack
            board[i][j] = '.';
        }
    }
        
    return false;
}

void solveSudoku(vector<vector<char>>& board) {
solveSudoku(board, 0, 0);
}
    
};