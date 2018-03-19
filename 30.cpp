#if 0
#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> findSubstring(string s, vector<string>& words)
{
    vector<int> vi(s.size(),-1);
    vector<int> vb(words.size(),0);
    map<string,int> m;
    map<string,int>::iterator mi;
    vector<int> res;

    for(int i=0;i<words.size();i++)
    {
        mi=m.find(words[i]);
        if(mi==m.end())
            m[words[i]]=1;
        else
        {
            m[words[i]]++;
            continue;
        }

        size_t pos=0;
        while(pos!=string::npos)
        {
            pos=s.find(words[i],pos);
            if(pos!=string::npos)
            {
                vi[pos]=i;
                pos+=1;
            }
        }
    }

    for(int i=0;i<s.size();i++)
    {
        if(vi[i]==-1)
            continue;
        for(int j=0;j<words.size();j++)
            vb[j]=0;
        int cnt=0;
        for(int j=i;j<s.size();j+=words[0].size())
        {
            if(vi[j]==-1)
                break;
            vb[vi[j]]++;
            if(vb[vi[j]]>m[words[vi[j]]])
                break;
            else
                cnt++;
            if(cnt==words.size())
                break;
        }

        if(cnt==words.size())
            res.push_back(i);

    }

    return res;
}

int main()
{
    string str[]={"word","good","best","good"};
    vector<string> vecstr;

    for(int i=0;i<4;i++)
        vecstr.push_back(str[i]);
    findSubstring("wordgoodgoodgoodbestword",vecstr);
    return 0;
}
#endif // 1
