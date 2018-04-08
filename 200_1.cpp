#if 0
//union find method;
#include <iostream>
#include <vector>

using namespace std;

int dirtX[2]={-1,0};
int dirtY[2]={0,-1};

int getParent(vector<int> &p, int x)
{
    if(p[x]==x)
        return x;
    else
    {
        p[x]=getParent(p,p[x]);
        return p[x];
    }
}

int numIslands(vector<vector<char>>& grid)
{
    int res=0;
    vector<int> p;
    for(int i=0;i<grid.size();i++)
        for(int j=0;j<grid[0].size();j++)
        {
            if(grid[i][j]=='0')
                res--;
            p.push_back(i*grid[0].size()+j);
        }

    for(int i=0;i<grid.size();i++)
        for(int j=0;j<grid[0].size();j++)
        {
            if(grid[i][j]=='0')
                continue;
            for(int k=0;k<2;k++)
            {
                int newrow,newcol;
                newrow=dirtX[k]+i;
                newcol=dirtY[k]+j;
                if(newrow>=0&&newcol>=0&&grid[newrow][newcol]=='1')
                {
                    int pnew=getParent(p,newrow*grid[0].size()+newcol);
                    int pcur=getParent(p,i*grid[0].size()+j);
                    p[pcur]=pnew;
                }
            }
        }

    for(int i=0;i<grid.size();i++)
        for(int j=0;j<grid[0].size();j++)
            if(p[i*grid[0].size()+j]==i*grid[0].size()+j)
                res++;
    return res;
}

int main()
{

    vector<vector<char>> grid;
    char str[]="11110";
    vector<char> vc;
    for(int i=0;i<5;i++)
        vc.push_back(str[i]);
    grid.push_back(vc);

    char str1[]="11010";
    vc.clear();
    for(int i=0;i<5;i++)
        vc.push_back(str1[i]);
    grid.push_back(vc);

    char str2[]="11000";
    vc.clear();
    for(int i=0;i<5;i++)
        vc.push_back(str2[i]);
    grid.push_back(vc);

    char str3[]="00000";
    vc.clear();
    for(int i=0;i<5;i++)
        vc.push_back(str3[i]);
    grid.push_back(vc);

    cout<<numIslands(grid)<<endl;
    return 0;
}
#endif // 1
