#if 0
#include <iostream>
#include <vector>

using namespace std;
int dirtX[4]={-1,0,1,0};
int dirtY[4]={0,-1,0,1};

void dfsgraph(vector<vector<char>> &grid, vector<vector<bool>> &flag, int row, int col)
{
    flag[row][col]=true;
    for(int i=0;i<4;i++)
    {
        int newrow,newcol;
        newrow=row+dirtX[i];
        newcol=col+dirtY[i];
        if(newrow>=0&&newrow<grid.size()&&newcol>=0&&newcol<grid[0].size()&&grid[newrow][newcol]=='1'&&!flag[newrow][newcol])
            dfsgraph(grid,flag,newrow,newcol);
    }
}

int numIslands(vector<vector<char>>& grid)
{
    int res=0;

    vector<vector<bool>> flag;
    for(int i=0;i<grid.size();i++)
    {
        vector<bool> tmp(grid[0].size(),false);
        flag.push_back(tmp);
    }

    for(int i=0;i<flag.size();i++)
        for(int j=0;j<flag[0].size();j++)
        {
            if(!flag[i][j]&&grid[i][j]=='1')
            {
                res++;
                dfsgraph(grid,flag,i,j);
            }
        }
    return res;
}

int main()
{
    return 0;
}
#endif // 1
