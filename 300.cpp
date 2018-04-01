#if 0
#include <iostream>
#include <vector>
using namespace std;

int lengthOfLIS(vector<int>& nums)
{
    vector<int> res;
    if(nums.size()==0)
        return 0;

    res.push_back(nums[0]);
    for(int i=1;i<nums.size();i++)
    {
        auto it=lower_bound(res.begin(),res.end(),nums[i]);
        if(it==res.end())
            res.push_back(nums[i]);
        else
            *it=nums[i];
    }
    return res.size();
}

int main()
{
    return 0;
}
#endif // 1
