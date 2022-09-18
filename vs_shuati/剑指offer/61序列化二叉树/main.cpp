#include <iostream>
#include<string>
#include<stack>
using namespace std;


struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};

class Solution {
public:
	char* Serialize(TreeNode *root) {
		stack<TreeNode*>sta;
		TreeNode *cur = root;
		string rts = "";
		while (1)
		{
			while (1)
			{
				if (cur){
					sta.push(cur);
					rts += to_string(cur->val) + ",";
					cur = cur->left;
				}
				else {
					rts += "#,";
					break;
				}
			}
			if (sta.empty())
			{
				char *ret = new char[rts.size() + 1];
				strcpy(ret, rts.c_str());
				//rts.copy(ret,rts.size(),0);ret[rts.size()] = '\0';//�ڶ���д��
				return ret;
			}
			cur = sta.top();
			sta.pop();
			cur = cur->right;
		}
	}

	TreeNode* RecurDe(string str, int &st)
	{
		TreeNode *root = NULL;
		int ind = str.find_first_of(',', st);
		if (str[st] == '#') //�����õ�����һ��������#�ţ���Ϊ���Ҷ�ڵ�������ӽڵ㶼Ϊ�գ����Բ���Ҫ����str�Ľ���������Ϊ����֮ǰ�Ѿ�ֹͣ�ݹ��� 
			st = ind + 1;
		else {
			root = new TreeNode(stoi(str.substr(st, ind - st)));
			st = ind + 1;
			root->left = RecurDe(str, st);
			root->right = RecurDe(str, st);
		}
		return root;
	}
	TreeNode* Deserialize(char *str)
	{
		int st = 0;
		if (str == NULL)return NULL;
		return RecurDe(string(str), st);
	}
};
int main()
{
	char *ptr = "123,4";
	string str=string(ptr);
	cout << str.find_first_of(',',0);
	//cout << 1+stoi(str.substr(0,2))<<endl;

	cout << "end" << endl;
	system("pause");
}