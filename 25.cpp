#if 0
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


    void solve(ListNode *pre,int k)
    {
        if(k/2==0)
            return ;

        int prek=k/2,nextk=k/2;
        if(k%2==1)
            prek++;

        ListNode *kstep=pre,*kkstep;
        for(int i=0;i<prek;i++)
            kstep=kstep->next;
        kkstep=kstep;
        for(int i=0;i<nextk;i++)
            kkstep=kkstep->next;

        ListNode *tmp=kstep->next;
        kstep->next=kkstep->next;
        kkstep->next=pre->next;
        pre->next=tmp;

        solve(kkstep,prek);
        solve(pre,nextk);
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *prehead=new ListNode(0),*cur,*pre;
        prehead->next=head;
        cur=prehead;
        pre=prehead;
        int cnt=0;
        while(cur!=nullptr)
        {
            if(cnt==k)
            {
                ListNode *tmp=pre->next;
                solve(pre,k);
                pre=tmp;
                cur=pre;
                cnt=0;
            }
            else
            {
                cur=cur->next;
                cnt++;
            }
        }
        ListNode *res=prehead->next;
        free(prehead);
        return res;
    }
/*
int main()
{
    int a[4];
    for(int i=0;i<4;i++)
        a[i]=i+1;
    ListNode *head=new ListNode(1);
    for(int i=3;i>0;i--)
    {
        ListNode *tmp=new ListNode(a[i]);
        tmp->next=head->next;
        head->next=tmp;
    }

    ListNode *cur=reverseKGroup(head,2);
    while(cur!=nullptr)
    {
        cout<<cur->val<<endl;
        cur=cur->next;
    }
    return 0;
}*/

int main()
{
    int a[5];
    for(int i=0;i<5;i++)
        a[i]=i+1;
    ListNode *head=new ListNode(1);
    for(int i=4;i>0;i--)
    {
        ListNode *tmp=new ListNode(a[i]);
        tmp->next=head->next;
        head->next=tmp;
    }

    ListNode *cur=reverseKGroup(head,2);
    while(cur!=nullptr)
    {
        cout<<cur->val<<endl;
        cur=cur->next;
    }
    return 0;
}
#endif // 1
