#if 0
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int> preorderTraversal(TreeNode* root)
{
    vector<int> res;
    stack<TreeNode*> st;

    TreeNode *cur=root;
    while(cur!=NULL||!st.empty())
    {
        while(cur!=NULL)
        {
            res.push_back(cur->val);
            st.push_back(cur);
            cur=cur->left;
        }
        cur=st.top();
        st.pop();
        cur=cur->right;
    }

    return res;
}

int main()
{

}
#endif // 1
