class Solution {
public:
    string addString(string& nums1, string& nums2) {
        int i = nums1.size()-1, j = nums2.size()-2, add = 0;
        string result
    }
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        string result = "";
        int m = num1.size();
        int n = num2.size();
        int add = 0;
        for (int i = m-1; i >= 0; --i) {
            int multiple1 = num1[i]-'0';
            cout << "multiple1:" << multiple1 << endl;
            for (int j = n-1; j >= 0; --j) {
                int multiple2 = num2[j]-'0';
                int tmp = multiple1 * multiple2 + add;
                add = tmp/10;
                result += to_string(tmp%10);
                cout << "multiple2:" << multiple2 
                     << ",tmp:" << tmp 
                     << ",add:" << add 
                     << ",result:" << result << endl;
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};