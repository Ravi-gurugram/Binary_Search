class Solution {
public:
    bool canEatAll(vector<int>& piles, int h, int speed) {
        long long totalTime = 0;
        for (int pile : piles) {
            totalTime += (pile + speed - 1) / speed;  // Ceil(pile / speed)
        }
        return totalTime <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canEatAll(piles, h, mid)) {
                ans = mid;         // try smaller speed
                high = mid - 1;
            } else {
                low = mid + 1;     // speed too slow
            }
        }

        return ans;
    }
};
