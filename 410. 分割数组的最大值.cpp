class Solution {
public:
int splitArray(vector<int>& nums, int m) {
    long l = nums[0], h = 0;//int类型在这里不合适，因为h可能会超过int类型能表示的最大值
    for (auto i : nums)
    {
        h += i;
        l = l > i ? l : i;
    }
    while (l<h)
    {
        long mid = (l + h) / 2;
        long temp = 0;
        int cnt = 1;//初始值必须为1
        for(auto i:nums)
        {
            temp += i;
            if(temp>mid)
            {
                temp = i;
                ++cnt;
            }
        }
        if(cnt>m)
            l = mid + 1;
        else
            h = mid;
    }
    return l;
}
};