class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, int> m;
        for (int i = 0; i < arr.size(); ++i) {
            if (m.find(arr[i]) == m.end()) {
                m[arr[i]] = 1;
            } else {
                m[arr[i]]++;
            }
        }

        unordered_map<int, int>::const_iterator it = m.begin();
        set<int> s;
        for (; it != m.end(); ++it) {
            if (s.find(it->second) != s.end()) {
                return false;
            } else {
                s.insert(it->second);
            }
        }
        return true;
    }
};