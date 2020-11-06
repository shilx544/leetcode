class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](int a, int b){
            return make_pair(bitset<32>(a).count(), a) < make_pair(bitset<32>(b).count(), b);
        });
        return arr;
    }
};