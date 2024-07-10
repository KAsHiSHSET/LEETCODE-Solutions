class Solution {
public:
int m,n;
    bool solve(vector<vector<char>>& board,string word,int i,int j,int index){
        if(i<0||j<0||i>=m||j>=n||board[i][j]!=word[index]) return false;
        if(index==word.length()-1) return true;
        char recover=word[index];
        board[i][j]='@';//no alphanumeric characters
        bool left=solve(board,word,i+1,j,index+1);
        bool right=solve(board,word,i-1,j,index+1);
        bool up=solve(board,word,i,j-1,index+1);
        bool down=solve(board,word,i,j+1,index+1);
        board[i][j]=recover;
        return left||right||up||down;
    }
    bool exist(vector<vector<char>>& board, string word) {
         m=board.size();
         n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int index=0;
                bool ans=solve(board,word,i,j,index);
                if(ans) return true;
                else{
                    continue;
                }
          }
         
          
    }
     return false;
          
}};