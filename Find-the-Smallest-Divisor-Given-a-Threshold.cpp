class Solution {
public:
    int computeSum(vector<int>& nums, int divisor) {
        int total = 0;
        for (int num : nums) {
            total += (num + divisor - 1) / divisor;  // ceil(num / divisor)
        }
        return total;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int answer = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int total = computeSum(nums, mid);

            if (total <= threshold) {
                answer = mid;
                high = mid - 1;  // Try smaller divisor
            } else {
                low = mid + 1;   // Divisor too small
            }
        }

        return answer;
    }
};
