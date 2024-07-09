class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       if(s1.size()>s2.size()){
        return 0;
       }
      map<char,int> mp1;
       map<char,int> mp2;
      for(auto it:s1){
        mp1[it]++;
      }
      for(int i=0;i<s1.size();i++){
        mp2[s2[i]]++;
      }
      int i=0; int j=s1.length()-1;
      while(j<s2.size()){
        if(mp1==mp2) return true;
        mp2[s2[i]]--;
        if(mp2[s2[i]]==0) mp2.erase(s2[i]);
        i++;
        j++;
        mp2[s2[j]]++;
      }
      return false;
    }
};