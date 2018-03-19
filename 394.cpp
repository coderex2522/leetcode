#if 0
#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

string decodeString(string s)
{
    stack<char> sc;
    int i=s.size()-1;
    string res;
    int cntRight=0;

    while(i>=0)
    {
         if(s[i]=='[')
        {
            cntRight--;
            i--;
            string tmpStr;
            char tmp=sc.top();
            while(tmp!=']')
            {
                tmpStr.append(1,tmp);
                sc.pop();
                tmp=sc.top();
            }
            sc.pop();
            int cnt=0,digit=1;
            while(i>=0&&s[i]>='0'&&s[i]<='9')
            {
                cnt+=(s[i]-'0')*digit;
                digit*=10;
                i--;
            }

            if(sc.empty()||sc.size()==0)
            {
                for(int j=0;j<cnt;j++)
                    res=tmpStr+res;
            }
            else
            {
                for(int j=0;j<cnt;j++)
                    for(int k=tmpStr.size()-1;k>=0;k--)
                        sc.push(tmpStr[k]);
            }
        }
        else if(s[i]==']'&&cntRight==0&&!sc.empty())
        {
            string tmpStr;
            while(!sc.empty())
            {
                char tmp=sc.top();
                sc.pop();
                tmpStr.append(1,tmp);
            }
            res=tmpStr+res;
            sc.push(s[i]);
            cntRight++;
            i--;
        }
        else{
            if(s[i]==']')
                cntRight++;
            sc.push(s[i]);
            i--;
        }
    }
    if(!sc.empty())
    {
        string tmpStr;
        while(!sc.empty())
        {
            char tmp=sc.top();
            sc.pop();
            tmpStr.append(1,tmp);
        }
        res=tmpStr+res;
    }

    return res;
}

int main()
{
    string s("leetcode");
    cout<<decodeString(s)<<endl;
    return 0;
}
#endif // 1
