#if 0
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void solve(TreeNode* root,int cur_level,int &maxx_level,int &maxx,int &second_maxx)
{
    if(root==nullptr)
    {
        maxx_level=cur_level;
        return ;
    }

    int left_maxx,left_second_maxx,left_maxx_level,right_maxx,right_second_maxx,right_maxx_level;
    left_maxx=left_second_maxx=0;
    right_maxx=right_second_maxx=0;

    solve(root->left,cur_level+1,left_maxx_level,left_maxx,left_second_maxx);
    solve(root->right,cur_level+1,right_maxx_level,right_maxx,right_second_maxx);
    int cur=root->val;
    if(left_maxx_level-cur_level==1)
        cur+=left_second_maxx;
    else
        cur+=left_maxx;

    if(right_maxx_level-cur_level==1)
        cur+=right_second_maxx;
    else
        cur+=right_maxx;

    if(cur>left_maxx+right_maxx)
    {
        maxx_level=cur_level;
        maxx=cur;
        second_maxx=left_maxx+right_maxx;
    }
    else
    {
        maxx_level=cur_level+1;
        maxx=left_maxx+right_maxx;
        second_maxx=maxx;
    }
}

int rob(TreeNode* root)
{
    int maxx=0,maxx_level,second_maxx;
    solve(root,0,maxx_level,maxx,second_maxx);
    return maxx;
}

int main()
{
    TreeNode *tn=new TreeNode(4);
    TreeNode *tn1=new TreeNode(8);
    TreeNode *tn2=new TreeNode(11);
    tn2->left=tn;
    tn2->right=tn1;
    cout<<rob(tn2)<<endl;
    return 0;
}
#endif // 1
