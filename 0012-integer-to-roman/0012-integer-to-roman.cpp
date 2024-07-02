class Solution {
public:
    string intToRoman(int num) {
        string ans="";
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hundredss[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string thousands[]={"","M","MM","MMM"};
         string th=thousands[num/1000];
         ans=ans+th;
         string h=hundredss[(num%1000)/100];
         ans=ans+h;
         string ten=tens[(num%100)/10];
         ans=ans+ten;
         string one= ones[num%10];
         ans=ans+one;
        return ans;
    }
};