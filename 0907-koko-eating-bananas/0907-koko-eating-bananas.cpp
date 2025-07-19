
class Solution {
public:
    long long int hoursRequired(std::vector<int>& arr, int k) {
        int n = arr.size();
      long long int total_hours = 0;
      //calcukate fr the all emelent in the array .
        for (int i = 0; i < n; i++) {

            total_hours +=  ceil((double)arr[i]/(double)k); 
        }
        return total_hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;  
        int high = *max_element(piles.begin(), piles.end());  
        int result = high; 

        while (low <= high) {
            int mid = (low + high) / 2;
            if (hoursRequired(piles, mid) <= h) {
                result = mid;  
                high = mid - 1;
            } else {
                low = mid + 1; 
            }
        }

        return low;
    }
};
//tc - 0(N) * 0( log2 (maxelement))