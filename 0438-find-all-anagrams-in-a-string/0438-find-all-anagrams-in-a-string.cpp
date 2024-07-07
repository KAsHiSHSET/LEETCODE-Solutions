class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(p.length()>s.length()){
            return ans;
        }
        int plen=p.length();//3
        int slen=s.length();//10
        vector<int> v1(26,0);
        vector<int> v2(26,0);
        int left=0;
        int right=0;
        for(int i=0;i<plen;i++){
            v1[s[i]-'a']++;
            v2[p[i]-'a']++;
            right++;//3

        }
        right--;//2
        for(int i=right;i<slen;i++){
            if(v1==v2) ans.push_back(left);
            right++;
            if(right!=slen){
                v1[s[right]-'a']++;
            }
            v1[s[left]-'a']--;
            left++;
        }
        return ans;
    }
};