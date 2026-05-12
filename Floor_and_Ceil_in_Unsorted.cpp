// TC - O(n log n)
// SC - O(log n)

class Solution {
public:

    int upperb(vector<int>& arr, int x, int i, int j) {
        if(i > j) return i;

        int mid = (i + j) / 2;

        if(arr[mid] < x)
            return upperb(arr, x, mid + 1, j);
        else
            return upperb(arr, x, i, mid - 1);
    }

    int lowerbound(vector<int>& arr, int x, int i, int j) {
        if(i > j) return j;

        int mid = (i + j) / 2;

        if(arr[mid] <= x)
            return lowerbound(arr, x, mid + 1, j);
        else
            return lowerbound(arr, x, i, mid - 1);
    }

    vector<int> getFloorAndCeil(int x, vector<int>& arr) {

        sort(arr.begin(), arr.end());

        int f1 = lowerbound(arr, x, 0, arr.size() - 1);
        int f2 = upperb(arr, x, 0, arr.size() - 1);

        int firstelement = (f1 >= 0) ? arr[f1] : -1;
        int secondelement = (f2 < arr.size()) ? arr[f2] : -1;

        return {firstelement, secondelement};
    }
};
