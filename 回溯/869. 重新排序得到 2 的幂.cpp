class Solution {
public:
    std::set<int> candidates;
    int m;
    int cnts[10];

    bool dfs(int u, int cur) {
        if (u == m)
            return candidates.find(cur) != candidates.end();
        for (int i = 0; i < 10; i++) {
            if (cnts[i] != 0) {
                cnts[i]--;
                if ((i != 0 || cur != 0) && dfs(u + 1, cur * 10 + i)) return true;
                cnts[i]++;
            }
        }
        return false;
    }

    bool reorderedPowerOf2(int n) {
	    for (int i = 1; i < (int)1e9+10; i*=2) {
            candidates.insert(i);
        }
        while (n != 0) {
            cnts[n % 10]++;
            n /= 10;
            m++;
        }
        return dfs(0, 0);
    }
};