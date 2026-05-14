// Time Complexity: O(m * log n)
// Space Complexity: O(1)
class Solution {
public:
    int max_ele(vector<vector<int>>& arr, int col) {
        int maxi = INT_MIN, index = -1;
        for (int i = 0; i < arr.size(); i++) {
            if (maxi < arr[i][col]) {
                maxi = max(maxi, arr[i][col]);
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& arr) {
        int i = 0, j = arr[0].size() - 1;
        while (i <= j) {
            int mid = (i + j) / 2;
            int maxindex = max_ele(arr, mid);
            if ((mid + 1 >= arr[0].size() ||
                 arr[maxindex][mid] > arr[maxindex][mid + 1]) &&
                (mid - 1 < 0 || arr[maxindex][mid] > arr[maxindex][mid - 1]))
                return {maxindex, mid};
            else if (arr[maxindex][mid] < arr[maxindex][mid + 1])
                i = mid + 1;
            else
                j = mid - 1;
        }
        return {-1, -1};
    }
};
