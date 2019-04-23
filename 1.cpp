//�Ӹ������������ҵ�����������ҵ���У���������ޡ�����ͻ���ʱ��Ĺ���
#include<iostream>
#include<algorithm>//������C++�е�sort����
#define min(a,b) ((a)<(b))?(a):(b)

using namespace std;

// Job�Ľṹ
struct Job
{
   char id;      // ���� Id
   int dead;    // ������deadline
   int profit; // ��deadline֮ǰ���ʱ�������Ļ���
   int cost;  // ������cost
   int value;
};

 
 
// �˺������ڸ���һ����������ֹ���ڶ�������ҵ���������Ȱ�value�������У����value��ͬ���ٰ�dead�������С�
bool comparison(Job a, Job b)
{
	if(a.value!=b.value)
		return (a.value > b.value);
	else
		return (a.dead < b.dead);
}
 
//����ƽ̨�������С��Ŀ
void printJobScheduling(Job arr[], int n, int max)
{
    // ����compare������������ҵ��������Sort(���鿪ʼλ��start,�������λ��end,���򷽷���Ĭ�ϴ�С�������Ҫ�Ӵ�С�ţ�ʹ��compare����)
	sort(arr, arr+n, comparison);//��ʹarr+nд��arr+1Ҳ��������˵���ڶ��������ǲ����������
	int* result = new int[n]; // �洢���(��ҵ����)
    bool* slot = new bool[max];  // ���ٿ���ʱ��
	int r=0;
 
    // ��ʼ������λ��Ϊ����
    for (int i=0; i<max; i++)
        slot[i] = false;
 
    // �������и�������ҵ
    for (i=0; i<n; i++)
	{
		int sum_cost=0;
		//���źõĹ������ĵ�ʱ���
		if(i>0)
		{
			for(int k=0; k<i; k++)
			{
				sum_cost=sum_cost+arr[k].cost;
			}
		}

		//�ж����ӵ������Ƿ����֮ǰ��������ͻ��û�������򽫽������result�У������ռ�õ�ʱ�䵥λ
		if(slot[sum_cost]==false && sum_cost+arr[i].cost<=arr[i].dead)
		{
			result[r]=i;
			r++;
			for(int j=sum_cost; j<sum_cost+arr[i].cost; j++)
			{
				slot[j] = true;
			}
		}
	}


    // �����
    for (i=0; i<n; i++)
       if (slot[i])
         cout << arr[result[i]].id << " ";
}

int main()
{
	int profit,cost;
    int value=profit/cost;
	//����Ϊid, dead, profit, cost
	Job arr[] = { {'1', 10, 2, 4}, {'2', 8, 3, 3}, {'3', 4, 3, 2},{'4', 2, 6, 1}};
	//ȷ����������
    int n = sizeof(arr)/sizeof(arr[0]);
	//�����������ʱ��ռ�
	int max=arr[0].dead;
	for (int i=0;i<n;i++)
		if(max<arr[i].dead)
			max=arr[i].dead;
	//������
    cout << "Following is maximum profit sequence of jobs\n";
    printJobScheduling(arr, n, max);
    return 0;
}
