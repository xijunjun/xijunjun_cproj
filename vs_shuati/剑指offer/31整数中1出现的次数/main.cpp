#include <iostream>
using namespace std;

//f(92)��ֵ��������ʮλ��1�Ļ���0-9��1��1��92��92%10=9��0-9����9*f(9)������ʮλʣ��2��,��λֵ�����1�ĸ���Ϊf(2)��l����ʮλΪ1ʱ����10��1��f(92)=9*f(9)+f(2)+10
//ͬ��f(925)=9*f(99)+f(25)+100,��0-899�У�99����������9�Σ�����ʣ��25���ټ��ϰ�λ���ֵ�1��100�Ρ�
class Solution1 {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		if (n<10)return n != 0;
		int k = n, width = 0;
		while (k != 0){
			width++;
			k /= 10;
		}
		k = n;
		int extra_num = 0;
		if (int(k / pow(10, width - 1))>1)extra_num = pow(10, width - 1);
		else extra_num = (n % (unsigned int)pow(10, width - 1)) + 1;
		return (n / (unsigned int)pow(10, width - 1))*NumberOf1Between1AndN_Solution(pow(10, width - 1) - 1) + extra_num + NumberOf1Between1AndN_Solution(n % (unsigned int)pow(10, width - 1));
	}
};

class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		//��Ҫ˼·���趨�����㣨��1��10��100�ȵȣ���Ϊλ�õ�i����Ӧn�ĸ�λ��ʮλ����λ�ȵȣ����ֱ��ÿ����λ���ж��ٰ���1�ĵ���з���
		//�����趨������λ�ã���n���зָ��Ϊ�����֣���λn/i����λn%i
		//��i��ʾ��λ���Ұ�λ��Ӧ����>=2,��n=31456,i=100����a=314,b=56����ʱ��λΪ1�Ĵ�����a/10+1=32�������λ0~31����ÿһ�ζ�����100�������ĵ㣬������(a%10+1)*100����İ�λΪ1
		//��i��ʾ��λ���Ұ�λ��Ӧ����Ϊ1����n=31156,i=100����a=311,b=56����ʱ��λ��Ӧ�ľ���1������a%10(�����λ0-30)���ǰ���100�������㣬�������λΪ31����a=311��������ֻ��Ӧ�ֲ���00~56����b+1�Σ����е���������У�a%10*100��+(b+1)����Щ���λ��ӦΪ1
		//��i��ʾ��λ���Ұ�λ��Ӧ����Ϊ0,��n=31056,i=100����a=310,b=56����ʱ��λΪ1�Ĵ�����a/10=31�������λ0~30��
		//�ۺ������������������λ��Ӧ0��>=2ʱ����(a+8)/10�ΰ�������100���㣬���е���λΪ1(a%10==1)����Ҫ���Ӿֲ���b+1
		//֮���Բ�8������Ϊ����λΪ0����a/10==(a+8)/10������λ>=2����8�������λλ��Ч����ͬ��(a/10+1)
		int count = 0;
		for (int i = 1; i <= n; i *= 10)
		{
			//i��ʾ��ǰ����������һ����λ
			int a = n / i, b = n%i;
			count +=  (a + 8) / 10 * i +  (a % 10 == 1)*(b + 1);
		}
		return count;
	}
};
int main()
{

	Solution mys;
	Solution1 mys1;

	cout << mys.NumberOf1Between1AndN_Solution(908) << endl;
	cout << mys1.NumberOf1Between1AndN_Solution(908) << endl;
	cout << "end" << endl;
	system("pause");
}