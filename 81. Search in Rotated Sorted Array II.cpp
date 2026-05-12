// Time Complexity:
// Average Case  -> O(log n)
// Worst Case    -> O(n)   // due to duplicates

// Space Complexity:
// O(log n)   // recursive stack space
class Solution {
public:
    bool binsearch(vector<int>& nums, int target, int i, int j){
        if(i>j) return false;

        
        int mid=(i+j)/2;
        
        if(target==nums[mid])   return true;

        if(nums[i]==nums[j] && nums[i]==nums[mid]){
            return binsearch(nums,target,i+1,j-1);
        }

        if(nums[i]<=nums[mid]){
            if(target<nums[mid] && target >=nums[i])    return binsearch(nums,target,i,mid-1);
            else    return  binsearch(nums,target,mid+1,j);
        }
        else{
            if(target>nums[mid] && target <=nums[j])    return binsearch(nums,target,mid+1,j);
            else return binsearch(nums,target,i,mid-1);
        }
    }
    bool search(vector<int>& nums, int target) {
        return binsearch(nums,target,0,nums.size()-1);
    }
};
