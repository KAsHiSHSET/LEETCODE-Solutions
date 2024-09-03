class Solution {
public:
    int getLucky(string s, int k) {
        string ab;
        int sum=0; 
        for(int i=0;i<s.length();i++){
            ab.append(to_string(s[i]-'a'+1));
        }
        for(int i=0;i<ab.length();i++){
            sum+=(ab[i]-'0');
        }
        k--;
       
        while(k!=0){
            int num=sum;
            sum=0;
            while(num!=0){
                int s=num%10;
                num=num/10;
                sum+=s;
            }
            k--;
        }
        
        return sum;
        
    }
};