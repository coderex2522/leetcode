#if 0
//时间复杂度并不符合题意要求
#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef struct Node{
    string s;
    struct Node *next;
    Node(string s,struct Node *next):s(s),next(next){}
}Node;

struct classcomp {
  bool operator() (const int& lhs, const int& rhs) const
  {return lhs>rhs;}
};

struct classcmpstr {
  bool operator() (const string& lhs, const string& rhs) const
  {return lhs>rhs;}
};

vector<string> topKFrequent(vector<string>& words, int k)
{
    vector<string> res;

    map<string,int,classcmpstr> msi;
    map<string,int>::iterator it;

    for(int i=0;i<words.size();i++)
    {
        it=msi.find(words[i]);
        if(it!=msi.end())
            msi[words[i]]++;
        else
            msi[words[i]]=1;
    }

    map<int,Node*,classcomp> minptr;
    map<int,Node*>::iterator it_inptr;

    it=msi.begin();
    while(it!=msi.end())
    {
        it_inptr=minptr.find(it->second);
        if(it_inptr==minptr.end())
        {
            Node *node=new Node(it->first,NULL);
            minptr[it->second]=node;
        }
        else
        {
            Node *node=new Node(it->first,it_inptr->second);
            minptr[it->second]=node;
        }
        it++;
    }

    it_inptr=minptr.begin();
    int cnt=0;
    while(it_inptr!=minptr.end())
    {
        Node *head=it_inptr->second;
        while(head!=NULL&&cnt<k)
        {
            res.push_back(head->s);
            cnt++;
            head=head->next;
        }

        head=it_inptr->second;
        while(head!=NULL)
        {
            Node *tmp=head;
            head=head->next;
            delete tmp;
        }
        it_inptr++;
    }

    minptr.clear();
    return res;
}

int main()
{
    string str[]={"i", "love", "leetcode", "i", "love", "coding"};
    vector<string> vecstr;
    for(int i=0;i<6;i++)
    {
        vecstr.push_back(str[i]);
    }
    topKFrequent(vecstr,0);
    return 0;
}
#endif // 1
