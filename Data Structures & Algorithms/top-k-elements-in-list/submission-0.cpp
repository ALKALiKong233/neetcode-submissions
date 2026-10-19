class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, unordered_set<int>> bucket;
        vector<int> freq(2001);
        for (const auto& i : nums) {
            freq[i + 1000]++;
            bucket[freq[i + 1000]].insert(i);
            if (freq[i + 1000] != 1) bucket[freq[i + 1000] - 1].erase(i);
        }
        vector<int> ans;

        for (int f = nums.size(); f >= 1; f--) {
            if (bucket.find(f) == bucket.end()) continue;

            for (int x : bucket[f]) {
                ans.push_back(x);

                if (ans.size() == k) return ans;
            }
        }

        return ans;
    }
};
