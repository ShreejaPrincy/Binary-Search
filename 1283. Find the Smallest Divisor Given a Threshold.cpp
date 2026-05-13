//Time: O(n log(max(nums)))
//Space: O(1)
class Solution {
public:
    int summation(vector<int>& nums,int divisor){
        int sum=0;
        for(int num:nums){
            sum+=(num+divisor-1)/divisor;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int i=1;
        int j=*max_element(nums.begin(),nums.end());
        while(i<j){
            int mid=(i+j)/2;
            int sum=summation(nums,mid);
            if(sum>threshold)   i=mid+1;
            else    j=mid;
        }
        return i;
    }
};
