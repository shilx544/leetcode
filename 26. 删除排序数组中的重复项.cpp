class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        int cnt = 0; //统计当前元素需要前移的位数，注意还是计数排序思想！！！只不过不需要整个数组
        for(int i=1; i<size; ++i){
            if(nums[i] == nums[i-1])
                cnt++;
            nums[i-cnt] = nums[i]; //前移cnt个位置           
        }
        return size-cnt;
    }
};