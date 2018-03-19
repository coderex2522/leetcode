#if 0
#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

typedef struct Node{
    int first;
    int second;
    int cnt;
}Node;

int atom[27][27];

string countOfAtoms(string formula) {
    stack<Node> sn;
    int i,len=formula.size();
    string res;
    memset(atom,0,sizeof(atom));

    i=0;
    while(i<len)
    {
        Node node;
        if(formula[i]<='Z'&&formula[i]>='A')
        {
            node.first=formula[i]-'A'+1;
            i++;
            if(i<len&&formula[i]<='z'&&formula[i]>='a')
            {
                node.second=formula[i]-'a'+1;
                i++;
            }
            else
                node.second=0;

            node.cnt=0;
            while(i<len&&formula[i]>='0'&&formula[i]<='9')
            {
                node.cnt=node.cnt*10+formula[i]-'0';
                i++;
            }
            if(node.cnt==0)
                node.cnt=1;
            sn.push(node);
        }
        else if(formula[i]=='(')
        {
            i++;
            node.cnt=0;
            node.first=0;
            node.second=0;
            sn.push(node);
        }
        else if(formula[i]==')')
        {
            i++;
            node.cnt=0;
            while(i<len&&formula[i]>='0'&&formula[i]<='9')
            {
                node.cnt=node.cnt*10+formula[i]-'0';
                i++;
            }
            if(node.cnt==0)
                node.cnt=1;

            stack<Node> tmp;
            Node tmpNode=sn.top();
            while(tmpNode.cnt!=0)
            {
                tmpNode.cnt*=node.cnt;
                tmp.push(tmpNode);
                sn.pop();
                tmpNode=sn.top();
            }
            sn.pop();
            while(!tmp.empty())
            {
                tmpNode=tmp.top();
                sn.push(tmpNode);
                tmp.pop();
            }
        }

    }

    while(!sn.empty())
    {
        Node node=sn.top();
        atom[node.first][node.second]+=node.cnt;
        sn.pop();
    }

    char buf[15];
    for(i=1;i<27;i++)
        for(int j=0;j<27;j++)
        {
            if(atom[i][j])
            {
                res.append(1,'A'+i-1);
                if(j!=0)
                    res.append(1,'a'+j-1);
                if(atom[i][j]!=1)
                {
                    int k=0;
                    while(atom[i][j]!=0)
                    {
                        buf[k++]=atom[i][j]%10+'0';
                        atom[i][j]/=10;
                    }
                    k--;
                    while(k>=0)
                    {
                        res.append(1,buf[k]);
                        k--;
                    }
                }
            }

        }

    return res;
}

int main()
{
    string formula("K4(ON(SO3)2)2");
    cout<<countOfAtoms(formula)<<endl;
    return 0;
}
#endif // 1
