//STRIVER_SDE_SHEET

class Solution {
public:
    vector<vector<string>> ans;

bool isPossible(int n, int row, int col, vector<string>&board){
    
    for(int i=row-1;i>=0;i--){                 //checking vertically upwards, row changing, col fixed
        if(board[i][col]=='Q') return false;
    }
    
    for(int i=row-1, j=col-1; i>=0 && j>=0; i--,j--){  //upper left diagonally
        if(board[i][j]=='Q') return false;
    }
    
    for(int i=row-1, j=col+1; i>=0 && j<n ; i--,j++){  //upper right diagonally
        if(board[i][j]=='Q') return false;
    }
    
    return true;
}

void helper(int n, int row, vector<string>&board){
    
    if(n==row){
        ans.push_back(board);
        return;
    }
    
    for(int col=0;col<n;col++){
        
        if(isPossible(n,row,col,board)){ //if Queen can be placed on given square, then proceed
            
            board[row][col]='Q';
            helper(n,row+1,board);
            board[row][col]='.';    //backtrack
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    
    string s(n,'.');
    vector<string> board(n,s);  //board is initialised with '.' of size n*n
    helper(n,0,board);
    return ans;
}
};