#if 0
//Segment Tree
#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    vector<int> segtree;
    int length;
    NumArray(vector<int> nums) {
        length=1;
        while(length<nums.size())
            length*=2;
        for(int i=0;i<length*2-1;i++)
            segtree.push_back(0);

        for(int i=0;i<nums.size();i++)
            update(i,nums[i]);

        for(int i=0;i<length*2-1;i++)
            cout<<segtree[i]<<endl;
    }

    void update(int i, int val) {
        i+=length-1;
        int sub=val-segtree[i];
        segtree[i]=val;

        while(i>0)
        {
            i=(i-1)/2;
            segtree[i]+=sub;
        }
    }

    int doSumRange(int i,int j,int root,int left,int right)
    {
        if(i<=left&&right<=j)
            return segtree[root];
        if(right<i||left>j)
            return 0;

        int leftsum=doSumRange(i,j,root*2+1,left,(right+left)/2);
        int rightsum=doSumRange(i,j,root*2+2,(right+left)/2+1,right);
        return leftsum+rightsum;
    }

    int sumRange(int i, int j) {
        return doSumRange(i,j,0,0,length-1);
    }
};

int main()
{

    int a[]={1,3,5};
    vector<int> vec;
    for(int i=0;i<3;i++)
        vec.push_back(a[i]);
    NumArray num(vec);
    cout<<num.sumRange(0,2)<<endl;
    return 0;
}
#endif
