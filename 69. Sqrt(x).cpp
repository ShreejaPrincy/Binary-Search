//// TC - O(log x)
// SC - O(1)
class Solution {
public:
    int mySqrt(int x) {
        int i=0;
        int j=x;
        while(i<=j){
            int mid=(i+j)/2;
            long long sq=1LL*mid*mid;
            if(sq==x)  return mid;
            else if(sq<x)  i=mid+1;
            else    j=mid-1;
        }
        return j;
    }
};
