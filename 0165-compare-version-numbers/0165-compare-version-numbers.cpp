class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0;
        int j=0;
        int n1=version1.length();
        int n2=version2.length();
         
        while(i<n1||j<n2){
          long int x1=0;
            long int x2=0;
            while(i<n1&&version1[i]!='.') 
            {x1=10*x1+version1[i]-'0'; i++;}
             while(j<n2&&version2[j]!='.') 
             {x2=10*x2+version2[j]-'0'; j++;}
             i++;
             j++;
            if(x1<x2)
               return -1;
            else if(x2<x1)
               return 1; 
            
        }
        
                return 0;

    }
};