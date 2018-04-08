#if 0
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> trie;

    void initTrie()
    {
        vector<int> vi(27,-1);
        trie.push_back(vi);
    }

    void insertWord(string word)
    {
        int cur_index=0;
        for(int i=0;i<word.size();i++)
        {
            int cur_ch=word[i]-'a';
            if(trie[cur_index][cur_ch]==-1)
            {
                vector<int> vi(27,-1);
                trie.push_back(vi);
                trie[cur_index][cur_ch]=trie.size()-1;
            }
            cur_index=trie[cur_index][cur_ch];
        }
        trie[cur_index][26]=0;
    }


    string searchWord(string word)
    {
        int cur_index=0;
        for(int i=0;i<word.size();i++)
        {
            int cur_ch=word[i]-'a';
            if(trie[cur_index][26]==0)
                return word.substr(0,i);
            if(trie[cur_index][cur_ch]==-1)
                return word;
            cur_index=trie[cur_index][cur_ch];
        }
        return word;
    }

    string replaceWords(vector<string>& dict, string sentence) {
        initTrie();
        for(int i=0;i<dict.size();i++)
            insertWord(dict[i]);
        string str;
        size_t j=sentence.find(' ');
        for(int i=0;i<sentence.size();j=sentence.find(' ',i))
        {
            if(j==string::npos)
                j=sentence.size();
            if(j-i>=1)
            {
                string sub=sentence.substr(i,j-i);
                cout<<sub<<endl;
                if(str.size()!=0)
                    str+=' ';
                str+=searchWord(sub);
            }
            i=j+1;
        }
        return str;
    }
};

int main()
{
    string str="a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa";
    string strArray[]={"a", "aa", "aaa", "aaaa"};
    vector<string> vec;
    for(int i=0;i<4;i++)
        vec.push_back(strArray[i]);
    Solution solution;
    solution.replaceWords(vec,str);
    return 0;
}
#endif
