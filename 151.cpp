# if 0
#include <iostream>

using namespace std;

void reverseWords(string &s) {
        int len=s.size(),i;

        i=0;
        while(i<len&&s[i]!=' ')
            i++;

        while(i<len)
        {
            int j=i;
            while(j<len&&s[j]==' ')
                j++;

            if(j==len)
            {//if j==len, only i-j all is space
                s[i]='\0';
                s.resize(i);
                break;
            }

            int sub=j-i-1;
            if(i==0)
                sub+=1;

            if(sub==0)
            {
                while(j<len&&s[j]!=' ')
                    j++;
            }
            else{
                while(j<len&&s[j]!=' ')
                {
                    s[j-sub]=s[j];
                    s[j]=' ';
                    j++;
                }
            }
            i=j-sub;
        }

        len=s.size();
        for(int i=0;i<len/2;i++)
        {
            char temp=s[i];
            s[i]=s[len-i-1];
            s[len-i-1]=temp;
        }

        size_t prePos=0,nextPos;

        bool flag=true;

        if(s.size()<=0)
            flag=false;

        while(flag)
        {
            if((nextPos=s.find(' ',prePos))==string::npos)
            {
                nextPos=s.size();
                flag=false;
            }
            for(int i=prePos;i<(nextPos+prePos)/2;i++)
            {
                char temp=s[i];
                s[i]=s[nextPos-i+prePos-1];
                s[nextPos-i+prePos-1]=temp;
            }
            prePos=nextPos+1;
        }
}

int main()
{
    string s("hello world!");
    reverseWords(s);
    cout<<s<<endl;
    return 0;
}

/*比较优的解法*/
/*
void reverseWords(string &a) {
    int i = 0, j = 0;
        int n=a.length();

    while (j < n) {
      while (j < n && a[j] == ' ') j++;             // skip spaces
      while (j < n && a[j] != ' ') a[i++] = a[j++]; // keep non spaces
      while (j < n && a[j] == ' ') j++;             // skip spaces
      if (j < n) a[i++] = ' ';                      // keep only one space
    }

     a.erase(a.begin()+i, a.end());

        n=a.length();
        i=0;
        j=0;
        while(j<n){
            while(j<n&&a[j]!=' ') j++;
            rev(a, i, j-1);
            j++;
            i=j;
        }

        rev(a, 0, n-1);


    }

    void rev(string &a, int lo, int hi){
        while(lo<hi){
            swap(a[lo], a[hi]);
            lo++;
            hi--;
        }
    }*/
# endif // 1
