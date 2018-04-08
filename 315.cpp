#if 0
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    struct Node{
        int index;
        int val;
        Node(int index,int val):index(index),val(val){}
    };

    static bool myCmp(Node a,Node b)
    {
        if(a.val==b.val)
            return a.index<b.index;
        return a.val<b.val;
    }
    void update(vector<int> &cnt, int i)
    {
        while(i<cnt.size())
        {
            cnt[i]+=1;
            i+=i&(-i);
        }
    }

    int sum(vector<int> &cnt, int i)
    {//if cnt is not reference, memory is exceed the limit
        int res=0;
        while(i>0)
        {
            res+=cnt[i];
            i-=i&(-i);
        }
        return res;
    }

    vector<int> countSmaller(vector<int>& nums) {
        vector<Node> vec;
        for(int i=0;i<nums.size();i++)
            vec.push_back(Node(i,nums[i]));
        sort(vec.begin(),vec.end(),myCmp);
        vector<int> cnt(nums.size()+1,0);
        vector<int> res(nums.size(),0);
        for(int i=0;i<vec.size();i++)
        {
            res[vec[i].index]=sum(cnt,nums.size())-sum(cnt,vec[i].index);
            update(cnt,vec[i].index+1);
        }
        return res;
    }
};

int main()
{
    vector<int> nums{5, 2, 6, 1};
    Solution solution;
    solution.countSmaller(nums);
    return 0;
}
#endif // 1
