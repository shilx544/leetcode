// islower(char c) 是否为小写字母
// isupper(char c) 是否为大写字母
// isdigit(char c) 是否为数字
// isalpha(char c) 是否为字母
// isalnum(char c) 是否为字母或者数字
// toupper(char c) 字母小转大
// tolower(char c) 字母大转小
// c.begin() 返回一个迭代器，它指向容器c的第一个元素
// c.end() 返回一个迭代器，它指向容器c的最后一个元素的下一个位置
// c.rbegin() 返回一个逆序迭代器，它指向容器c的最后一个元素
// c.rend() 返回一个逆序迭代器，它指向容器c的第一个元素前面的位置

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0; int right = s.size()-1;
        while (left < right) {
            while (!isalnum(s[left]) && left < right) left++;
            while (!isalnum(s[right]) && left < right) right--;

            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};