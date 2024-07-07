class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drink=0; int empty=0;
        while(numBottles!=0){
            drink=drink+numBottles;
            empty=empty+numBottles;
            numBottles=empty/numExchange;
            empty=empty%numExchange;
            
        }
        return drink;
    }
};