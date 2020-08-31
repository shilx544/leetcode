class Solution {
public:
    int findLUSlength(string a, string b) {

        if(a.length()!=b.length())
            return max(a.length(),b.length());

        else{

            if(a.compare(b)==0)
                return -1;
            else
                return a.length();
        }

        return 0;

    }
};