class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> output;
        for(int i=0;i<nums1.size();i++){
            int element=nums1[i];
            auto it= find(nums2.begin(),nums2.end(),element);
            int index= it- nums2.begin();
            bool found=false;
            for(int j=index;j<nums2.size();j++){
                if(element<nums2[j]){
                output.push_back(nums2[j]);
                found=true;
                break;
                    
                }
            }
            if(!found){
                output.push_back(-1);
            }

        }
        return output;
    }
};