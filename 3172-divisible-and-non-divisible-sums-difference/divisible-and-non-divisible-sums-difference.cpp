class Solution {
public:
    int differenceOfSums(int n, int m) {
        //total no of numbers divisible by m.
        int k = n/m;
        int totalsum= n*(n+1)/2;
        //sum of numbers which are divisible
       int num2= m * (k*(k+1)/2);
        //sum of numbers which are non divisible
       int num1= totalsum-num2;

        return num1-num2;
    }
};