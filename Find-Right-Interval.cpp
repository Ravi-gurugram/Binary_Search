class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
    int n = intervals.size();
    vector<pair<int, int>> starts;  // {start, index}
    
    for (int i = 0; i < n; ++i) {
        starts.push_back({intervals[i][0], i});
    }
    
    // Sort based on start time
    sort(starts.begin(), starts.end());

    vector<int> result(n, -1);
    for (int i = 0; i < n; ++i) {
        int target = intervals[i][1];  // end of current interval

        // Binary search to find smallest start >= target
        int lo = 0, hi = n - 1, pos = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (starts[mid].first >= target) {
                pos = starts[mid].second;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        result[i] = pos;
    }
    return result;
}

};