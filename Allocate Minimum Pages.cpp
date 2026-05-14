//Time : O(n log(sum(arr)))
//Space Complexity: O(1)
class Solution {
  public:
    bool allocatepages(vector<int> &arr, int k, int mid){
        int stu=1;
        int pg=0;
        for(int num : arr){
            if(pg + num <= mid) pg+=num;
            else{
                pg=num;
                stu++;
            }
        }
        return stu<=k;
    }
    int findPages(vector<int> &arr, int k) {
        if(k>arr.size())    return -1;
        int i=*max_element(arr.begin(),arr.end());
        int j=0;
        for(int num:arr){
            j+=num;
        }
        while(i<=j){
            int mid=(i+j)/2;
            bool allo=allocatepages(arr,k,mid);
            
            if(allo)    j=mid-1;
            else    i=mid+1;
        }
        return i;
    }
};
