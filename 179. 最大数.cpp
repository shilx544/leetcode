bool cmp(int a, int b) {
    string sa = to_string(a);
    string sb = to_string(b);
    return sa + sb > sb + sa;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string result = "";
        sort(nums.begin(),nums.end(),cmp);
        for(int i : nums) {
            result += to_string(i);
        }
        // 去除掉前面的0元素
        while (result.size() > 1 && result[0] == '0') {
            result.erase(result.begin());
        }
        return result;
    }
};