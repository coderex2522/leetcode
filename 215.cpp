#if 0
//heap sort
#include <iostream>
#include <vector>

using namespace std;

void adjustHeap(vector<int> &nums, int root, int length)
{
    while(root<length)
    {
        int largest;
        if(root*2+1<length&&nums[root*2+1]>nums[root])
            largest=root*2+1;
        else
            largest=root;

        if(root*2+2<length&&nums[root*2+2]>nums[largest])
            largest=root*2+2;
        if(largest!=root)
        {
            int tmp=nums[root];
            nums[root]=nums[largest];
            nums[largest]=tmp;
            root=largest;
        }
        else
            break;
    }
}

int findKthLargest(vector<int>& nums, int k)
{
    for(int i=nums.size()/2-1;i>=0;i--)
    {
        adjustHeap(nums,i,nums.size());
    }

    int res;
    for(int i=0;i<k;i++)
    {
        res=nums[0];
        nums[0]=nums[nums.size()-i-1];
        adjustHeap(nums,0,nums.size()-i-1);
    }
    return res;
}

int main()
{
    int a[]={3,1,2,4};
    vector<int> nums;
    for(int i=0;i<4;i++)
    {
        nums.push_back(a[i]);
    }
    cout<<findKthLargest(nums,2)<<endl;
    return 0;
}
#endif // 1
