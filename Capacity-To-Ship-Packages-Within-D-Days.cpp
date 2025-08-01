class Solution {
public:
    // Helper function to check if capacity 'cap' can ship within 'days'
    bool canShip(vector<int>& weights, int days, int cap) {
        int dayCount = 1; // start with day 1
        int currentLoad = 0;

        for (int w : weights) {
            if (currentLoad + w > cap) {
                dayCount++;         // need new day
                currentLoad = 0;
            }
            currentLoad += w;
        }

        return dayCount <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());  // Minimum possible capacity
        int high = accumulate(weights.begin(), weights.end(), 0); // Maximum possible capacity
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canShip(weights, days, mid)) {
                ans = mid;         // valid capacity, try smaller
                high = mid - 1;
            } else {
                low = mid + 1;     // capacity too small, increase it
            }
        }

        return ans;
    }
};
