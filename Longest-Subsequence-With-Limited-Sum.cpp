class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());  // Sort to take smallest numbers first
        int n = nums.size();

        // Build prefix sum array
        vector<int> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; ++i)
            prefix[i] = prefix[i - 1] + nums[i];

        vector<int> res;
        for (int q : queries) {
            // Use upper_bound to find how many elements we can take
            int count = upper_bound(prefix.begin(), prefix.end(), q) - prefix.begin();
            res.push_back(count);
        }

        return res;
    }
};
