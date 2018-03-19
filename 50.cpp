#if 0
#include <iostream>
//注意负数转为正数，>>1可能还是负数。太大了
using namespace std;

double solve(double x, int n)
{
    double res;
    if(n==0)
        return 1.0;
    if(n<0)
        n=-1*n;

    res=solve(x, n>>1);
    res=res*res;
    if(n%2)
        res*=x;

    return res;
}

double myPow(double x, int n)
{
    bool flag=true;
    if(n<0)
        flag=false;

    if(flag)
        return solve(x, n);
    else
        return 1/solve(x,n);

}

int main()
{
    cout<<myPow(2.00000,10);
    return 0;
}
#endif // 1
