class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
      int n=hand.size();
      if(n%groupSize!=0) return false; 
      sort(hand.begin(),hand.end());
      while (!hand.empty()) {
        int start = hand[0];
        for (int i = 0; i < groupSize; ++i) {
            auto it = find(hand.begin(), hand.end(), start + i);
            if (it == hand.end()) {
                return false;
            }
            hand.erase(it);
        }
    }

    return true;
      
    }
};