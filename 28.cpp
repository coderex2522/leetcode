#if 0
#include <iostream>
#include <vector>

using namespace std;

void getNextArray(string str,vector<int> &next)
{
    next.push_back(-1);
    int k=-1,j=0;
    while(j<str.size()-1)
    {
        if(k==-1||str[k]==str[j])
        {
            ++k;
            ++j;
            next.push_back(k);
        }
        else
            k=next[k];
    }
}

int strStr(string haystack, string needle)
{
    vector<int> next;
    getNextArray(needle,next);
    int i,j;
    i=j=0;
    int leni=haystack.size();
    int lenj=needle.size();
    while(i<leni&&j<lenj)
    {
        if(j==-1||haystack[i]==needle[j])
        {
            i++;
            j++;
        }
        else
            j=next[j];
    }

    if(j==needle.size())
        return i-j;
    else
        return -1;
}

int main()
{
    string hay="hello",needle="ll";
    cout<<strStr("","")<<endl;
    return 0;
}
#endif // 1
