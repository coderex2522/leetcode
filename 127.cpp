#if 0
#include <iostream>
#include <queue>

using namespace std;
typedef struct Node{
    int id;
    int layer;
    struct Node *next;
    Node(int id,int layer,struct Node *next)
    {
        this->id=id;
        this->layer=layer;
        this->next=next;
    }
}Node;

bool isLink(string a,string b)
{
    int cnt=0;
    for(int i=0;i<a.length();i++)
        if(a[i]!=b[i])
            cnt++;
    if(cnt==1)
        return true;
    else
        return false;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
    vector<Node> vn;
    vector<bool> vb;
    int endx;
    for(int i=0; i<=wordList.size(); i++)
    {
        vn.push_back(Node(i,0,NULL));
        vb.push_back(false);
    }

    for(int i=0;i<=wordList.size();i++)
    {
        string a;
        if(i==0)
            a=beginWord;
        else
            a=wordList[i-1];

        if(a==endWord)
            endx=i;
        if(i!=0&&a==beginWord)
            continue;

        for(int j=i;j<wordList.size();j++)
        {
            if(isLink(a,wordList[j]))
            {
                if(a!=endWord)
                {
                    Node *tmp=new Node(j+1,0,vn[i].next);
                    vn[i].next=tmp;
                }
                if(a!=beginWord)
                {
                    Node *tmp=new Node(i,0,vn[j+1].next);
                    vn[j+1].next=tmp;
                }
            }
        }
    }


    queue<Node> q;
    int layer=0;
    vn[0].layer=1;
    q.push(vn[0]);
    vb[0]=true;
    while(!q.empty())
    {
        Node node=q.front();
        q.pop();

        if(node.id==endx)
        {
            layer=node.layer;
            break;
        }

        Node *head=node.next;
        while(head!=NULL)
        {
            if(vb[head->id])
            {
                head=head->next;
                continue;
            }
            vb[head->id]=true;
            vn[head->id].layer=node.layer+1;
            q.push(vn[head->id]);
            head=head->next;
        }
    }

    while(!q.empty())
        q.pop();

    return layer;
}

int main()
{
    string str[]={"hot","dot","dog","lot","log","cog"};
    vector<string> vecstr;
    for(int i=0;i<6;i++)
        vecstr.push_back(str[i]);
    cout<<ladderLength("hit","cog",vecstr)<<endl;
    return 0;
}
#endif // 1
