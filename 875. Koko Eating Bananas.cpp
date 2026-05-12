//TC - O(n * log(max(piles)))
//SC - O(1)
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());

        while(low<=high){
            int mid=(low+high)/2;
            long long ht=0;
            for(int num:piles){
                ht += (long long)(num + mid - 1) / mid;
            }
            if(ht<=h)    high=mid-1;
            else    low=mid+1;
        }
        return low;
    }
};
