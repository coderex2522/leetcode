#if 0
#include <iostream>
#include <vector>

using namespace std;
//下面算法只适用与单符号组的数组,即全部都是正数,或者全部都是负数.
void radixsort(vector<int> &nums)
{
    vector<int> v[10];
    int digit=1;
    int maxx;//用来存储最大的那个数,确定最大的位数;

    if(nums.size()==0)
        return ;

    maxx=nums[0];
    for(int i=1;i<nums.size();i++)
    {
        if(maxx<nums[i])
            maxx=nums[i];
    }



}
int main()
{
    return 0;
}
#endif // 1
