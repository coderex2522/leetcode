#if 0
#include <iostream>
#include <vector>

using namespace std;

//最大值 最小化
int cntArrayNums(vector<int> nums,int sumx)
{
    int cnt=0,subsum=0;
    for(int i=0;i<nums.size();i++)
    {
        subsum+=nums[i];
        if(subsum<=sumx)
            continue;
        else
        {
            subsum=nums[i];
            cnt++;
        }
    }
    cnt++;
    return cnt;
}

int splitArray(vector<int>& nums, int m)
{
    int total_sum=0,maxx;
    maxx=-1;
    for(int i=0;i<nums.size();i++)
    {
        if(total_sum+nums[i]>INT_MAX)
        {
            total_sum=INT_MAX;
            break;
        }

        total_sum+=nums[i];
        if(maxx<nums[i])
            maxx=nums[i];
    }

    if(nums.size()==0)
        return 0;
    if(m==1)
        return total_sum;
    if(nums.size()==m)
        return maxx;

    int left=maxx,right=total_sum;
    while(left<=right)
    {
        int mid,childres;
        mid=(left+right)/2;
        childres=cntArrayNums(nums,mid);
        if(m<childres)
            left=mid+1;
        else
            right=mid-1;
    }

    return left;
}

/* Time Limit Exceed
int solve(vector<int> &nums,vector<int> sums, int startx, int m)
{
    if(m==1)
    {
        int sumx=0;
        for(int i=startx;i<nums.size();i++)
            sumx+=nums[i];
        return sumx;
    }

    if(nums.size()-startx==m)
    {
        int maxx=-1;
        for(int i=startx;i<nums.size();i++)
            if(nums[i]>maxx)
                maxx=nums[i];
        return maxx;
    }

    int sumx=0;
    int minx=-1;
    for(int i=startx;i<nums.size();i++)
    {
        sumx+=nums[i];
        if(nums.size()-i<m)
            break;
        int childanswer=solve(nums,i+1,m-1);
        if(minx==-1||max(sumx,childanswer)<minx)
            minx=max(sumx,childanswer);
    }
    return minx;
}

int splitArray(vector<int>& nums, int m)
{
    return solve(nums,0,m);
}
*/
int main()
{
    int a[]={1,2,3,4,5};
    vector<int> vec;
    for(int i=0;i<5;i++)
        vec.push_back(a[i]);

    cout<<splitArray(vec,2)<<endl;
    return 0;
}
#endif // 1
