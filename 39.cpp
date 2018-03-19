#if 0
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int> > solve(vector<int> candidates,int startx,int target)
{
    vector<vector<int> > res;
    if(startx>=candidates.size())
        return res;
    for(int i=0;i<=target/candidates[startx];i++)
    {
        if(target-i*candidates[startx]==0)
        {
            res.push_back(vector<int>(i,candidates[startx]));
            break;
        }
        else if(target-i*candidates[startx]<candidates[startx])
            break;
        else
        {
            vector<vector<int> > childRes;
            childRes=solve(candidates,startx+1,target-i*candidates[startx]);
            for(int j=0;j<childRes.size();j++)
            {
                for(int k=0;k<i;k++)
                    childRes[j].push_back(candidates[startx]);
                res.push_back(childRes[j]);
            }
        }
    }
    return res;
}
vector<vector<int> > combinationSum(vector<int>& candidates, int target)
{
    vector<vector<int> > res;
    sort(candidates.begin(),candidates.end());
    return solve(candidates,0,target);
}

int main()
{
    int a[]={2, 3, 6, 7};
    vector<int> candidates;
    vector<vector<int> > res;
    for(int i=0;i<4;i++)
        candidates.push_back(a[i]);

    res=combinationSum(candidates, 7);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
            cout<<res[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
#endif // 1
