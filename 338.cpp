#if 0
#include <iostream>
#include <vector>

using namespace std;

vector<int> countBits(int num)
{
    vector<int> res(num+1,0);

    for(int i=1;i<=num;i++)
    {
        res[i]=res[i&(i-1)]+1;
    }

    return res;
}

int main()
{
    vector<int> res=countBits(5);
    for(int i=0;i<=5;i++)
        cout<<res[i]<<" ";
    return 0;
}
#endif // 1
