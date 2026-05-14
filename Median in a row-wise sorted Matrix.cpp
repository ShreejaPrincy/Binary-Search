// TC: O(row * log(col) * log(maxValue - minValue))
// SC: O(1)
class Solution {
  public:
    int upperb(vector<int>&arr,int target){
        int i=0;
        int j=arr.size()-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(arr[mid]<=target) i=mid+1;
            else    j=mid-1;
        }
        return i;
    }
    int number_smalls(vector<vector<int>> &mat,int num){
        int cnt=0;
        for(int i=0;i<mat.size();i++){
            int cntrow=upperb(mat[i],num);
            if(cntrow!=-1)  cnt+=cntrow;
        }
        return cnt;
    }
    int median(vector<vector<int>> &mat) {
        int row=mat.size();
        int col=mat[0].size();
        int i=INT_MAX,j=INT_MIN;
        for(int k=0;k<mat.size();k++){
            i=min(i,mat[k][0]);
            j=max(j,mat[k][col-1]);
        }
        while(i<=j){
            int mid=(i+j)/2;
            int num=mid;
            int smallequals=number_smalls(mat,num);
            if(smallequals<row*col/2+1)  i=mid+1;
            else    j=mid-1;
        }
        return i;
    }
};
