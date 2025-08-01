class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> ans;
        vector<int> tails;  // tails[i] = smallest ending value of length i+1

        for (int x : obstacles) {
            int idx = upper_bound(tails.begin(), tails.end(), x) - tails.begin();

            if (idx == tails.size()) tails.push_back(x);
            else tails[idx] = x;

            ans.push_back(idx + 1); // +1 because index starts at 0
        }

        return ans;
    }
};
