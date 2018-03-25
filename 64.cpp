#if 0
//dynamic programming
//f[i][j]=minx(f[i-1][j],f[i][j-1])+grid[i][j];
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> vecres(grid.size());


        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                int minx=-1;
                if(j-1>=0)
                    minx=vecres[i][j-1];
                if(i-1>=0&&(minx==-1||minx>vecres[i-1][j]))
                    minx=vecres[i-1][j];
                if(minx!=-1)
                    vecres[i].push_back(minx+grid[i][j]);
                else
                    vecres[i].push_back(grid[i][j]);
            }
        }

        if(grid.size()==0||grid[0].size()==0)
            return 0;
        return vecres[grid.size()-1][grid[0].size()-1];
    }
};

int main()
{
    return 0;
}
#endif // 1
