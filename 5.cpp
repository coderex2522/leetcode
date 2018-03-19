#if 0
#include <iostream>
#include <string>

using namespace std;

string longestPalindrome(string s)
{
    int longest=0;
    int center=0;
    if(s.size()==0)
        return "";
    for(int i=0;i<s.size();i++)
    {
        int len=0;
        for(int j=1;(i-j>=0)&&(i+j<s.size());j++)
        {
            if(s[i-j]!=s[i+j])
                break;
            len++;
        }
        if(len*2+1>longest)
        {
            center=i;
            longest=2*len+1;
        }

        len=0;
        for(int j=0;(i-j>=0)&&(i+j+1<s.size());j++)
        {
            if(s[i-j]!=s[i+j+1])
                break;
            len++;
        }

        if(len*2>longest)
        {
            center=i;
            longest=2*len;
        }
    }

    if(longest%2)
        return s.substr(center-(longest-1)/2,longest);
    else
        return s.substr(center-(longest/2)+1,longest);
}

int main()
{
    cout<<longestPalindrome("cbbd")<<endl;
    return 0;
}
#endif // 1
