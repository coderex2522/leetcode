#if 0
#include <iostream>
#include <vector>

using namespace std;
//�����㷨ֻ�����뵥�����������,��ȫ����������,����ȫ�����Ǹ���.
void radixsort(vector<int> &nums)
{
    vector<int> v[10];
    int digit=1;
    int maxx;//�����洢�����Ǹ���,ȷ������λ��;

    if(nums.size()==0)
        return ;

    maxx=nums[0];
    for(int i=1;i<nums.size();i++)
    {
        if(maxx<nums[i])
            maxx=nums[i];
    }



}
int main()
{
    return 0;
}
#endif // 1
