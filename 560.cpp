#if 0
//important
#include <iostream>
#include <unordered_map>
using namespace std;


int subarraySum(vector<int>& nums, int k)
{
    int cnt,sum;
    unordered_map<int,int> um;
    cnt=sum=0;
    um[0]=1;
    for(auto num:nums)
    {
        sum+=num;
        cnt+=um[sum-k];
        um[sum]+=1;
    }

    return cnt;
}

int main()
{
    vector<int> vec={1,2,3};
    subarraySum(vec,3);
    return 0;
}

/**Time spend so much
int subarraySum(vector<int>& nums, int k)
{
    if(nums.size()==0)
        return 0;
    int cnt,sum=0;
    vector<int> totalsum;
    for(auto i:nums)
    {
        totalsum.push_back(sum);
        sum+=i;
    }
    totalsum.push_back(sum);

    for(int i=0;i<nums.size();i++)
        for(int j=i+1;j<=nums.size();j++)
            if(totalsum[j]-totalsum[i]==k)
                cnt++;

    return cnt;
}*/
#endif // 1
