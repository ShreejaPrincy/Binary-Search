// Time Complexity: O(n * log(m))
// Space Complexity: O(1)
class Solution {
  public:
    int upperb(vector<int>&arr){
        int i=0;
        int j=arr.size()-1;
        while(i<=j){
            int mid = (i+j)/2;
            if(arr[mid]<1)   i=mid+1;
            else    j=mid-1;
        }
        return (i<arr.size())?i:-1;
    }
    int rowWithMax1s(vector<vector<int>> &arr) {
        int idx=INT_MAX;
        int row=-1;
        for(int i=0;i<arr.size();i++){
            int index=upperb(arr[i]);
            if(index!=-1&&idx>index){
                row=i;
                idx=index;
            }
        }
        return row;
    }
};
