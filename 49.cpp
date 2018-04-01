#if 0
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int m[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,57,61,67,71,73,79,83,89,97,101};
int magic=2654404609;

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    unordered_map<int,vector<string>> um;

    for(int i=0;i<strs.size();i++)
    {
        int mul=1;
        for(int j=0;j<strs[i].size();j++)
        {
            mul*=m[strs[i][j]-'a'];
            mul%=magic;
        }
        auto it=um.find(mul);
        if(it!=um.end())
        {
            it->second.push_back(strs[i]);
        }
        else
        {
            vector<string> vs;
            vs.push_back(strs[i]);
            um[mul]=vs;
        }
    }

    auto it=um.begin();
    vector<vector<string>> res;
    while(it!=um.end())
    {
        res.push_back(it->second);
        it++;
    }

    return res;
}


#endif
