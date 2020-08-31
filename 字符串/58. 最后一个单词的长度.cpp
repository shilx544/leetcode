
std::string& trim(std::string &s)
{
    if (s.empty())
    {
        return s;
    }

    s.erase(0,s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
    return s;
}

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) return 0;
        s = trim(s);
        reverse(s.begin(),s.end());
        return s.find(" ") == string::npos? s.size(): s.find(" ");
    }
};