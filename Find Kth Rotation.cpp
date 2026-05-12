// TC - O(log n)
// SC - O(1)
class Solution {
  public:
    int findKRotation(vector<int> &nums) {

        int i = 0, j = nums.size() - 1;

        while(i < j) {

            int mid = i + (j - i) / 2;

            if(nums[mid] > nums[j]) {
                i = mid + 1;
            }
            else {
                j = mid;
            }
        }

        return i;

    }
};
