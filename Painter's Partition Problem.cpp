//Time Complexity: O(n * log(sum(boards)))
//Space Complexity: O(1)
bool possible(vector<int> &nums, int k, int mid){
    int painter=1, poss=0;
    for(int n:nums){
        if(poss+n<=mid) poss+=n;
        else{
            poss=n;
            painter++;
        }
    }
    return painter<=k;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    int i=*max_element(boards.begin(),boards.end());
    int j=0;
    for(int n:boards){
        j+=n;
    }
    while(i<=j){
        int mid=(i+j)/2;
        bool poss=possible(boards,k,mid);
        if(poss)    j=mid-1;
        else    i=mid+1;
    }
    return i;
}
