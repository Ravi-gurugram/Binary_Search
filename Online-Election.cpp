class TopVotedCandidate {
private:
    vector<int> times;
    vector<int> leaders;

public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        this->times = times;
        unordered_map<int, int> voteCount;
        int leader = -1;
        int maxVotes = 0;

        for (int i = 0; i < persons.size(); ++i) {
            voteCount[persons[i]]++;

            if (voteCount[persons[i]] >= maxVotes) {
                // >= ensures recent person wins in case of tie
                leader = persons[i];
                maxVotes = voteCount[persons[i]];
            }

            leaders.push_back(leader);
        }
    }

    int q(int t) {
        int l = 0, r = times.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (times[mid] <= t)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return leaders[r];
    }
};


/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */