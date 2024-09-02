class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
       long long int sum=accumulate(chalk.begin(),chalk.end(),0LL);
        int total=k%sum;
        // if(total==0) return 0;
        int i=0;
        for(;i<chalk.size();i++){
            if(total>chalk[i]){
               total=total-chalk[i];
            }
            else if(total==chalk[i]) return i+1;
           else{
             break;
           }
        }
        return i;
    }
};
