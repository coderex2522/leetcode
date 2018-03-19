#if 0
#include <iostream>
#include <vector>
#include <map>

using namespace std;
typedef struct Node{
    int num;
    int cnt;
}Node;
vector<int> topKFrequent(vector<int>& nums, int k)
{
    vector<int> res;
    map<int,int> m;
    map<int,int>::iterator it;
    for(int i=0;i<nums.size();i++)
    {
        it=m.find(nums[i]);
        if(it==m.end())
            m[nums[i]]=1;
        else
            it->second++;
    }
    return res;
}

int main()
{
    return 0;
}
#endif // 1
