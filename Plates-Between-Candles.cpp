class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
         int n = s.size();
        vector<int> prefix(n, 0);
        vector<int> left(n, -1), right(n, -1);

        // Step 1: Build prefix sum of plates
        prefix[0] = (s[0] == '*') ? 1 : 0;
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i-1] + (s[i] == '*' ? 1 : 0);

        // Step 2: Build nearest left candle
        for (int i = 0, last = -1; i < n; i++) {
            if (s[i] == '|') last = i;
            left[i] = last;
        }

        // Step 3: Build nearest right candle
        for (int i = n-1, last = -1; i >= 0; i--) {
            if (s[i] == '|') last = i;
            right[i] = last;
        }

        // Step 4: Process queries
        vector<int> ans;
        for (auto& q : queries) {
            int l = right[q[0]];   // nearest candle on or after left
            int r = left[q[1]];    // nearest candle on or before right
            if (l == -1 || r == -1 || l >= r) {
                ans.push_back(0);
            } else {
                ans.push_back(prefix[r] - prefix[l]);
            }
        }

        return ans;
    }
};