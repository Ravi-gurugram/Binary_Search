class Solution {
public:
    int missingNumber(vector<int>& nums) {
          int sum=0, sum1=0;
int i=0;
          for(i;i<nums.size();i++){
             sum+=i ; sum1+=nums[i] ;
          }
          sum+=i ;
      int missing = sum- sum1 ;
      return missing ;


    }
};