class Solution {
public:
    int beautySum(string s) {
     //aabcb -> {a,aa,aab,aabc,aabcb,a,ab,abc,abcb,b,bc,bcb,c,cb,b}->possible substring
     int max_freq;
    
     int min_freq;
     int total_beauty=0;
     for(int i=0;i<s.size();i++){
        unordered_map<char,int> mp;
     
        for(int j=i;j<s.size();j++){
          mp[s[j]]++; //increment the occurence of the character.
          max_freq= INT_MIN;
          min_freq= INT_MAX;
          for(auto p: mp){ 
          max_freq= max(max_freq,p.second);
          min_freq= min(min_freq,p.second);
          }
         total_beauty+=(max_freq-min_freq);
        }
        

     }
     return total_beauty;
       
    }
};