#if 0
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k)
{
    vector<int> res,vec_ksum;
    int sum=0;
    if(nums.size()<3*k)
        return res;

    vec_ksum.push_back(0);
    for(int i=0;i<nums.size();i++)
    {
        if(i>=k)
        {
            vec_ksum.push_back(sum);
            sum-=nums[i-k];
        }
        sum+=nums[i];
    }
    vec_ksum.push_back(sum);

    vector<vector<int>> f(vec_ksum.size(),vector<int>(3+1,0));

    for(int i=1;i<vec_ksum.size();i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(i<k)
                f[i][j]=max(f[i-1][j],vec_ksum[i]);
            else
                f[i][j]=max(f[i-1][j],f[i-k][j-1]+vec_ksum[i]);
        }
    }

    int index=vec_ksum.size()-1;
    for(int j=3;j>0;j--)
    {
        for(int i=1;i<vec_ksum.size();i++)
            if(f[i][j]==f[index][j])
            {
                index=i;
                res.push_back(i-1);
                break;
            }
        index=index-k;
    }
    reverse(res.begin(),res.end());
    return res;
}

int main()
{
    vector<int> vec={7,13,20,19,19,2,10,1,1,19};
    maxSumOfThreeSubarrays(vec,3);
    return 0;
}
#endif // 1
