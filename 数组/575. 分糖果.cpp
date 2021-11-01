class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> types(begin(candyType), end(candyType));  
        return min(types.size(), candyType.size() / 2);     
    }
};