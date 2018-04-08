#if 0
#include <iostream>
#include <vector>

using namespace std;

class Trie {
public:
    vector<vector<int>> dm;

    /** Initialize your data structure here. */
    Trie() {
        vector<int> v(27,-1);
        dm.push_back(v);
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        int cur_index=0;
        for(int i=0;i<word.size();i++)
        {
            int cur_ch=word[i]-'a';
            if(dm[cur_index][cur_ch]==-1)
            {
                vector<int> v(27,-1);
                dm.push_back(v);
                dm[cur_index][cur_ch]=dm.size()-1;
            }
            cur_index=dm[cur_index][cur_ch];
        }
        dm[cur_index][26]=0;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        int cur_index=0;
        for(int i=0;i<word.size();i++)
        {
            int cur_ch=word[i]-'a';
            if(dm[cur_index][cur_ch]==-1)
                return false;
            cur_index=dm[cur_index][cur_ch];
        }
        if(dm[cur_index][26]==0)
            return true;
        else
            return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int cur_index=0;
        for(int i=0;i<prefix.size();i++)
        {
            int cur_ch=prefix[i]-'a';
            if(dm[cur_index][cur_ch]==-1)
                return false;
            cur_index=dm[cur_index][cur_ch];
        }
        return true;
    }
};

int main()
{
    string word="hello";
    Trie* obj = new Trie();
    obj->insert(word);
    cout<<obj->search("helloo")<<endl;
    cout<<obj->startsWith("hel")<<endl;
    return 0;
}
#endif // 1
