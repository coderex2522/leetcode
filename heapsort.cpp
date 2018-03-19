#if 0
#include <iostream>
#include <vector>

using namespace std;

void adjustHeap(vector<int> &heap, int len)
{
    int i=0,tmp;
    while(i<len)
    {
        if(2*i+1<len)
        {
            tmp=heap[i];
            heap[i]=heap[2*i+1];
            heap[2*i+1]=tmp;
            i=2*i+1;
            continue;
        }
        if(2*i+2<len)
        {
            tmp=heap[i];
            heap[i]=heap[2*i+2];
            heap[2*i+2]=tmp;
            i=2*i+2;
            continue;
        }
        break;
    }
}

void insertElem(vector<int> &heap,int elem)
{

}
int findKthLargest(vector<int>& nums, int k)
{
    return 0;
}

int main()
{
    vector<int> num;
    num.push_back(10);
    cout<<num.size()<<endl;
    num.pop_back();
    cout<<num.size()<<endl;
    num.clear();
    cout<<num[0]<<endl;
    return 0;
}
#endif // 1
