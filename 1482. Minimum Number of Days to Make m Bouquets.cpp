//Time Complexity: O(n log(max(bloomDay)))
//Space Complexity: O(1)
class Solution {
public:
    int bloom(vector<int>&arr,int k,int mid){
        int cnt=0,ans=0;
        for(int num:arr){
            if(num<=mid)   cnt++;
            else{
                ans+=cnt/k;
                cnt=0;
            }
        }
        ans+=cnt/k;
        return ans;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(1LL*m*k>bloomDay.size())    return -1;

        int minday=1;
        int maxday=*max_element(bloomDay.begin(),bloomDay.end());

        while(minday<=maxday){

            int mid=(minday+maxday)/2;
            int bouqets=bloom(bloomDay,k,mid);
            if(bouqets>=m)   maxday=mid-1;
            else    minday=mid+1;  
        }
        return minday;
    }
};
