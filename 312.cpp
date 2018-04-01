#if 0
#include <iostream>
#include <vector>

using namespace std;

int maxCoins(vector<int>& nums)
{
    if(nums.size()==0)
        return 0;

    //1..nums..1
    nums.push_back(1);
    nums.push_back(1);
    for(int i=nums.size()-2;i>0;i--)
        nums[i]=nums[i-1];
    nums[0]=1;
    int f[nums.size()][nums.size()]={0};
    for(int len=0;len<nums.size();len++)
    {
        for(int i=0;i<nums.size();i++)
        {
            if(i+len>=nums.size())
                break;
            f[i][i+len]=0;
            int maxx=0;
            for(int j=i+1;j<i+len;j++)
            {

                int tmp=f[i][j]+nums[i]*nums[j]*nums[i+len]+f[j][i+len];
                if(tmp>maxx)
                    maxx=tmp;
            }
            f[i][i+len]=maxx;
        }
    }

    return f[0][nums.size()-1];
}

int main()
{
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(8);
    cout<<maxCoins(nums)<<endl;

    return 0;
}

/*method of Tan Xin is false*/
/*
int maxCoins(vector<int>& nums)
{
    if(nums.size()==0)
        return 0;
    int res=0,len=nums.size();
    for(int i=0;i<nums.size()-2;i++)
    {
        int minx=-1;
        for(int j=1;j<nums.size()-1;j++)
            if(nums[j]!=-1)
            {
                if(minx==-1)
                    minx=j;
                else if(nums[minx]>nums[j])
                    minx=j;
            }
        int childres=nums[minx];
        int pre=minx-1;
        while(pre>=0&&nums[pre]==-1)
            pre--;
        if(pre>=0)
            childres*=nums[pre];
        int next=minx+1;
        while(next<nums.size()&&nums[next]==-1)
            next++;
        if(next<nums.size())
            childres*=nums[next];
        res+=childres;
        nums[minx]=-1;
    }

    if(len>=2)
        res+=nums[0]*nums[len-1];

    if(len==1)
        res+=nums[0];
    else
        res+=max(nums[0],nums[len-1]);
    return res;
}*/
/*Time Limit*/
/*
int solve(vector<int> &nums,int cnt)
{
    if(cnt==nums.size())
        return 0;
    int maxx=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]!=-1)
        {
            int childres=nums[i],pre,next;
            pre=i-1;
            while(pre>=0&&nums[pre]==-1)
                pre--;
            if(pre>=0)
                childres*=nums[pre];
            next=i+1;
            while(next<nums.size()&&nums[next]==-1)
                next++;
            if(next<nums.size())
                childres*=nums[next];

            int tmp=nums[i];
            nums[i]=-1;
            childres+=solve(nums,cnt+1);
            nums[i]=tmp;
            if(childres>maxx)
            maxx=childres;
        }
    }
    return maxx;
}

int maxCoins(vector<int>& nums)
{
    return solve(nums,0);
}*/
#endif // 1
