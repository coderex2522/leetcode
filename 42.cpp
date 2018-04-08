#if 0
#include <iostream>
#include <vector>

using namespace std;

int trap(vector<int>& height)
{
    int left,res,childres,max_index;
    left=res=childres=max_index=0;
    for(int i=1;i<height.size()||left<height.size();i++)
    {
        if(i==height.size())
        {
            childres=0;
            for(int j=left+1;j<max_index;j++)
                childres+=height[max_index]-height[j];
            res+=childres;
            left=max_index;
            i=left;
            max_index++;
            childres=0;
            continue;
        }
        if(height[i]>=height[left])
        {
            left=i;
            res+=childres;
            childres=0;
            max_index=left+1;
        }
        else
        {
            childres+=height[left]-height[i];
            if(height[max_index]<=height[i])
                max_index=i;
        }
    }
    return res;
}

int main()
{
    vector<int> height{4,2,3};
    cout<<trap(height)<<endl;
    return 0;
}
#endif // 1
