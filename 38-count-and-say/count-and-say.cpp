class Solution {
public:
 //tc - 0(2^n)
 //sc -0(2^n) + 0(n)
    string sayfunction(int n){
        if(n==1){
            return "1";
        }
        string result="";
        string say = sayfunction(n-1);
        //har step par aake processing 
        for(int i=0;i<say.length();i++){
            char ch= say[i];
            int count=1;
            while(i<say.length()-1&&say[i]==say[i+1]){
              count++;
              i++;
            }
            result+= to_string(count)+ string(1,ch);

        }
        return result;    
    }
    string countAndSay(int n) {
        return sayfunction(n);
    }
};