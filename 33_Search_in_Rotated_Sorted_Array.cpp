//TC - O(log n)
//SC - O(log n)  - (due to recursion)
class Solution {
public:
    int binsearch(vector<int>& nums, int target, int i, int j){
        if(i>j) return -1;

        int mid=(i+j)/2;
        if(target==nums[mid])   return mid;
        if(nums[i]<=nums[mid]){
            if(target<nums[mid] && target >=nums[i])    return binsearch(nums,target,i,mid-1);
            else    return  binsearch(nums,target,mid+1,j);
        }
        else{
            if(target>nums[mid] && target <=nums[j])    return binsearch(nums,target,mid+1,j);
            else return binsearch(nums,target,i,mid-1);
        }
    }
    int search(vector<int>& nums, int target) {
        return binsearch(nums,target,0,nums.size()-1);
    }
};
