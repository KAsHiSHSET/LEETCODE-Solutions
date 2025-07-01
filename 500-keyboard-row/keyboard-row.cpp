class Solution {
public:
    //sc - O(N) auxiliary space for the answer, O(1) extra
    //tc- total work = O(M · R) = O(M) because R is a tiny constant.
vector<string> findWords(vector<string>& words) 
{
    vector<string> result;
    int n = words.size();
    for (int i = 0; i < n; i++) {
        if (IsInRowOne(words[i]) || IsInRowTwo(words[i]) || IsInRowThree(words[i])) {
            result.push_back(words[i]);
        }
    }
    return result;
}
bool IsInRowOne(string word) {
    string row1 = "qwertyuiopQWERTYUIOP";
    int n = word.size();
    for (int i = 0; i < n; i++) {
        if (row1.find(word[i]) == string::npos) {
            return false;
        }
    }
    return true;
}
bool IsInRowTwo(string word) {
    string row2 = "asdfghjklASDFGHJKL";
    int n = word.size();
    for (int i = 0; i < n; i++) {
        if (row2.find(word[i]) == string::npos) {
            return false;
        }
    }
    return true;
}
bool IsInRowThree(string word) {
    string row3 = "zxcvbnmZXCVBNM";
    int n = word.size();
    for (int i = 0; i < n; i++) {
        if (row3.find(word[i]) == string::npos) {
            return false;
        }
    }
    return true;
}
};