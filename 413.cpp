#if 0
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int cal(int x)
{
    int res=0;
    for(int i=3;i<=x;i++)
    {
        res+=x-i+1;
    }
    return res;
}

int numberOfArithmeticSlices(vector<int>& A)
{
    if(A.size()<3)
        return 0;
    vector<int> vec_cnt;
    unordered_map<int,int> um;//calculate
    int cnt,diff=A[1]-A[0],res;
    cnt=res=0;

    for(int i=1;i<A.size();i++)
    {
        if(diff==A[i]-A[i-1])
            cnt++;
        else
        {
            if(cnt>=2)
                vec_cnt.push_back(cnt+1);
            diff=A[i]-A[i-1];
            cnt=1;
        }
    }

    if(cnt>=2)
        vec_cnt.push_back(cnt+1);


    for(int i=0;i<vec_cnt.size();i++)
    {
        if(um.find(vec_cnt[i])==um.end())
            um[vec_cnt[i]]=cal(vec_cnt[i]);
        res+=um[vec_cnt[i]];
    }

    return res;
}
#endif // 1
