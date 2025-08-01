class Solution {
public:
    bool canAllocate(vector<int>& candies, long long k, long long x) {
        long long children = 0;
        for (int c : candies) {
            children += (c / x);
            if (children >= k) return true; // early exit
        }
        return false;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long low = 1;
        long long high = *max_element(candies.begin(), candies.end());
        long long ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (canAllocate(candies, k, mid)) {
                ans = mid;       // mid is possible
                low = mid + 1;
            } else {
                high = mid - 1;  // mid too high, try lower
            }
        }

        return ans; // will be 0 if nothing worked
    }
};
