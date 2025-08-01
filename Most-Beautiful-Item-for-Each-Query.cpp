class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // Step 1: Sort items by price
        sort(items.begin(), items.end());

        // Step 2: Prefix max array
        vector<pair<int, int>> priceBeauty;  // {price, max_beauty_so_far}
        int maxBeauty = 0;
        for (auto& item : items) {
            maxBeauty = max(maxBeauty, item[1]);
            priceBeauty.push_back({item[0], maxBeauty});
        }

        // Step 3: For each query, binary search
        vector<int> res;
        for (int q : queries) {
            int l = 0, r = priceBeauty.size() - 1, ans = 0;
            while (l <= r) {
                int m = l + (r - l) / 2;
                if (priceBeauty[m].first <= q) {
                    ans = priceBeauty[m].second;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};
