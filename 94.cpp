#if 0
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode* root)
{
    stack<TreeNode *> st;
    vector<int> res;

    TreeNode *cur=root;
    while(cur!=NULL||!st.empty())
    {
        while(cur!=NULL)
        {
            st.push(cur);
            cur=cur->left;
        }
        cur=st.top();
        st.pop();
        res.push_back(cur->val);
        cur=cur->right;
    }

    return res;
}

int main()
{
    return 0;
}
#endif // 1
