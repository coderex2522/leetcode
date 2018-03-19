#if 0
//stupid method accept
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

typedef struct Node{
    int val;
    int leftval;//val/digit;
    int digit;
    Node(int val, int leftval, int digit):val(val),leftval(leftval),digit(digit){}
}Node;

string largestNumber(vector<int>& nums)
{
    vector<Node> vn;
    vector<Node> res;
    string resStr;

    for(int i=0;i<nums.size();i++)
        vn.push_back(Node(nums[i],0,0));

    int digit=1,cnt=0;
    while(cnt<vn.size())
    {
        digit*=10;
        for(int i=0;i<vn.size();i++)
        {
            if(vn[i].digit!=0)
                continue;

            if(vn[i].val/digit==0)
            {
                cnt++;
                vn[i].digit=digit/10;
                vn[i].leftval=vn[i].val/(digit/10);
            }
        }
    }
    digit/=10;

    int curdigit=1;
    vector<Node> bucket[10];
    while(curdigit<=digit)
    {
        for(int i=0;i<vn.size();i++)
        {
            if(curdigit>=(digit/vn[i].digit))
            {
                int tmp=vn[i].val/(curdigit/(digit/vn[i].digit))%10;
                bucket[tmp].push_back(vn[i]);
            }
            else
                bucket[vn[i].leftval].push_back(vn[i]);
        }

        vn.clear();
        for(int i=9;i>=0;i--)
        {
            if(curdigit==digit)
            {
                for(int j=1;j<bucket[i].size();j++)
                {
                    if(bucket[i][j-1].val*10+bucket[i][j-1].leftval==bucket[i][j].val)
                    {
                        int tmpdigit=bucket[i][j-1].digit,tmp=bucket[i][j-1].val;
                        bool flag=false;
                        while(tmpdigit!=0)
                        {
                            int cur=tmp/tmpdigit%10;
                            if(cur<bucket[i][j-1].leftval)
                            {
                                flag=true;
                                break;
                            }
                            if(cur>bucket[i][j-1].leftval)
                                break;
                            tmpdigit/=10;
                        }
                        if(flag)
                        {
                            bucket[i][j-1].val=bucket[i][j].val;
                            bucket[i][j].val=tmp;
                        }
                    }
                    if(bucket[i][j].val*10+bucket[i][j].leftval==bucket[i][j-1].val)
                    {
                        int tmpdigit=bucket[i][j].digit,tmp=bucket[i][j].val;
                        bool flag=false;
                        while(tmpdigit!=0)
                        {
                            int cur=tmp/tmpdigit%10;
                            if(cur<bucket[i][j].leftval)
                                break;
                            if(cur>bucket[i][j].leftval)
                            {
                                flag=true;
                                break;
                            }
                            tmpdigit/=10;
                        }
                        if(flag)
                        {
                            bucket[i][j].val=bucket[i][j-1].val;
                            bucket[i][j-1].val=tmp;
                        }
                    }
                }
            }
            for(int j=0;j<bucket[i].size();j++)
            {
                vn.push_back(bucket[i][j]);

            }
            bucket[i].clear();
        }

        curdigit*=10;
    }

    ostringstream oss;
    for(int i=0;i<vn.size();i++)
    {
        oss<<vn[i].val;
        if(i==0&&vn[i].val==0)
            break;

    }
    return oss.str();
}

int main()
{
    int a[]={0,0};
    vector<int> vi;
    for(int i=0;i<2;i++)
        vi.push_back(a[i]);
    cout<<largestNumber(vi)<<endl;
    return 0;
}
#endif // 1
