class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        for (int i = size-1; i >= 0; i--) {
            if (digits[i] != 9) {
                digits[i] += 1;
                return digits;
            } else if (i != 0){
                digits[i] = 0;
                continue;
            } else {
                digits[i] = 0;
                vector<int> digits2;
                digits2.push_back(1);
                for (auto j:digits) {
                    digits2.push_back(j);
                }
                return digits2;
            }
        }
        return digits;
    }
};