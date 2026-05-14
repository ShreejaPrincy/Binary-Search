//top-right staircase traversal
// TC: O(row + col)
// SC: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int row = matrix.size();
        int col = matrix[0].size();

        int i = 0;
        int j = col - 1;

        while(i < row && j >= 0) {

            int num = matrix[i][j];

            if(num == target)
                return true;

            else if(num < target)
                i++;

            else
                j--;
        }

        return false;
    }
};
