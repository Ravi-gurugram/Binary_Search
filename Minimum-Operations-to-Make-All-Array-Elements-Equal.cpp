class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        // Prefix sum
        vector<long long> prefix(n+1, 0);
        for (int i = 0; i < n; ++i)
            prefix[i+1] = prefix[i] + nums[i];

        vector<long long> ans;

        for (int q : queries) {
            int idx = upper_bound(nums.begin(), nums.end(), q) - nums.begin();

            // Elements less than or equal to q
            long long left = (long long)q * idx - prefix[idx];

            // Elements greater than q
            long long right = (prefix[n] - prefix[idx]) - (long long)q * (n - idx);

            ans.push_back(left + right);
        }

        return ans;
    }
};
