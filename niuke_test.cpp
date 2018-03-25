#if 0
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
long long solve(char *a)
{
    int len=strlen(a);
    for(int i=0;i<4;i++)
    {
        if(i<len)
            continue;
        a[i]='0';
    }
    a[4]='\0';

    long long cnt=0;
    int q=0;
    for(int i=3;i>=0;i--)
    {
        q=1+25*q;
        if(a[i]=='0')
            continue;
        cnt+=(a[i]-'a')*q;
        cnt+=1;
    }
    return cnt-1;
}

int main()
{
    char str[100];

    while(cin>>str)
    {
        cout<<solve(str)<<endl;
    }
    return 0;
}
#endif // 1
