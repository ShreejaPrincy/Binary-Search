//Time: O(n log(sum(weights)))
//Space: O(1)
class Solution {
public:
    int totaldays(vector<int>& nums, int weight){
        int capacity=weight;
        int tday=1;
        for(int num:nums){
            if(capacity>=num)   capacity-=num;
            else{
                tday++;
                capacity=weight-num;
            }
        }
        return tday;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int i = *max_element(weights.begin(), weights.end());

        int sum=0;
        for(int num:weights)   sum+=num;

        int j=sum;
        while(i<j){
            int mid=(i+j)/2;
            int tday=totaldays(weights,mid);
            if(tday>days)   i=mid+1;
            else    j=mid;
        }
        return j;
    }
};
