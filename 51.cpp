#if 0
//N-queens
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<string>> res;
void solve(vector<bool> &column_flag, vector<bool> &pos_flag, vector<bool> &neg_flag, vector<int> &vi_res, int currow, int n)
{
    if(currow==n)
    {
        string str(n,'.');
        vector<string> vecstr(n,str);
        for(int i=0;i<vi_res.size();i++)
        {
            vecstr[i][vi_res[i]]='Q';
        }
        res.push_back(vecstr);
        return ;
    }

    for(int i=0;i<n;i++)
    {
        int pos_flag_index=i-currow+n-1;
        int neg_flag_index=2*n-2-(currow+i);
        if(!column_flag[i]&&!pos_flag[pos_flag_index]&&!neg_flag[neg_flag_index])
        {
            column_flag[i]=true;
            pos_flag[pos_flag_index]=true;
            neg_flag[neg_flag_index]=true;
            vi_res.push_back(i);
            solve(column_flag,pos_flag,neg_flag,vi_res,currow+1,n);
            vi_res.pop_back();
            column_flag[i]=false;
            pos_flag[pos_flag_index]=false;
            neg_flag[neg_flag_index]=false;
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<bool> pos_flag(2*n-1,false);
    vector<bool> neg_flag(2*n-1,false);
    vector<bool> column_flag(n,false);
    vector<int> vi_res;
    solve(column_flag,pos_flag,neg_flag,vi_res,0,n);
    return res;
}

int main()
{
    solveNQueens(4);
    return 0;
}
#endif // 1
