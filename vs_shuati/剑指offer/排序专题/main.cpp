#include <iostream>
#include<vector>
#include <algorithm>
#include <typeinfo>
using namespace std;

//01ð������
void bubble_sort(int*input, int st, int ed)
{
	int lenth = ed - st + 1;
	for (int rindex = int(lenth - 1); rindex >= st; rindex--)//��ѭ����ȷ���ҽ�
	{
		for (int j = 0; j <= rindex-1; j++)//�������Ƚ�
		{
			if (input[j + 1]<input[j])
				swap(input[j], input[j + 1]);
		}
	}
}

//02ѡ������
void select_sort(int*input, int st, int ed)
{
	int lenth = ed - st + 1;
	for (int lindex = st; lindex <= int(lenth - 2); lindex++)//��ѭ����ȷ�����
	{
		int  minindex = lindex;
		for (int j = lindex; j <= lenth - 1; j++)//Ѱ��������絽���ҵ���Сֵ��
		if (input[j] < input[minindex])
			minindex = j;
		swap(input[lindex], input[minindex]);
	}
}

//03��������
void insert_sort(int*input, int st, int ed)
{
	int lenth = ed - st + 1;
	for (int lindex = st - 1; lindex <= int(lenth - 1); lindex++)//��ѭ����ȷ�����
	{
		for (int j = lindex; j >= 1; j--)//�������Ƚ�
		{
			if (input[j - 1] > input[j])
				swap(input[j - 1], input[j]);
			else
				break;
		}
	}
}

//04�鲢����
void merge_sort(int *input, int*temp, int st, int ed)
{
	if (ed <= st)return;
	int midindex = (st + ed) / 2;
	merge_sort(input, temp, st, midindex);
	merge_sort(input, temp, midindex + 1, ed);
	for (int i = st; i <= ed; i++)//�ݴ�����������Ľ��
		temp[i] = input[i];
	int lind = st, rind = midindex + 1;
	for (int i = st; i <= ed; i++)//�ϲ���������
	{
		if (lind <= midindex&&rind <= ed)//�����������鶼û������
			input[i] = temp[lind] < temp[rind] ? temp[lind++] : temp[rind++];
		else if (lind <= midindex)//��ֻʣ��ߵ�����
			input[i] = temp[lind++];
		else if (rind <= ed)//��ֻʣ�ұߵ�����
			input[i] = temp[rind++];
	}
}

//05��������
void quick_sort(int*input, int st, int ed)
{
	if (ed <= st)return;
	swap(input[st], input[ed]);
	int insert_index = st - 1;
	for (int i = st; i <= ed - 1; i++)
	if (input[i] < input[ed])
		swap(input[++insert_index], input[i]);
	swap(input[++insert_index], input[ed]);
	quick_sort(input, st, insert_index);
	quick_sort(input, insert_index + 1, ed);
}

int partition(int *p, int st, int ed)
{
	//swap(p[st], p[ed]);
	int insert_index = st;
	for (int i = st; i <= ed - 1; i++)
		if (p[i] < p[ed])swap(p[insert_index++], p[i]);
	swap(p[insert_index], p[ed]);
	return insert_index;
}
void quick_sort_par(int *p, int st, int ed)
{
	if (ed <= st)return;
	int index = partition(p, st, ed);
	quick_sort(p, st, index);
	quick_sort(p, index + 1, ed);
}




