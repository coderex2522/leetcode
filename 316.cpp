#if 0
#include <iostream>
#include <string>
#include <stack>

using namespace std;

string removeDuplicateLetters(string s)
{
    stack<char> sc;
    int cnt[26]={0};
    bool flag[26]={false};
    for(int i=0;i<s.size();i++)
        cnt[s[i]-'a']++;

    for(int i=0;i<s.size();i++)
    {
        if(flag[s[i]-'a'])
        {
            cnt[s[i]-'a']--;
            continue;
        }

        if(sc.empty())
            sc.push(s[i]);
        else
        {
            char ctop=sc.top();
            while(cnt[ctop-'a']>1&&s[i]<ctop)
            {
                cnt[ctop-'a']--;
                flag[ctop-'a']=false;
                sc.pop();
                if(sc.empty())
                    break;
                ctop=sc.top();
            }
            sc.push(s[i]);
        }
        flag[s[i]-'a']=true;
    }
    string str(sc.size(),'\0');
    for(int i=str.size()-1;i>=0;i--)
    {
        str[i]=sc.top();
        sc.pop();
    }
    return str;
}


int main()
{
    string str="ccacbaba";
    cout<<removeDuplicateLetters(str)<<endl;
    return 0;
}
#endif // 1
