class Solution {
public:
    string answer;
    void decToBin(int n) {
        while (n) {
            if (n & 1 == 1)
                answer = "1" + answer;
            else
                answer = "0" + answer;

            n >>= 1;
        }
    }

    string convertDateToBinary(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));

        decToBin(day);
        answer="-"+answer;
        decToBin(month);
        answer="-"+answer;
        decToBin(year);

        return answer;
    }
};
