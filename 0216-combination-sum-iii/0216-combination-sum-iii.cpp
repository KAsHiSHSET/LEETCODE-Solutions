class Solution {
public:
//TC = O(C(9, k) × k)
// sc- O(k + C(9, k) × k)
//  O(k) for the call stack.
//  store O(C(9, k)) combinations, each of length k.
    void helper(vector<vector<int>> &ans,vector<int> &step,int start,int k,int n){
        //if the sum is 0 , and there are already k elements that sum upto n, then add in result finally
        if(k==0 && n==0){
            ans.push_back(step);
            return ;
        }
        else{
            for(int i=start;i<=9;i++){
            // if(n<0&&k<0) break; //prune
            if(n>0&&k>0){
                
                step.push_back(i);
                helper(ans,step,i+1,k-1,n-i);
                step.pop_back();}
                
            }
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
       vector<vector<int>> ans;
       vector<int> step;
        helper(ans,step,1,k,n); 
        return ans;
    }
};