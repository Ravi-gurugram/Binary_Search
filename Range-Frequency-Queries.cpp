class RangeFreqQuery {
    unordered_map<int, vector<int>> positions;

public:
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); ++i) {
            positions[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int value) {
        if (!positions.count(value)) return 0;
        const vector<int>& pos = positions[value];

        auto lo = lower_bound(pos.begin(), pos.end(), left);
        auto hi = upper_bound(pos.begin(), pos.end(), right);

        return hi - lo;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */