class Solution {
public:
    int search(vector<int>& nums, int target) {
         int s=0, e=nums.size()-1 , mid;
         while(s<=e){
             mid= s+ (e-s)/2 ;
            if(nums[mid]==target)
                { return mid ;break ; }
            else if(target>nums[mid])
                s= mid+1 ;
            else
               e= mid-1 ;
         }
        return target==nums[mid]  ? mid : -1 ;
    }
};