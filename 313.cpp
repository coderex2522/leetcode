#if 0
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int nthSuperUglyNumber(int n, vector<int>& primes)
{
    vector<int> index(primes.size(),0),vec;
    vec.push_back(1);
    int cnt=1;
    while(cnt<n)
    {
        int minx=INT_MAX;
        for(int i=0;i<primes.size();i++)
            minx=min(minx,primes[i]*vec[index[i]]);
        vec.push_back(minx);
        cnt++;
        for(int i=0;i<primes.size();i++)
            while(primes[i]*vec[index[i]]<=minx)
                index[i]++;
    }

    return vec[vec.size()-1];
}

int main()
{
    vector<int> primes;
    primes.push_back(2);
    primes.push_back(7);
    primes.push_back(13);
    primes.push_back(19);
    cout<<nthSuperUglyNumber(12,primes)<<endl;
    return 0;
}
/*Time Limit*/
/*
int nthSuperUglyNumber(int n, vector<int>& primes)
{
    vector<int> vec;
    int cnt=1,cur,primes_len;
    vec.push_back(1);
    primes_len=primes.size();
    cur=0;
    while(cnt<n)
    {
        if(vec[cur]*primes[primes_len-1]<=vec[vec.size()-1])
        {
            cur++;
            continue;
        }
        else
        {
            int minx=vec[cur]*primes[primes_len-1];
            int max_primes=primes_len;
            for(int i=cur;i<vec.size();i++)
            {
                if(vec[i]*primes[0]>minx)
                    break;
                for(int j=0;j<max_primes;j++)
                {
                    int tmp=vec[i]*primes[j];
                    if(tmp>vec[vec.size()-1]&&tmp<minx)
                    {
                        minx=tmp;
                        max_primes=j;
                        break;
                    }
                }
            }
            vec.push_back(minx);
            cnt++;
        }
    }

    return vec[vec.size()-1];
}
*/
#endif // 1
