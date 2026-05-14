//Time Complexity: O(n log(stalls[n-1] - stalls[0]))
//O(n * log(maxDistance))
//Space Complexity: O(1)
class Solution {
  public:
    bool possible(vector<int> &stalls, int k, int mid){
        int pos=stalls[0]+mid;
        k--;
        for(int num:stalls){
            if(num>=pos){
                k--;
                pos=num+mid;
            }
        }
        return (k>0)?0:1;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(),stalls.end());
        int i=1;
        int j=stalls.back()-stalls.front();
        while(i<=j){
            int mid=(i+j)/2;
            bool pos=possible(stalls,k,mid);
            if(pos==1)  i=mid+1;
            else    j=mid-1;
        }
        return j;
    }
};
