#if 0
#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int> &nums)
{
    for(int i=1;i<nums.size();i++)
    {
        int cur=nums[i],j;
        for(j=i-1;j>=0;j--)
        {
            if(cur<nums[j])
                nums[j+1]=nums[j];
            else
                break;
        }
        nums[j+1]=cur;
    }
}

int main()
{
    int nums[]={3,2,5,4,6,7,8,1,9,0};
    vector<int> vecnums;

    for(int i=0;i<10;i++)
        vecnums.push_back(nums[i]);

    insertion_sort(vecnums);

    for(auto i:vecnums)
        cout<<i<<endl;

    return 0;
}
#endif // 1
