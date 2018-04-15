#if 0
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>

using namespace std;
bool mycmp(string a,string b)
{
    if(a.size()==b.size())
        return a<b;
    return a.size()<b.size();
}
bool searchString(string pa,string child)
{
    int pi=0,ci=0;
    while(pi<pa.size()&&ci<child.size())
    {
        if(pa[pi]==child[ci])
        {
            pi++;
            ci++;
        }
        else
            pi++;
    }
    if(ci==child.size())
        return true;
    return false;
}

int findLUSlength(vector<string>& strs)
{
    unordered_map<string,int> um;
    for(auto str:strs)
        um[str]++;
    vector<string> vs;
    for(auto i=um.begin();i!=um.end();i++)
        vs.push_back(i->first);
    sort(vs.begin(),vs.end(),mycmp);

    for(int i=vs.size()-1;i>=0;i--)
    {
        if(um[vs[i]]!=1)
            continue;
        bool flag=false;
        for(int j=i+1;j<vs.size();j++)
            if(searchString(vs[j],vs[i]))
            {
                flag=true;
                break;
            }

        if(!flag)
            return vs[i].size();
    }
    return -1;
}
int main()
{
    vector<string> vec;
    vec.push_back("aabbcc");
    vec.push_back("aabbcc");
    vec.push_back("cb");
    vec.push_back("abc");
    cout<<findLUSlength(vec)<<endl;
    return 0;
}

/**algorithm is wrong, only think about the other string is prefix.
vector<vector<int>> trie;

void initTrie()
{
    vector<int> tmp(27,-1);
    trie.push_back(tmp);
}
void insertString(string a)
{
    int cur_index=0;
    for(int i=0;i<a.size();i++)
    {
        int cur_char=a[i]-'a';
        if(trie[cur_index][cur_char]==-1)
        {
            vector<int> tmp(27,-1);
            trie.push_back(tmp);
            trie[cur_index][cur_char]=trie.size()-1;
        }
        cur_index=trie[cur_index][cur_char];
    }
    trie[cur_index][26]--;
}

bool searchString(string a)
{
    int cur_index=0;
    for(int i=0;i<a.size();i++)
        cur_index=trie[cur_index][a[i]-'a'];
    for(int i=0;i<26;i++)
        if(trie[cur_index][i]>=0)
            return true;
    if(trie[cur_index][26]<-2)
        return true;
    return false;
}

int findLUSlength(vector<string>& strs)
{
    vector<string> vvs[11];
    initTrie();
    for(auto i:strs)
    {
        if(i.size()!=0)
            insertString(i);
        vvs[i.size()].push_back(i);
    }

    for(int i=10;i>=0;i--)
        for(int j=0;j<vvs[i].size();j++)
        {
            if(i==0)
                return 0;
            if(!searchString(vvs[i][j]))
                return i;
        }
    return -1;
}
*/
#endif // 1
