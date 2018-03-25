#if 0
#include <iostream>
#include <vector>

using namespace std;

void binary_sort(vector<int> &nums)
{
    for(int i=1;i<nums.size();i++)
    {
        int left=0,right=i-1;

        while(left<=right)
        {
            /*while循环返回后,如果left<i,总是位于大于nums[i]处，否则left=i*/
            int mid=(left+right)/2;
            if(nums[mid]<=nums[i])
                left=mid+1;
            else if(nums[mid]>nums[i])
                right=mid-1;
        }
        if(left==i)
            continue;
        int tmp=nums[i];
        for(int j=i-1;j>=left;j--)
            nums[j+1]=nums[j];
        nums[left]=tmp;
    }
}

int main()
{
    int nums[]={3,2,5,4,6,7,8,1,9,0};
    vector<int> vecnums;

    for(int i=0;i<10;i++)
        vecnums.push_back(nums[i]);

    binary_sort(vecnums);

    for(auto i:vecnums)
        cout<<i<<endl;

    return 0;
}
#endif // 1
