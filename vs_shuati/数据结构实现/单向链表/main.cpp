////�ο���ָoffer��3��
#include <iostream>
#include <vector>
#include<stack>
using namespace std;


template<class Elem> struct ListNode {
	Elem val;
	struct ListNode *next;
	ListNode(Elem x) :val(x), next(NULL) {
	}
};
template<class Elem> class LList{
  public:
	  ListNode< Elem> *head = NULL;
	  ListNode<Elem> *tail = NULL;
	void append(Elem val){
		if (head == NULL){
			head = new ListNode<Elem>(val);
			tail = head;
		}
		else{
			tail->next = new ListNode<Elem>(val);
			tail = tail->next;
		}
	}
	//ɾ�����һ���ڵ�
	Elem  remove(){
		Elem rtval;
		if (tail == NULL)return 0;
		else if (head->next == NULL){
			rtval = head->val;
			head = NULL;
			tail = NULL;
		}
		else{//ֵ��ע��������޸ĵ����ڶ����ڵ��nextֵʱ������ͨ�������������ڵ��next��ָ��ָ�����ڶ��ڵ��next���޸ġ�
			rtval = tail->val;
			ListNode<Elem> *tphead = head;
			while (tphead->next->next != NULL)tphead=tphead->next;
			delete tphead->next;
			tphead->next = NULL;
			tail = tphead;
		}
		return rtval;
	}
	////ɾ��ֵΪval�Ľڵ�(������û���ظ���ֵ)
	//void remove_val(Elem val){
	//	if (tail == NULL)return ;
	//	else if (head->val ==val){
	//		head = NULL;
	//		tail = NULL;
	//	}
	//}
};


int main()
{
	LList<int>mlist;
	for (int i = 0; i < 10; i++){
		mlist.append(i);
	}
	int re_val=mlist.remove();
	cout << "remove:" << re_val << endl;
	mlist.append(99);
	ListNode<int>*phead = mlist.head;
	while (phead != NULL){
		cout << phead->val << " ";
		phead = phead->next;
	}
	cout << "end" << endl;
	system("pause");
}