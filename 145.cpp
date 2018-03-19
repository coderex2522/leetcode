#if 0
//·ÇµÝ¹é
#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

 typedef struct LRB{
    bool left;
    bool right;
 }LRB;

vector<int> postorderTraversal(TreeNode* root)
{
    vector<int> res;
    stack<TreeNode *> st;
    map<TreeNode*,LRB> m;
    map<TreeNode*,LRB>::iterator mi;

    if(root==NULL)
        return res;
    st.push(root);
    while(!st.empty())
    {
        TreeNode *tn=st.top();
        TreeNode *tn_tmp=tn;
        mi=m.find(tn);
        if(mi==m.end())
        {
            LRB lrb;
            lrb.left=false;
            lrb.right=false;
            m[tn]=lrb;
        }
        else if(mi->second.left&&mi->second.right)
        {
            st.pop();
            res.push_back(tn->val);
            continue;
        }

        if(!m[tn].left)
        {
            m[tn].left=true;
            while(tn->left!=NULL)
            {
                tn=tn->left;
                LRB lrb;
                lrb.left=true;
                lrb.right=false;
                m[tn]=lrb;
                st.push(tn);
            }
        }

        if(tn_tmp==tn&&!m[tn_tmp].right)
            m[tn_tmp].right=true;

        if(!tn->right)
        {
            res.push_back(tn->val);
            st.pop();
        }
        else{
            m[tn].right=true;
            st.push(tn->right);
        }
    }

    return res;
}

int main()
{
    TreeNode *tn2=new TreeNode(2);
    TreeNode *tn1=new TreeNode(1);
    tn1->right=tn2;
    TreeNode *tn3=new TreeNode(3);
    tn3->left=tn1;

    vector<int> vi;
    vi=postorderTraversal(tn3);
    for(int i=0;i<vi.size();i++)
    {
        cout<<vi[i]<<"  ";
    }

    return 0;
}
#endif // 1
