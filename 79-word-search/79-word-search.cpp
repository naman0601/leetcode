class Solution {
public:
    bool bt(vector<vector<char>>& board, string word,int i,int j,int k){
         if(k>=word.length()) return true;
      if(i>=board.size()||i<0||j>=board[0].size()||j<0||board[i][j]!=word[k] || board[i][j]=='0' ) return false;
      char temp = board[i][j];
      board[i][j] = '0';
      if(bt(board,word,i,j+1,k+1)||bt(board, word,i+1,j,k+1)||bt(board, word, i, j-1, k+1)||bt(board, word, i-1, j, k+1))
           return true;
      board[i][j] = temp;
      return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
          for(int i = 0;i<board.size();i++){
          for(int j=0;j<board[0].size();j++){
              if(bt(board,word,i,j,0))
              return true;
          }
      }
      return false;
    }
};