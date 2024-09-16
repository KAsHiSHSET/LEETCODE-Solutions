class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> vec;
        for(auto timePoint:timePoints){
            int h=(timePoint[0]-'0')*10+(timePoint[1]-'0');
            int m=(timePoint[3]-'0')*10+(timePoint[4]-'0');
            int element=h*60+m;
            vec.push_back(element);
        }
        sort(vec.begin(),vec.end());
        int mini=INT_MAX;
        for(int i=1;i<vec.size();i++){
            mini=min(mini,vec[i]-vec[i-1]);
        }
        return min(mini,1440+vec[0]-vec.back());
    }
};