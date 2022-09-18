#include <iostream>
#include<vector>
using namespace std;

//01����-�ݹ�
int max_val_rec(int* pC, int* pW, int item_num, int index, int Vpack)
{
	if (index == item_num - 1)//�ݹ���ڣ�������������Ʒ
	{
		if (Vpack<pC[index])
			return 0;
		else return pW[index];
	}
	else
	{
		int zero_sum = 0, one_sum = 0;
		zero_sum = max_val_rec(pC, pW, item_num, index + 1, Vpack);
		if (Vpack >= pC[index])//������Ʒ�޷�װ�£�����������Ʒ
			one_sum = max_val_rec(pC, pW, item_num, index + 1, Vpack - pC[index]) + pW[index];   
		return zero_sum > one_sum ? zero_sum : one_sum;
	}
}
//01����-��̬�滮
int max_val(int* pC, int* pW, int item_num, int Vpack)
{
	int *table = new int[(++Vpack)*item_num];//ע����++Vpack!!!!
	for (int j = 0; j < Vpack; j++)
	{
		table[j] = pC[0] <= j ? pW[0] : 0;
	}
	for (int i = 1; i < item_num; i++)
	{
		for (int j = 0; j < Vpack; j++)
		{
			int zero_sum = table[(i - 1)*Vpack + j], one_sum = 0;
			if (j >= pC[i]) one_sum = table[(i - 1)*Vpack + j - pC[i]] + pW[i];
			table[i*Vpack + j] = zero_sum>one_sum ? zero_sum : one_sum;
		}
	}
	int res = table[Vpack*item_num - 1];
	delete[]table;
	return res;
}

int main()
{
	int arryC[] = {2,3,4,5,9};//���
	int arryW[] = { 3, 4, 5, 8, 10 };//��ֵ


	//cout << max_val_rec(arryC, arryW, 5, 0, 20) << endl;
	cout << max_val(arryC, arryW, 5, 20) << endl;

	cout << "end" << endl;
	system("pause");
}