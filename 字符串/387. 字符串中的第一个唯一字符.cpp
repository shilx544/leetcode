class Solution {
public:
    int firstUniqChar(string s) 
    {
        map<char,int> m;//<关键字,关键字的值>（每个关键字在map里出现一次）
        for(char x:s) m[x]++; //记录关键字出现的次数
        //查找只出现一次的关键字，并按题目要求返回
        for(int i=0; i<s.size(); ++i) {
            if(m[s[i]]==1) return i;
        }
        return -1;
    }
};