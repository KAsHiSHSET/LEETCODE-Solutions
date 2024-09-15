class Solution {
public:
    vector<string> below_20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", 
                                "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", 
                                "Eighteen", "Nineteen"};
                                
    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
    vector<string> thousands = {"", "Thousand", "Million", "Billion"};
    
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        
        string result = "";
        int i = 0; // To track thousands, millions, etc.
        
        // Process each group of three digits
        while (num > 0) {
            if (num % 1000 != 0) { // Process current chunk if it's not zero
                result = helper(num % 1000) + thousands[i] + (result.empty() ? "" : " " + result);
            }
            num /= 1000; // Move to the next group of three digits
            i++;
        }
        while (result.back() == ' ') {
            result.pop_back();
        }
        return result;
    }
    
    // Helper function to convert numbers less than 1000
    string helper(int num) {
        if (num == 0) {
            return "";
        } else if (num < 20) {
            return below_20[num] + " ";
        } else if (num < 100) {
            return tens[num / 10] + (num % 10 ? " " + below_20[num % 10] : "") + " ";
        } else {
            return below_20[num / 100] + " Hundred " + (num % 100 ? helper(num % 100) : "");
        }
    }
};