#if 0
#include <iostream>
#include <vector>
#include <set>

using namespace std;
/*success the condition check too terrible */

bool check(int a,int b,int t)//a<=b
{
    long long res=b;
    res-=a;

    return res<=t;
}

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
{
    multiset<int> num_set_k;
    if(t<0||nums.size()==0)
        return false;

    for(int i=0;i<nums.size();i++)
    {
        if(i>k)
            num_set_k.erase(num_set_k.find(nums[i-k-1]));
        num_set_k.insert(nums[i]);
        multiset<int>::iterator it=num_set_k.find(nums[i]);
        it++;
        if(it!=num_set_k.end()&&check(nums[i],*it,t))
            return true;
        it--;
        if(it!=num_set_k.begin()&&check(*(--it),nums[i],t))
            return true;
    }
    return false;
}


int main()
{
    return 0;
}

/*success the condition check too terrible */
/*
bool check(int a,int b,int t)
{
    if(a==INT_MIN||b==INT_MIN)
    {
        if(a>=0||b>=0)
            return false;
        if(abs(abs(a)-abs(b))<=t)
            return true;
        else
            return false;
    }

    if((a>0&&b<0)||(a<0&&b>0))
    {
        int absa=abs(a),absb=abs(b);
        if((absa+absb<=absa)||(absa+absb<=absb))
            return false;
        return absa+absb<=t;
    }

    if(abs(a-b)<=t)
        return true;
    else
        return false;
}

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
{
    multiset<int> num_set_k;
    if(t<0||nums.size()==0)
        return false;

    for(int i=0;i<nums.size();i++)
    {
        if(i>k)
            num_set_k.erase(num_set_k.find(nums[i-k-1]));
        num_set_k.insert(nums[i]);
        multiset<int>::iterator it=num_set_k.find(nums[i]);
        it++;
        if(it!=num_set_k.end()&&check(*it,nums[i],t))
            return true;
        it--;
        if(it!=num_set_k.begin()&&check(*(--it),nums[i],t))
            return true;
    }
    return false;
}
*/

/*origin method Time Limit*/
/*
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
{
    for(int i=0;i<nums.size();i++)
    {
        for(int j=i+1;j-i<=k&&j<nums.size();j++)
        {
            if((nums[j]<0&&nums[i]>0)||(nums[j]>0&&nums[i]<0))
            {
                int tmp=abs(nums[j])+abs(nums[i]);
                if(tmp<=abs(nums[j])||tmp<=nums[i])
                    continue;
            }
            if((nums[j]==-2147483648&&nums[i]==0)||(nums[i]==-2147483648&&nums[j]==0))
                continue;
            int tmp=nums[j]-nums[i];
            if(tmp<0)
                tmp=-1*tmp;
            if(tmp<=t)
                return true;
        }
    }
    return false;
}
*/
#endif // 1
