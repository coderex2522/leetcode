#if 0
#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *recurConstructTree(vector<int> nums,int left,int right)
{
    if(left>right)
        return NULL;

    int max_index=left;
    for(int i=left+1;i<=right;i++)
        if(nums[i]>nums[max_index])
            max_index=i;

    TreeNode *root=new TreeNode(nums[max_index]);
    if(left!=right)
    {
        TreeNode *leftTree=recurConstructTree(nums,left,max_index-1);
        TreeNode *rightTree=recurConstructTree(nums,max_index+1,right);
        root->left=leftTree;
        root->right=rightTree;
    }
    return root;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums)
{
    return recurConstructTree(nums,0,nums.size()-1);
}


int main()
{
    return 0;
}
#endif // 1
