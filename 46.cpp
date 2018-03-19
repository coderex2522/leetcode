#if 0
#include <iostream>
#include <vector>

using namespace std;
vector<vector<int> > resVvi;
void recur(vector<int> &resVi, int n, int cnt, vector<bool> &flag)
{
    if(cnt==0)
        {
            resVvi.push_back(resVi);
            return ;
        }

        for(int i=0;i<n;i++)
        {
            if(!flag[i])
            {
                flag[i]=true;
                resVi.push_back(i);
                recur(resVi,n,cnt-1,flag);
                resVi.pop_back();
                flag[i]=false;
            }
        }
}
vector<vector<int>> permute(vector<int>& nums)
{
    vector<bool> flag(nums.size(),false);
        vector<int> resVi;
        for(int i=0;i<nums.size();i++)
        {
            resVi.clear();
            flag[i]=true;
            resVi.push_back(i);
            recur(resVi,nums.size(),nums.size()-1,flag);
            flag[i]=false;
        }

        for(int i=0;i<resVvi.size();i++)
        {
            for(int j=0;j<resVvi[i].size();j++)
            {
                resVvi[i][j]=nums[resVvi[i][j]];
                //cout<<resVvi[i][j]<<"   ";
            }
            //cout<<endl;
        }
        return resVvi;
}
int main()
{
    return 0;
}
#endif // 1
