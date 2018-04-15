#if 0
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
/*
    int findLHS(vector<int>& nums) {
        map<int,int> um;//unordered_map not according the key sort
        for(auto i:nums)
            um[i]++;

        int pre,precnt,maxxcnt=0;
        precnt=0;
        for(auto i=um.begin();i!=um.end();i++)
        {
            if(precnt!=0&&(i->first-pre==1))
                maxxcnt=max(maxxcnt,i->second+precnt);
            pre=i->first;
            precnt=i->second;
        }
        return maxxcnt;
    }
*/

int findLHS(vector<int>& nums)
{
    if(nums.size()==0)
        return 0;
    sort(nums.begin(),nums.end());
    int precnt,next,nextcnt,maxxcnt;
    next=nums[0];
    nextcnt=maxxcnt=0;
    precnt=INT_MIN;

    for(auto i:nums)
    {
        if(next==i)
            nextcnt++;
        else
        {
            maxxcnt=max(maxxcnt,precnt+nextcnt);
            precnt=(i-next==1?nextcnt:INT_MIN);
            next=i;
            nextcnt=1;
        }
    }
    return max(maxxcnt,precnt+nextcnt);
}

int main()
{
    vector<int> nums={1,1,1,1};
    cout<<findLHS(nums)<<endl;
    return 0;
}
#endif // 1
