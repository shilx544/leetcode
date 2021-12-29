class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> mp;
        int maxnum = 0;
        for(int i = 0; i < arr.size(); ++ i){
            mp[arr[i]] = mp[arr[i] - difference] + 1;
            maxnum = max(mp[arr[i]], maxnum);
        }
        return maxnum;
    }
};