class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.length()-1;
        int j=b.length()-1;
        int carry=0;
        string ans="";
        while(i>=0||j>=0||carry>0){
            int sum=carry;
            if(i>=0){
                sum=sum+a[i]-'0';
                i--;
            }
            if(j>=0){
                sum=sum+b[j]-'0';
                j--;
            }
            ans=ans+to_string(sum%2);
            carry=sum/2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};