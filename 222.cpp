#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int getLeftHeight(TreeNode *root)
{
    int h=0;
    TreeNode *tmp=root;
    while(tmp!=nullptr)
    {
        h++;
        tmp=tmp->left;
    }
    return h;
}

int getRightHeight(TreeNode *root)
{
    int h=0;
    TreeNode *tmp=root;
    while(tmp!=nullptr)
    {
        h++;
        tmp=tmp->right;
    }
    return h;
}

int countNodes(TreeNode* root)
{
    if(root==nullptr)
        return 0;
    int left=getLeftHeight(root);
    int right=getRightHeight(root);
    if(left==right)
        return (1<<left)-1;
    else
        return countNodes(root->left)+countNodes(root->right)+1;

}


/**Time Limit
int res=-1,maxlevel=-1;

    void recur_cnt(TreeNode *pa,int level,int no)
    {
        if(res!=-1)
            return ;

        if(pa->left!=nullptr)
            recur_cnt(pa->left,level+1,no*2);
        if(pa->right!=nullptr)
            recur_cnt(pa->right,level+1,no*2+1);

        if(pa->left!=nullptr&&pa->right!=nullptr)
            return ;
        if(pa->left==nullptr&&pa->right==nullptr)
        {
            if(maxlevel==-1)
                maxlevel=level;
            else if(maxlevel==level-1)
                res=no*2-1;
            return ;
        }

        res=no*2;
    }

    int countNodes(TreeNode* root)
    {
        if(root==nullptr)
            return 0;
        recur_cnt(root,1,1);
        if(res==-1)
        {
            res=(1<<maxlevel)-1;
        }
        return res;
    }*/
/**Time Limit
int countNodes(TreeNode* root)
{
    if(root==nullptr)
        return 0;
    queue<TreeNode *> q;
    TreeNode *tmp;
    int cnt=1;
    q.push(root);
    while(!q.empty())
    {
        tmp=q.front();
        cnt++;
        q.pop();
        if(tmp->left!=nullptr)
            q.push(tmp->left);
        else
        {
            cnt=cnt*2-1;
            break;
        }
        if(tmp->right!=nullptr)
            q.push(tmp->right);
        else
        {
            cnt=cnt*2;
            break;
        }
    }

    return cnt;
}
*/
int main()
{
    return 0;
}
#endif // 1
