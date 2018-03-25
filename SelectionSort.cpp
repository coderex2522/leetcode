#if 0
#include <iostream>
#include <vector>

using namespace std;

void selection_sort(vector<int> &nums)
{
    for(int i=0;i<nums.size();i++)
    {
        int minx=i;
        for(int j=i+1;j<nums.size();j++)
            if(nums[minx]>nums[j])
                minx=j;
        if(minx!=i)
        {
            int tmp=nums[i];
            nums[i]=nums[minx];
            nums[minx]=tmp;
        }
    }
}

int main()
{
    int nums[]={3,2,5,4,6,7,8,1,9,0};
    vector<int> vecnums;

    for(int i=0;i<10;i++)
        vecnums.push_back(nums[i]);

    selection_sort(vecnums);

    for(auto i:vecnums)
        cout<<i<<endl;

    return 0;
}
#endif // 1
