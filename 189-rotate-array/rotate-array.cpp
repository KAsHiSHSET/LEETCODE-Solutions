class Solution {
public:
    void rotate(vector<int>& vec, int k) {
      int n=vec.size();
      k=k%n;

     reverse(vec.begin(),vec.end());
    //  reverse(vec.begin(),vec.begin()+k);
     reverse(vec.begin()+k,vec.end());
       reverse(vec.begin(),vec.begin()+k);
   
     



    }
    
    };