class Solution {
public:
    bool checkrows(vector<vector<char>> &board,int n){
        for(int i=0;i<n;i++){
            set<int> s;
            int c=0;
            for(int j=0;j<n;j++){
                if(board[i][j]!='.')
                s.insert(board[i][j]-'0');
                else
                    c++;
            }
            if(n-c!=s.size())
                return false;
        }
        return true;
    }
    bool checkcolumns(vector<vector<char>> &board,int n){
        for(int i=0;i<n;i++){
            set<int> s;
            int c=0;
            for(int j=0;j<n;j++){
                if(board[j][i]!='.')
                s.insert(board[j][i]-'0');
                else
                    c++;
            }
            if(n-c!=s.size())
                return false;
        }
        return true;
    }
    bool check3x3(vector<vector<char>> &board,int n){
        int i=0,j=0,c=0;
        set<int> s;
        for(i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]!='.')
                s.insert(board[i][j]-'0');
                else
                    c++;
            }
        }
        if(n-c!=s.size())
                return false;
        s.clear();
        c=0;
        for(i=0;i<3;i++){
            for(int j=3;j<6;j++){
                if(board[i][j]!='.')
                s.insert(board[i][j]-'0');
                else
                    c++;
            }
        }
        if(n-c!=s.size())
                return false;
        s.clear();
        c=0;
        for(i=0;i<3;i++){
            for(int j=6;j<9;j++){
                if(board[i][j]!='.')
                s.insert(board[i][j]-'0');
                else
                    c++;
            }
        }
        if(n-c!=s.size())
                return false;
        s.clear();
        c=0;
        for(i=3;i<6;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]!='.')
                s.insert(board[i][j]-'0');
                else
                    c++;
            }
        }
        if(n-c!=s.size())
                return false;
        s.clear();
        c=0;
        for(i=3;i<6;i++){
            for(int j=3;j<6;j++){
                if(board[i][j]!='.')
                s.insert(board[i][j]-'0');
                else
                    c++;
            }
        }
        if(n-c!=s.size())
                return false;
        s.clear();
        c=0;
        for(i=3;i<6;i++){
            for(int j=6;j<9;j++){
                if(board[i][j]!='.')
                s.insert(board[i][j]-'0');
                else
                    c++;
            }
        }
        if(n-c!=s.size())
                return false;
        s.clear();
        c=0;
        for(i=6;i<9;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]!='.')
                s.insert(board[i][j]-'0');
                else
                    c++;
            }
        }
        if(n-c!=s.size())
                return false;
        s.clear();
        c=0;
        for(i=6;i<9;i++){
            for(int j=3;j<6;j++){
                if(board[i][j]!='.')
                s.insert(board[i][j]-'0');
                else
                    c++;
            }
        }
        if(n-c!=s.size())
                return false;
        s.clear();
        c=0;
        for(i=6;i<9;i++){
            for(int j=6;j<9;j++){
                if(board[i][j]!='.')
                s.insert(board[i][j]-'0');
                else
                    c++;
            }
        }
        if(n-c!=s.size())
                return false;
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return (checkrows(board,board.size()) && checkcolumns(board,board.size()) && check3x3(board,board.size()));
    }
};