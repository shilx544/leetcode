class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        string result = "";
        int m = num1.size();
        int n = num2.size();
        int add = 0;
        for (int i = 0; i < m; ++i) {
            int multiple1 = num1[i]-'0';
            cout << "multiple1:" << multiple1 << endl;
            for (int j = 0; j < n; ++j) {
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