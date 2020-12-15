class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        unordered_map<string,vector<string>>mp;
        for(const auto& str:strs){
            auto key=str;
            sort(key.begin(),key.end());//key是排好序的一个单词
            mp[key].push_back(str);//value是排好序的单词对应的strs多个未排序的str集合
        }
        for(const auto&m:mp){
            res.push_back(m.second);//把value集合放进res
        }
        return res;
    }
};