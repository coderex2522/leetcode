#if 0
#include <iostream>
#include <vector>

using namespace std;

int maximalSquare(vector<vector<char>>& matrix)
{
    if(matrix.size()==0)
        return 0;
    vector<vector<int>> f(matrix.size()+1,vector<int>(matrix[0].size()+1,0));
    int maxx=0;
    for(int i=1;i<=matrix.size();i++)
        for(int j=1;j<=matrix[i].size();j++)
        {
            if(matrix[i-1][j-1]=='0')
                continue;
            f[i][j]=min(f[i-1][j],f[i][j-1]);
            f[i][j]=min(f[i-1][j-1],f[i][j]);
            f[i][j]+=1;
            if(maxx<f[i][j])
                maxx=f[i][j];
        }

    return maxx*maxx;
}

int main()
{
    return 0;
}

/**space is too much
int maximalSquare(vector<vector<char>>& matrix)
{
    if(matrix.size()==0)
        return 0;
    vector<vector<int>> f(matrix.size(),vector<int>(matrix[0].size(),0)),rowf(f),colf(f);
    int maxx=0;
    for(int i=0;i<matrix.size();i++)
        for(int j=0;j<matrix[i].size();j++)
        {
            if(matrix[i][j]=='0')
                continue;
            rowf[i][j]=colf[i][j]=f[i][j]=1;
            if(i-1>=0&&j-1>=0)
                f[i][j]+=f[i-1][j-1];
            if(i-1>=0)
                colf[i][j]+=colf[i-1][j];
            if(j-1>=0)
                rowf[i][j]+=rowf[i][j-1];
            f[i][j]=min(f[i][j],rowf[i][j]);
            f[i][j]=min(f[i][j],colf[i][j]);
            if(maxx<f[i][j])
                maxx=f[i][j];
        }

    return maxx*maxx;
}
*/
#endif
