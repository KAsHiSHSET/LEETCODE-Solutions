class Solution {
public:
    int candy(vector<int>& ratings) {
        int n= ratings.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        left[0]=1;
        right[n-1]=1;
        //filling the left array
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
            //left neighbour is smaller which means rating of current is greater
            //so it will get greater than the left neigbhour
            left[i]=left[i-1]+1;


        }
        else{
            // if the left neighbour is greater than left[i]=1
            left[i]=1;
        }}

        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                right[i]=right[i+1]+1;
            }
            else{
                right[i]=1;
            }
        }
        int sum=0;
        for(int i=0;i<n;i++){
             sum+=max(left[i],right[i]);
        }
        return sum;
    }
};