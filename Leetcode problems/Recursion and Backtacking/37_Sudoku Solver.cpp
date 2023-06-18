class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char ch){
        //checking row
        for(int j=0;j<9;j++){
            if(board[row][j] == ch) return false;
        }
        
        //checking column
        for(int i=0;i<9;i++){
            if(board[i][col] == ch) return false;
        }
        //checking 9x9 matrix
        for(int k=0;k<9;k++){
            if(board[3*(row/3) + (k/3)][3*(col/3) + (k%3)] == ch) return false;
        }
        
        return true;
    }
    
     bool solve(vector<vector<char>>& board){
         // int n = board[0].size();
         for(int row=0; row< board.size();row++){
             for(int col=0; col< board[0].size();col++){
                 if(board[row][col] == '.'){
                     for(int ch='1'; ch<='9'; ch++){
                         if(isSafe(board, row, col, ch)){
                             board[row][col] = ch;
                             // solve(board);
                              if(solve(board)==true) {
                                  return true;
                              }
                              board[row][col] ='.';
                         }
                      }
                     return false;
                 }
                 
             }
         }
         return true;
     }
    
     void solveSudoku(vector<vector<char>>& board) {
         solve(board);
    }
};

