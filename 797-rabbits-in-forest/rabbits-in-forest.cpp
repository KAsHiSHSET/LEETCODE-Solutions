class Solution {
public:
    int numRabbits(vector<int>& answers) {
        // 1 answer 2 loogo ne dia toh uska count hoga 2
        //2 answer diya 1 rabit ne toh uska count is 1
        //we will get to know the total count of 
        unordered_map<int,int> mpp;
        for(int i=0;i<answers.size();i++){
            mpp[answers[i]]++;
        }
        //x members -> x+1 rabbits
        //groupsize=ceil(count of x / x+1)
        //above check for each individual
        //total = groupsize*(x+1)
        int total=0;
        for(auto ch : mpp){
           int x = ch.first;
           int count=ch.second;
            //no of rabits in that grp
            int grpsize= x+1;
            
            int grp= ceil((double)count/grpsize);
            total+=  grp*grpsize;
          
        }
        return total;

    }
};