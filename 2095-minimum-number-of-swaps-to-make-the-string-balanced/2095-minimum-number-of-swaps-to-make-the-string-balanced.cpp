class Solution {
public:
    int minSwaps(string s) {
        int size=0;
        for(auto ch :s){
            if(ch=='['){
                size++;
            }
            else if(size>0){
                size--;
            }
        }
        return (size+1)/2;
    }
};