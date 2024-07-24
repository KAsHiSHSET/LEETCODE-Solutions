class Solution {
public:
vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
vector<vector<int>> ans;
priority_queue<pair<int, pair<int, int>>> pq; // max-heap to store the k smallest pairs
    for (int i = 0; i < nums1.size(); i++) {
        for (int j = 0; j <nums2.size(); j++) {
            int sum = nums1[i] + nums2[j];

           
            if (pq.size() < k)
                pq.push({sum, {nums1[i], nums2[j]}});
            else if (sum < pq.top().first) {
               
                pq.pop();
                pq.push({sum, {nums1[i], nums2[j]}});
            } else if (sum >= pq.top().first) {
                
                break;
            }
        }
    }

    // Retrieve the k smallest pairs from the priority queue and store them in the answer vector
    while (!pq.empty()) {
        ans.push_back({pq.top().second.first, pq.top().second.second});
        pq.pop();
    }

    return ans;
}
};