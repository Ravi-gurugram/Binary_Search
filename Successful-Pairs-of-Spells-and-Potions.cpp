class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m = potions.size();
        vector<int> res;

        for (int spell : spells) {
            long long min_potion = (success + spell - 1) / spell; // ceil division
            int idx = lower_bound(potions.begin(), potions.end(), min_potion) - potions.begin();
            res.push_back(m - idx);
        }

        return res;
    }
};
