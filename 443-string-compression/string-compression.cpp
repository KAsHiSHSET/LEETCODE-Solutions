class Solution {
public:
//tc -0(n)
//sc-0(1)
    int compress(vector<char>& chars) {
    //   int n=chars.size();
    //   int i=0;
    //   int index=0;
    //   while(i<n){
    //     char character=chars[i];
    //     int count=0;
    //     while(i<n&&chars[i]==character){
    //         count++;
    //         i++;
    //     }
    //     chars[index++]=character;
    //     if(count>1){
    //         string c=to_string(count);
    //         for(auto ch:c){
    //           chars[index++]=ch;
    //         }
    //     }
    //   }
    //   return index;
    // }

    int i=0;
    int index=0;
    int n=chars.size();
    int cnt;
    while(i<n){
        char character= chars[i];
        cnt=0;
        while(i< n && character==chars[i]){
            cnt++;
            i++;
        }
        chars[index++]=character;
        if(cnt>1){
            string output= to_string(cnt);
            for(auto ch: output){
                 chars[index++]=ch;
            }
        }
    }
    return index;
    }
};
