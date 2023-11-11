class Solution {
public:
    bool solve(vector<vector<char>>& board, string word,int ind,int sr,int sc){
        if(ind<0 || sr<0 || sc<0 || sr>=board.size() || sc>=board[0].size()) return false;
        if(ind==word.size()) return true;
        bool a=false,b=false,c=false,d=false;
        if(word[ind]==board[sr][sc]){
            char temp = board[sr][sc];
            board[sr][sc]='*';
            a = solve(board,word,ind+1,sr-1,sc);
            b= solve(board,word,ind+1,sr+1,sc);
            c= solve(board,word,ind+1,sr,sc-1);
            d= solve(board,word,ind+1,sr,sc+1);
            board[sr][sc]=temp;
        }
        return a||b||c||d;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int ind = 0;
        if(word.length()==1){
            for(int i=0;i<board.size();i++){
                for(int j=0;j<board[0].size();j++){
                    if(board[i][j]==word[0]){
                        return true;
                    }
                }
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[ind]){
                    if(solve(board,word,ind,i,j)) return true;
                }
            }
        }
        return false;
    }
};