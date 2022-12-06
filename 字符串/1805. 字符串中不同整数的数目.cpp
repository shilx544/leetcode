class Solution {
public:
    int numDifferentIntegers(string word) {
        string s;
        unordered_set<string> st;
        for (char c : word) {
            if (isdigit(c)) {
                s += c; 
            } else {
                if (s != "") st.insert(trim(s));
                s = "";
            }
        }
        
        if (s != "") st.insert(trim(s));
        
        return st.size();
    }
    
private:
    string trim(string &s) {
        int i = 0;
        while (i < s.size() - 1 && s[i] == '0') {
            i++; 
        }
        return s.substr(i);
    }
};