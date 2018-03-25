#if 0
//N-queens
#include <iostream>
#include <vector>

using namespace std;
int cnt=0;

void solve(vector<bool> &column, vector<bool> &pos, vector<bool> &neg, int currow, int n)
{
    if(currow==n)
    {
        cnt++;
        return ;
    }

    for(int i=0;i<n;i++)
    {
        int pos_index=i-currow+n-1;
        int neg_index=2*n-2-(i+currow);
        if(!column[i]&&!pos[pos_index]&&!neg[neg_index])
        {
            column[i]=pos[pos_index]=neg[neg_index]=true;
            solve(column,pos,neg,currow+1,n);
            column[i]=pos[pos_index]=neg[neg_index]=false;
        }
    }
}

int totalNQueens(int n)
{
    vector<bool> column(n,false);
    vector<bool> pos(2*n-1,false);
    vector<bool> neg(2*n-1,false);
    if(n==0)
        return 0;
    cnt=0;
    solve(column,pos,neg,0,n);
    return cnt;
}

int main()
{
    return 0;
}
#endif // 1
