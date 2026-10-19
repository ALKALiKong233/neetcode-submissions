class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<int,26>, vector<int>> mp;

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
        for ( auto obj : mp ) {
            vector<string> s;
            for ( auto j : obj.second ) {
                s.push_back(strs[j]);
            }
            res.push_back(s);
        }

        return res;
    }
};
