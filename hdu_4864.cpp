#if  0
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


const int MAXN=100005;

typedef struct Node{
    int time;
    int level;
}Node;

Node noden[MAXN],nodem[MAXN];
bool cmp(Node a,Node b)
{
    if(a.time==b.time)
        return a.level>b.level;
    return a.time>b.time;
    //return a.time*500+a.level*2>b.time*500+2*b.level;
}

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++)
            scanf("%d%d",&noden[i].time,&noden[i].level);
        for(int i=0;i<m;i++)
            scanf("%d%d",&nodem[i].time,&nodem[i].level);

        sort(noden,noden+n,cmp);
        sort(nodem,nodem+m,cmp);

        int  cnt=0,j=0;
        long long  money=0;
        vector<int> cnt_level(101,0);

        for(int i=0;i<m;i++)
        {
            while(j<n&&nodem[i].time<=noden[j].time)
            {
                cnt_level[noden[j].level]++;
                j++;
            }

            for(int k=nodem[i].level;k<=100;k++)
            {
                if(cnt_level[k]>0)
                {
                    cnt_level[k]--;
                    money+=500*nodem[i].time+2*nodem[i].level;
                    cnt++;
                    break;
                }
            }
        }
        printf("%d %I64d\n",cnt,money);
    }
    return 0;
}
#endif // 1
