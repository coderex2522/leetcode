#if 0
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;
const int maxn=55;
int directR[4]={-1,0,1,0};
int directC[4]={0,-1,0,1};
bool flag[maxn][maxn];

void solve(vector<vector<int> > &image, int sr, int sc, int newColor)
{
    flag[sr][sc]=true;
    for(int i=0;i<4;i++)
    {
        int newSr,newSc;
        newSr=sr+directR[i];
        newSc=sc+directC[i];
        if(newSr<0||newSr>=image.size()||newSc<0||newSc>=image[0].size())
            continue;
        if(flag[newSr][newSc])
            continue;
        if(image[sr][sc]==image[newSr][newSc])
        {
            solve(image,newSr,newSc,newColor);
        }
        else
            flag[newSr][newSc]=true;
    }
    image[sr][sc]=newColor;
}

vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int newColor)
{
    memset(flag,0,sizeof(flag));
    solve(image,sr,sc,newColor);
    return image;
}

int main()
{
    int a[3][3]={1,1,1,1,1,0,1,0,1};
    vector<vector<int> > image;
    for(int i=0;i<3;i++)
    {
        vector<int> tmp;
        for(int j=0;j<3;j++)
            tmp.push_back(a[i][j]);
        image.push_back(tmp);
    }

    floodFill(image,1,1,20);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            cout<<image[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
#endif // 1
