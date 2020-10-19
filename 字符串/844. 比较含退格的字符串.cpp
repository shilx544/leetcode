class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string S1, T1 = "";

        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == '#'){
                S1 = S1.substr(0, S1.size()-1);
                continue;
            }

            S1 += S[i];
        }

        for (int i = 0; i < T.size(); ++i) {
            if (T[i] == '#'){
                T1 = T1.substr(0, T1.size()-1);
                continue;
            }

            T1 += T[i];
        }

        return S1 == T1;
    }
};