class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> vec = nums;
        sort(vec.begin(),vec.end());

        int hash[101];
        for (int i = vec.size()-1; i >= 0; --i) {
            hash[vec[i]] = i;
        }

        for (int i = 0; i < nums.size(); ++i) {
            vec[i] = hash[nums[i]];
        }
        return vec;
    }
};