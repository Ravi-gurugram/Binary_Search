class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int less = 0, equal = 0;
    for (int num : nums) {
        if (num < target) less++;
        else if (num == target) equal++;
    }

    vector<int> ans;
    for (int i = 0; i < equal; ++i)
        ans.push_back(less + i); // consecutive indices where target would appear

    return ans;
    }
};