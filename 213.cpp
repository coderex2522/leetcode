#if 0
#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums, int left, int right)
{
    int maxx=nums[left],secmaxx=0;
    for(int i=left+1;i<right;i++)
    {
        int tmp=secmaxx+nums[i];
        secmaxx=maxx;
        maxx=max(tmp,maxx);
    }
    return maxx;
}

int rob(vector<int>& nums)
{
    if(nums.size()==0||nums.size()==1)
        return nums.size()==0?0:nums[0];

    return max(rob(nums,0,nums.size()-1),rob(nums,1,nums.size()));
}

int main()
{
    vector<int> nums{4,1,2};
    rob(nums);
    return 0;
}
#endif // 1
