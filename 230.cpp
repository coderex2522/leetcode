#if 0
#include <iostream>
#include <stack>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int kthSmallest(TreeNode* root, int k)
{
    stack<TreeNode *> s;
    TreeNode *cur=root;
    int cnt=0;
    while(cur!=nullptr||!s.empty())
    {
        while(cur!=nullptr)
        {
            s.push(cur);
            cur=cur->left;
        }
        cur=s.top();
        s.pop();
        cnt++;
        if(cnt==k)
            break;
        cur=cur->right;
    }

    return cur->val;
}
int main()
{
    TreeNode *tmp=new TreeNode(1);
    TreeNode *tmp1=new TreeNode(2);
    tmp1->left=tmp;
    TreeNode *tmp2=new TreeNode(3);
    tmp2->left=tmp1;
    TreeNode *tmp3=new TreeNode(4);
    tmp2->right=tmp3;
    cout<<kthSmallest(tmp2,3)<<endl;

    return 0;
}

//recur method

void solve(TreeNode *root,int &cur,int &res,int k)
{
    if(cur>k||root==NULL)
        return ;
    solve(root->left,cur,res,k);
    cur++;
    if(cur==k)
    {
        res=root->val;
        return ;
    }
    solve(root->right,cur,res,k);
}

int kthSmallest(TreeNode* root, int k)
{
    int res=0,cur=0;
    solve(root,cur,res,k);
    return res;
}

#endif // 1
