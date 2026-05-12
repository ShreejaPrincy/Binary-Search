// TC - O(log m * n)
// SC - O(1)
class Solution {
  public:
    int nthRoot(int n, int m) {
        int i=0;
        int j=m;
        while(i<=j){
            int mid=(i+j)/2;
            
            long long nth=1;
            int n1=n;
            while(n1>0){
                nth=nth*mid*1LL;
                n1--;
                if(nth>m)  break;
            }
            if(nth==m)   return mid;
            else if(nth>m)   j=mid-1;
            else    i=mid+1;
        }
        return -1;
    }
};
