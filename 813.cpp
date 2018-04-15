#if 0
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

double largestSumOfAverages(vector<int>& A, int K)
{
    vector<double> total;
    vector<vector<double>> f(A.size()+1,vector<double>(K+1,0));

    double sum=0;
    for(int i=0;i<A.size();i++)
    {
        total.push_back(sum);
        sum+=A[i];
    }
    total.push_back(sum);


    for(int i=1;i<=A.size();i++)
        for(int j=1;j<=i&&j<=K;j++)
        {
            if(j==1)
            {
                f[i][j]=total[i]/i;
                continue;
            }
            double maxx=0;
            for(int m=j-1;m<i;m++)
                if(maxx<f[m][j-1]+(total[i]-total[m])/(i-m))
                    maxx=f[m][j-1]+(total[i]-total[m])/(i-m);
            f[i][j]=maxx;
        }

    return f[A.size()][K];
}

int main()
{
    vector<int> vec={1,2,3,4,5,6,7};
    cout<<largestSumOfAverages(vec,4)<<endl;
    return 0;
}
#endif // 1
