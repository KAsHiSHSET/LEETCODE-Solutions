
class Solution {
public:
    long long int hoursRequired(std::vector<int>& arr, int k) {
        int n = arr.size();
      long long int total_hours = 0;
        for (int i = 0; i < n; i++) {
            total_hours +=  ceil((double)arr[i]/(double)k); 
        }
        return total_hours;
    }

    int minEatingSpeed(std::vector<int>& piles, int h) {
        int low = 1;  // Minimum possible eating speed
        int high = *max_element(piles.begin(), piles.end());  // Maximum pile size
        int result = 31;  // Initialize result with the highest possible speed

        while (low <= high) {
            int mid = (low + high) / 2;
            if (hoursRequired(piles, mid) <= h) {
                result = mid;  // This is a valid speed, try to find a smaller one
                high = mid - 1;
            } else {
                low = mid + 1;  // Speed too slow, increase it
            }
        }

        return result;
    }
};
