class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size()-1;
        int n2 = num2.size()-1;
        int carry = 0;
        string result = "";
        while(carry == 1 || n1 >= 0 || n2 >= 0) {
            int x = n1 < 0 ? 0 : num1[n1--] - '0';
            int y = n2 < 0 ? 0 : num2[n2--] - '0';
            result += to_string((x+y+carry) % 10);
            carry = (x+y+carry)/10;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};