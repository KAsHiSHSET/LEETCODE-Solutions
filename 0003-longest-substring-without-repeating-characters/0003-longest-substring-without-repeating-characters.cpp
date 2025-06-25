class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        // int n = s.length();
        // unordered_map<char, int> hash;
        // int left = 0;
        // int right = 0;
        // int maxLen = 0;
        // while(right < n){
           
        //     if(hash.find(s[right])==hash.end() || hash[s[right]] < left){
        //         hash[s[right]] = right;
        //         maxLen = max(maxLen, right-left+1);
        //         right++;       
        //     }
        
        //     else{
        //         left = hash[s[right]]+1;
        //     }
        // }
        // return maxLen;
        if(s.length()==0) return 0;
        int left=0;
        int maxans=INT_MIN;
        unordered_set<int> st;
        for(int right=0;right< s.length();right++){

           if(st.find(s[right])!=st.end()){
            while(left<right&&st.find(s[right])!=st.end()){
                st.erase(s[left]);
                left++;
            }
           }
            st.insert(s[right]);
            maxans=max(maxans,right-left+1);
        }
        return maxans;
    }
};