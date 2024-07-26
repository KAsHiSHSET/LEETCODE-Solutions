class Solution {
public:
    bool isSafe(int board[][10], int i, int j, int n) {
        //colmun
        for(int row=0;row<i;row++) 
        {
            if(board[row][j]==1) 
            {
                return false;
            }
        }

        //left diagonal
        int x=i;
        int y=j;
        while(x>=0 && y>=0) 
        {
            if(board[x][y]==1) 
            {
                return false;
            }
            x--;
            y--;
        }

        //right diagonal
        x=i;
        y=j;
        while(x>=0 && y<n) 
        {
            if(board[x][y]==1) 
            {
                return false;
            }
            x--;
            y++;
        }

        return true;
    }
bool NQueen(int board[][10],int i,int n, vector<vector<string>>& v) {
        //base 
        if(i==n) 
        {
            vector<string>curr;
            for (int row=0;row<n;row++)
            {
                string rowStr;
                for(int col=0;col<n;col++) 
                {
                    if(board[row][col]==1) 
                    {
                        rowStr+='Q';
                    } 
                    else 
                    {
                        rowStr+='.';
                    }
                }
                curr.push_back(rowStr);
            }
            v.push_back(curr);

            return false;
        }

        //rec case
        //try to place queen in curr row and call on remaining
        for(int j=0;j<n;j++) 
        {
            //check if (i,j) is safe to place
            if(isSafe(board,i,j,n)== true) 
            {
             //place the queen, assuming (i,j) is right pos
                board[i][j]=1;
                bool NextQueen=NQueen(board,i+1,n, v);
                if(NextQueen==true) 
                {
                    return true;
                }
                // out assumpton is wrong
                board[i][j]=0;
            }
        }
        // tried for all pos but could not place the queen
        return false;
    }
    vector<vector<string>> solveNQueens(int n) {
        int board[10][10];
        vector<vector<string>>v;
        vector<string> curr;
        NQueen(board,0,n,v);

        return v;
    }
};