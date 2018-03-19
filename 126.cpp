#if 0
#include <iostream>
#include <vector>
#include <map>

using namespace std;
typedef struct Node{
    int id;
    struct Node *next;
}Node;

vector<bool> flag;
vector<vector<int> > resInt;
int minx=-1;

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

void DFS(vector<int> &minres, vector<Node> vn, int curx, int endx, int cnt)
{
    minres.push_back(curx);
    if(curx==endx)
    {
        if(minx!=-1&&cnt<minx)
        {
            resInt.clear();
            resInt.push_back(minres);
            minx=cnt;
        }
        else if(minx==-1||cnt==minx)
        {
            resInt.push_back(minres);
            minx=cnt;
        }
        minres.pop_back();
        return ;
    }

    Node *head=vn[curx].next;
    while(head!=NULL)
    {
        if(flag[head->id])
        {
            head=head->next;
            continue;
        }
        flag[head->id]=true;
        DFS(minres, vn, head->id, endx, cnt+1);
        flag[head->id]=false;
        head=head->next;
    }
    minres.pop_back();
}

vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList)
{
    vector<Node> vn;
    for(int i=0;i<=wordList.size();i++)
    {
        Node tmp;
        tmp.id=i;
        tmp.next=NULL;
        vn.push_back(tmp);
        flag.push_back(false);
    }

    int endx;
    for(int i=0;i<=wordList.size();i++)
    {
        string cmpa;
        if(i==0)
            cmpa=beginWord;
        else
            cmpa=wordList[i-1];

        if(cmpa==endWord)
            endx=i;

        if(i!=0&&cmpa==beginWord)
            continue;

        for(int j=i;j<wordList.size();j++)
        {
            if(isLink(cmpa,wordList[j]))
            {
                Node *tmp;
                if(cmpa!=endWord)
                {
                    tmp=new Node();
                    tmp->id=j+1;
                    tmp->next=vn[i].next;
                    vn[i].next=tmp;
                    continue;
                }
                if(cmpa!=beginWord||cmpa==endWord)
                {
                    tmp=new Node();
                    tmp->id=i;
                    tmp->next=vn[j+1].next;
                    vn[j+1].next=tmp;
                    continue;
                }
            }
        }
    }

    /*for(int i=0;i<vn.size();i++)
    {
        Node *head=vn[i].next;
        cout<<i<<"  ";
        while(head!=NULL)
        {
            cout<<wordList[head->id-1]<<"   ";
            head=head->next;
        }
        cout<<endl;
    }*/


    vector<int> minres;
    DFS(minres, vn, 0, endx, 0);
    vector<vector<string> > res;
    for(int i=0;i<resInt.size();i++)
    {
        vector<string> vecstr;
        vecstr.push_back(beginWord);
        for(int j=1;j<resInt[i].size();j++)
        {
            vecstr.push_back(wordList[resInt[i][j]-1]);
        }
        res.push_back(vecstr);
    }

    return res;
}

int main()
{
    string str[]={"hot","dog","dot"};
    vector<string> vecstr;
    for(int i=0;i<3;i++)
        vecstr.push_back(str[i]);
    findLadders("hot","dog",vecstr);
    return 0;
}
#endif
