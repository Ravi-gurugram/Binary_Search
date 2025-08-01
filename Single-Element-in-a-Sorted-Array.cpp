class Solution {
public:
    
        int singleNonDuplicate(vector<int>& nums) {
    int low = 0, high = nums.size() - 2;  // last valid mid is at n-2

    while (low <= high) {
        int mid = (low + high) / 2;

        // Check if we are on the correct side using index parity
        if (nums[mid] == nums[mid ^ 1]) {
            // ^1 flips last bit: mid ^ 1 => mid+1 if even, mid-1 if odd
            // Still follows pair pattern, move right
            low = mid + 1;
        } else {
            // Break in pattern, move left
            high = mid - 1;
        }
    }

    return nums[low];  // single element is at `low`
}

    
};