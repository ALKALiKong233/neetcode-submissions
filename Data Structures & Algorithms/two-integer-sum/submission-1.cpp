class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for ( int i = 0; i < nums.size(); ++i ) {
            int p = target - nums[i];
            if ( mp.count(p) ) {
                return {mp[p], i};
            } else {
                if ( !mp.count(nums[i]) ) {
                    mp[nums[i]] = i;
                }
            }
        }
        return {-1, -1};
    }
};
