class Solution {
public:
    
        int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int x = 0; x <= n; x++) {
            // find first index where nums[i] >= x
            int idx = lower_bound(nums.begin(), nums.end(), x) - nums.begin();
            int count = n - idx;
            if (count == x)
                return x;
        }
        return -1;
    }
};