//06������
//https://www.cnblogs.com/chengxiao/p/6129630.html
//�����򲻿��ٶ�����ڴ棬�������������Ѷ�Ӧ�����������鿴��һ���߼��ṹ�ϵĶѣ���������ȫ�������������м������ԣ�����Ϊs�Ľڵ�����ӽڵ�Ϊ2*s+1,
//Ҷ�ڵ�����������Ҷ�ڵ�������Ȼ��1�����������ܳ���Ϊlenth�����Ҷ�ڵ���lenth/2����
//��һ���ǹ���󶥶ѣ�����˼·�Ǵ������ϡ���������ȥ�Է�Ҷ�ڵ㼰���������е�����ÿ�ε�����֤�ýڵ㼰��������Ϊ�󶥶ѣ�
//����1�ε������̣�����������ǽ��ýڵ����ӽڵ��д��ֵ���н�����ֱ�����ʵ�Ҷ�ڵ㡣
void heap_adj(int*input, int rootind, int maxind)
{
	while (1)
	{
		int nextind = rootind * 2 + 1;//����Դ�ڵ�����ӽڵ�
		if (nextind > maxind)break;//�����ӽڵ㳬����Χ���˳�
		if (nextind + 1 <= maxind&&input[nextind + 1] > input[nextind])//nexindָ��ϴ���ӽڵ�
			nextind++;
		if (input[rootind] >= input[nextind])break;//��Դ�ڵ�����ӽڵ����˳�����Ϊ�Ǵ������ϡ���������ȥ�Է�Ҷ�ڵ㼰���������е��������������Ѿ��Ǵ󶥶ѡ�
		swap(input[rootind], input[nextind]);//Դ�ڵ�����ӽڵ��򽻻�
		rootind = nextind;
	}
}
void heap_sort(int*input, int st, int ed)
{
	int lenth = ed - st + 1;
	for (int i = lenth / 2 - 1; i >= st; i--)//��ѭ��������󶥶�
	{
		heap_adj(input, i, lenth - 1);
	}
	for (int i = lenth - 1; i >= st; i--)//����ȷ����lenth-1��st��ֵ
	{
		swap(input[0], input[i]);//�ѶѶ�ֵ�뵱ǰ�����ڵ�ֵ����
		heap_adj(input, 0, i - 1);//�����Ӷ�Ϊ�󶥶ѣ�����i�Ľڵ㲻�������
	}
}

//07ϣ������
//���������ļ򵥲��Բ�ͬ��shell����ͨ�������εĲ����������Ч�ʣ�
void shell_sort(int*input, int st, int ed)
{
	int lenth = ed - st + 1;
	for (int step = lenth; step >= 1; step = step / 2)
	{
		for (int i = 0; i <= lenth - 1; i++)
		{
			for (int j = i; j - step >= 0; j -= step)
			{
				if (input[j] < input[j - step])
					swap(input[j], input[j - step]);
			}
		}
	}
}

//08��������
void countingsort(int*input, int st, int ed)
{
	int lenth = ed - st + 1;
	auto minmax = minmax_element(input+st,input+ed+1);
	int min = *minmax.first, max = *minmax.second;
	int *p_counts = new int[max - min + 1];//����������飬�������Ϊind����ֵ����Դ������ֵΪmin+ind��Ԫ�صĸ���
	memset(p_counts, 0, (max - min + 1)*sizeof(int) / sizeof(char));
	for (int i = 0; i <= lenth - 1; i++)//ִ�м���
		p_counts[input[i] - min]++;
	for (int i = 0, ind = 0; i <= max - min + 1 - 1; i++)//������������
	while (p_counts[i]--)
		input[ind++] = min + i;
	delete[]p_counts;
}
void CntSort(vector<int>&a)
{
	int ind=0,maxnum = *max_element(a.begin(),a.end());
	vector<int>hash(maxnum+1,0);
	for (int i = 0; i < a.size(); i++)
		hash[a[i]]++;
	for (int i = 0; i <= maxnum;i++)
		while (hash[i]--)
			a[ind++] = i;
}

void i_sort(vector<int>&a)
{
	for (int i = 1; i <=int(a.size() - 1); i++)
	{
		for (int j = i; j >= 1;j--)
		{
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
			else
				break;
		}
	}
}
int main()
{
	int arr[] = { 54, 35, 48, 36, 27, 12, 44, 44, 8, 14, 26, 17, 28 };
	
	//int arr[] = { 4 };

	int lenth = sizeof(arr) / sizeof(int);
	int *ptemp = new int[lenth];
	vector<int>a(&arr[0],&arr[lenth]);

	//bubble_sort(arr, 0, lenth - 1);
	//select_sort(arr, 0, lenth - 1);
	//insert_sort(arr, 0,lenth-1);
	//merge_sort(arr, ptemp, 0, lenth - 1);
	//quick_sort(arr, 0, lenth - 1);
	//quick_sort_par(arr, 0, lenth - 1);

	//heap_sort(arr, 0, lenth - 1);
	//shell_sort(arr, 0, lenth - 1);
	//countingsort(arr, 0, lenth - 1);
	CntSort(a);

	for (int i = 0; i<a.size(); i++)
	{
		cout << a[i] << ",";
	}


	cout << endl << "vector sort:" << endl;

	i_sort(a);
	for (int i = 0; i<a.size(); i++)
	{
		cout << a[i] << ",";
	}

	cout << endl << "end" << endl;
	int kk = 0;
	vector<int>test;
	cout << (kk>int(test.size() - 1)) << endl;
	delete[]ptemp;
	system("pause");
}