class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        sort(folder.begin(), folder.end());
       ans.push_back(folder[0]);
        for(int i=1;i<folder.size();i++){
          string bck=ans.back();
          bck.push_back('/');
           if(folder[i].compare(0, bck.size(), bck) != 0) {
                // If not a subfolder, add to result
                ans.push_back(folder[i]);
            }
        }
        return ans;
    }
};