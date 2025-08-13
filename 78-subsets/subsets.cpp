class Solution {
public:
    vector<vector<int>> ans;
    void printsubseq(int index,vector<int> &arr,vector<int> &ds){
      if(index==arr.size()){
       ans.push_back(ds);
      return;
       }
     ds.push_back(arr[index]);
     printsubseq(index+1,arr,ds);//take 
     ds.pop_back();
    printsubseq(index+1,arr,ds); //non take 
}
    vector<vector<int>> subsets(vector<int>& nums) {
        int index=0;
        vector<int>ds;
        printsubseq(index,nums,ds);
        return ans;
    }
};
// tc -> 0(2^n * n)
// sc-> 0(2^n * n)