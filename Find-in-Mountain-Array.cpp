/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        // Step 1: Find peak index
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                l = mid + 1;
            else
                r = mid;
        }
        int peak = l;

        // Step 2: Binary search on ascending part
        l = 0, r = peak;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int val = mountainArr.get(mid);
            if (val == target)
                return mid;
            else if (val < target)
                l = mid + 1;
            else
                r = mid - 1;
        }

        // Step 3: Binary search on descending part
        l = peak + 1, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int val = mountainArr.get(mid);
            if (val == target)
                return mid;
            else if (val > target)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return -1;
    }
};