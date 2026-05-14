// Time Complexity: O(log(row * col))
// Space Complexity: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size(),col=matrix[0].size();
        int i=0,j=row*col-1;

        while(i<=j){
            int mid=(i+j)/2;
            int num=matrix[mid/col][mid%col];
            if(target==num) return true;
            else if(target>num) i=mid+1;
            else    j=mid-1;
        }
        return false;
    }
};
