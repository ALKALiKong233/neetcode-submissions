class Solution {
public:
    // Combined Hash
    struct ArrayHash {
        size_t operator()(const array<int, 26>& arr) const {
            size_t h = 0;

            for (int x : arr) {
                size_t v = hash<int>{}(x);
                h ^= v + 0x9e3779b97f4a7c15ULL
                     + (h << 6) + (h >> 2);
            }

            return h;
        }
    };

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<array<int,26>, vector<int>, ArrayHash> mp;

        for ( int i = 0; i < strs.size(); i++ ) {
            int len = strs[i].length();
            int sum = 0;
            array<int, 26> arr{};
            for ( int j = 0; j < len; j++ ) {
                arr[strs[i][j]-'a']++;
            }
            mp[arr].push_back(i);
        }

        vector<vector<string>> res;
        for ( const auto& obj : mp ) {
            vector<string> s;
            for ( const auto& j : obj.second ) {
                s.push_back(strs[j]);
            }
            res.push_back(s);
        }

        return res;
    }
};
