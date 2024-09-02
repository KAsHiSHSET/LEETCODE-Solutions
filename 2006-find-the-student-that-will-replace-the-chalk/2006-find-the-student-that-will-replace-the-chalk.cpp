// class Solution {
// public:
//     int chalkReplacer(vector<int>& chalk, int k) {
//        long long int sum=accumulate(chalk.begin(),chalk.end(),0LL);
//         int total=k%sum;
//         if(total==0) return 0;
//         int i=0;
//         for(;i<chalk.size();i++){
//             if(total>chalk[i]){
//                total=total-chalk[i];
//             }
//            else{
//              break;
//            }
//         }
//         return i;
//     }
// };
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = accumulate(chalk.begin(), chalk.end(), 0LL);  // Accumulate chalk usage to find the total
        k %= sum;  // Reduce k modulo the total sum to optimize the process

        // Traverse through the chalk array to find the first index where k becomes less than the chalk required
        for (int i = 0; i < chalk.size(); ++i) {
            if (k < chalk[i]) {
                return i;
            }
            k -= chalk[i];
        }

        // The loop should return the correct index, and return -1 is only a safeguard (though it shouldn't be needed)
        return -1;
    }
};
