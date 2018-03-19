#if 0
//the code don't solve this problem well;
#include <iostream>
#include <string>

using namespace std;

int myAtoi(string str)
{
    const int INI_MAX=2147483647;
    const int INI_MIN=-2147483648;

    int num=0,cnt=0,cntDigit=0,first;
    bool flag=true;//default str stand for the number is positive.
    bool flagWhiteSpace=true;

    for(string::iterator it=str.begin();it!=str.end();it++)
    {
        if(cnt>1)
            return 0;

        if(*it==' '&&flagWhiteSpace)
            continue;
        else if(*it==' '&&!flagWhiteSpace)
            break;
        else
        {
            flagWhiteSpace=false;
            if(*it=='-')
            {
                flag=!flag;
                cnt++;
            }
            else if(*it=='+')
                cnt++;
            else if(*it>='0'&&*it<='9')
            {
                if(*it=='0'&&!cntDigit)
                    continue;
                if(!cntDigit)
                    first=*it-'0';
                cntDigit++;
                if(cntDigit>10||(cntDigit==10&&first>2))
                {
                    if(flag)
                        num=INI_MAX;
                    else
                        num=INI_MIN;
                    break;
                }

                int temp=num*10+*it-'0';
                if(flag&&(temp>=INI_MAX||temp<0||temp<num))
                {
                    num=INI_MAX;
                    break;
                }
                if(!flag&&(temp*(-1)<INI_MIN||temp*(-1)>0))
                {
                    num=INI_MIN;
                    break;
                }

                num=num*10+*it-'0';

            }
            else
                break;
        }
    }


    if(flag)
        return num;
    else
        return num*(-1);
}


int main()
{
    cout<<myAtoi("-2147483648")<<endl;
    return 0;
}
#endif // 1
