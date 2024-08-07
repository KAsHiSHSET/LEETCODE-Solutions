class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count=0;
       for(auto &details:details){
        string age;
        // age+=details[11];
        // age+=details[12];
        age={details[11],details[12]};
        if(age>"60"){
            count++;
        }

       }
        return count;
    }
};