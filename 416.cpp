#if 0
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <bitset>
#include <numeric>

using namespace std;


bool canPartition(vector<int>& nums) {
        int x = 0;
        for(int i = 0; i < nums.size(); i++)
            x += nums[i];
        if (x%2 == 1)
            return false;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n == 0) return false;
        return canSum(nums, x/2-nums[n-1], n-2);
    }

    bool canSum(vector<int>& v, int target, int index){
        if (target == 0) return true;
        if (index == -1) return false;
        if (v[index] == target)
            return true;
        if (v[index] < target && canSum(v, target-v[index], index-1))
            return true;
        return canSum(v, target, index-1);
    }

/*9ms*/
bool canPartition(vector<int>& nums)
{
        if(nums.size()<=1) return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2==1) return false;
        sum /= 2;
        bitset<30> bits(1);//初始化第零位为1

        for(int &num:nums){
            cout<<bits<<endl;
            bits |= bits<<num;
        }
        cout<<bits<<endl;
        return bits[sum];
}

bool canPartition(vector<int>& nums)
{
    unordered_map<int,bool> mib;
    int sum=0;
    for(int i=0;i<nums.size();i++)
        sum+=nums[i];

    if(sum%2!=0)
        return false;
    sum/=2;

    vector<int> v;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==sum)
            return true;
        auto it=mib.begin();
        while(it!=mib.end())
        {
            if((it->first)+nums[i]==sum)
                return true;
            if((it->first)+nums[i]<sum)
                v.push_back((it->first)+nums[i]);
            it++;
        }
        v.push_back(nums[i]);
        for(int j=0;j<v.size();j++)
            mib[v[j]]=true;
        v.clear();
    }
    return false;
}

int main()
{
    int a[]={1,5,11,5};
    vector<int> vec;
    for(int i=0;i<4;i++)
        vec.push_back(a[i]);
    canPartition(vec);
    return 0;
}

/*spend more time*/
/*
bool canPartition(vector<int>& nums)
{
    set<int> si;
    int sum=0;
    for(int i=0;i<nums.size();i++)
        sum+=nums[i];

    if(sum%2!=0)
        return false;
    sum/=2;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==sum)
            return true;
        vector<int> v;
        auto it=si.begin();
        while(it!=si.end())
        {
            if((*it)+nums[i]>sum)
                break;
            if((*it)+nums[i]==sum)
                return true;
            v.push_back((*it)+nums[i]);
            it++;
        }
        v.push_back(nums[i]);

        for(int j=0;j<v.size();j++)
            si.insert(v[j]);
    }
    return false;
}*/

/*Time Limit*/
/*
bool solve(vector<int> nums,vector<int> sum_vec,int cur,int presum,int halfsum)
{
    if(cur>=nums.size())
        return false;
    if(nums[cur]+presum==halfsum)
            return true;
    if(nums[cur]+presum>halfsum)
        return false;
    if(cur!=0&&(presum+sum_vec[sum_vec.size()-1]-sum_vec[cur-1]<halfsum))
        return false;
    return solve(nums,sum_vec,cur+1,presum+nums[cur],halfsum)||solve(nums,sum_vec,cur+1,presum,halfsum);
}

bool canPartition(vector<int>& nums)
{
    int sum=0;
    vector<int> sum_vec;
    for(int i=0;i<nums.size();i++)
    {
        sum+=nums[i];
        sum_vec.push_back(sum);
    }
    if(sum%2!=0)
        return false;

    return solve(nums,sum_vec,0,0,sum/2);
}
*/
#endif // 1
