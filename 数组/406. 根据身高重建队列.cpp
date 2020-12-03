class Solution {
public:
    /* 思路:
    将所有人按照身高从高到低排序，然后从高到低，逐个放入队列中。
    放置某人时，比他个高的都已放置，比他个低的都未放置，而只有比他个高的对他的k值有影响，比他个低的对他的k值无影响，所以，只需要把他放置到当前队列的第k+1位即可。（后来者不会影响到他）
     */
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        vector<vector<int>> result;

        sort(people.begin(), people.end(), 
            [&](const vector<int>& x, const vector<int>& y) 
            -> bool {return x[0] > y[0] || (x[0] == y[0] && x[1] < y[1]);});

        vector<int> idx;
        for (int i = 0; i < n; ++i) {
            idx.insert(idx.begin() + people[i][1],i);
        }

        for (int i = 0; i < n; ++i) {
            result.push_back(people[idx[i]]);
        }

        return result;
    }
};