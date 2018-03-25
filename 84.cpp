#if 0
//The Time Spend very much.
#include <iostream>
#include <vector>

using namespace std;

int largestRectangleArea(vector<int>& heights)
{
    vector<int> decvec(heights.size(),-1);
    vector<int> area;

    if(heights.size()==0)
        return 0;

    for(int i=0;i<heights.size();i++)
    {
        int j=i+1,origin=i;
        while(j<heights.size()&&heights[i]==heights[j])
        {
            j++;
        }
        i=j-1;

        if(origin>0&&heights[i]>heights[origin-1])
            decvec[i]=origin-1;
        else if(origin>0)
        {
            for(int k=decvec[origin-1];k!=-1;k=decvec[k])
                if(heights[i]>heights[k])
                {
                    decvec[i]=k;
                    break;
                }
        }

        int maxx=heights[i]*(i-decvec[i]);
        for(int k=decvec[i];k!=-1;k=decvec[k])
        {
            if(maxx<(i-decvec[k])*heights[k])
                maxx=(i-decvec[k])*heights[k];

            if(decvec[k]==-1&&maxx<(i+1)*heights[k])
                maxx=(i+1)*heights[k];
        }

        area.push_back(maxx);
    }

    int maxx=-1;
    for(int i=0;i<area.size();i++)
    {
        if(maxx<area[i])
            maxx=area[i];
    }

    return maxx;
}

int main()
{
    int a[]={1,1,1};
    vector<int> vec;
    for(int i=0;i<3;i++)
        vec.push_back(a[i]);
    cout<<largestRectangleArea(vec)<<endl;
    return 0;
}
#endif
