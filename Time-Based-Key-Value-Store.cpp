class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;

    // O(1) insert
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    // O(log n) search using binary search
    string get(string key, int timestamp) {
        if (!mp.count(key)) return "";

        const auto& vec = mp[key];
        int low = 0, high = vec.size() - 1;
        string res = "";

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (vec[mid].first <= timestamp) {
                res = vec[mid].second;  // candidate value
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return res;
    }
};


/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */