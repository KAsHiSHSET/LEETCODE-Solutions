class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
       int five=0;
       int ten=0;
     
       for(int i=0;i<bills.size();i++){
            if(bills[i]==5) five=five+1;
            else if(bills[i]==10){
                ten =ten+1;
                if(five!=0){
                    five= five-1;
                }
                else{
                    //i cant return anything as i dont have 5
                    return false;
                }
            }
            else{
               
                if(ten && five){
                  ten=ten-1;
                  five=five-1;

                }
                else if(five>=3){
                    five=five-3;
                }
                else{
                    return false;
                }
            }
       }
       return true;
    }
};