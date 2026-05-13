//Approach - 1
//Time: O(n)
//Space: O(1)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for(int num:arr){
            if(num<=k)  k++;
            else    break;
        }
        return k;
    }
};

//Approach - 2
//Time: O(log n)
//Space: O(1)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i=0;
        int j=arr.size()-1;
        while(i<=j){
            int mid=(i+j)/2;
            int missing=arr[mid]-(mid+1);

            if(missing<k) i=mid+1;
            else    j=mid-1;
        }
        return i+k;
    }
};
