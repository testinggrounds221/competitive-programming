// https://leetcode.com/problems/add-two-numbers/
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


void append(ListNode* head, int key) {
	ListNode* ptr = head;
	ListNode* newNode = new ListNode;
	newNode->val = key;
	newNode->next = NULL;
	if (head == NULL) { head = newNode;return; }
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = newNode;
	return ;
}


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { //CHANGE RETURN TO LISTNODE*
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;		
		ListNode* temp = new ListNode();
		int carry = 0;

		int curr_sum = ptr1->val+ptr2->val;
			if(curr_sum >=10){
			temp->val = (curr_sum - 10);		
				cout << (curr_sum - 10) << endl;				
				carry = 1;
			}
			else{
			temp->val = (curr_sum);
				cout << (curr_sum)<<endl;
				carry = 0;
			}
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		
		while(ptr1 && ptr2){
			int curr_sum = ptr1->val+ptr2->val + carry;
			if(curr_sum >=10){
				cout << (curr_sum - 10) << endl;				
				append(temp,curr_sum - 10);
				carry = 1;
			}
			else{
				cout << (curr_sum)<<endl;
				append(temp,curr_sum);
				carry = 0;
			}
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}


		while(ptr1){
			int curr_sum = ptr1->val+carry;
			if(curr_sum >=10){				
				cout << (curr_sum - 10) << endl;				
				append(temp,curr_sum-10);
				carry = 1;
			}
			else{
				cout << (curr_sum)<<endl;
				append(temp,curr_sum);
				carry = 0;
			}
			ptr1 = ptr1->next;
		}
		while(ptr2){
			int curr_sum = ptr2->val+carry;
			if(curr_sum >=10){				
				cout << (curr_sum - 10) << endl;				
				append(temp,curr_sum-10);
				carry = 1;
			}
			else{
				cout << (curr_sum)<<endl;
				append(temp,curr_sum);
				carry = 0;
			}
			ptr2 = ptr2->next;
		}
		cout << carry;
		if(carry)
				append(temp,carry);

			return temp;
    }

};

void traverse(ListNode* head) {
	ListNode* ptr = head;
	while (ptr) {
		cout << ptr->val << endl;
		ptr = ptr->next;
	}
}

ListNode* arrToList(int A[], int n) {
	if (n == 0) return NULL;
	ListNode* head = new ListNode;
	head->val = A[0];
	head->next = NULL;

	ListNode* ptr = head;

	for (int i = 1;i < n;i++) {
		ListNode* temp = new ListNode;
		temp->val = A[i];
		temp->next = NULL;

		ptr->next = temp;
		ptr = temp;
	}
	return head;
}


int main(int argc, char const *argv[])
{
	int a1[] = {2,4,3};
	int a2[] = {5,6,4};

	ListNode* p1 = arrToList(a1,sizeof(a1)/sizeof(a1[0]));
	ListNode* p2 = arrToList(a2,sizeof(a2)/sizeof(a2[0]));

	Solution s;
	cout << endl;
	traverse(s.addTwoNumbers(p1,p2));

	// ListNode* temp = new ListNode();
	// append(temp,1);
	// append(temp,1);
	// append(temp,1);
	// append(temp,1);

	// traverse(temp);



	return 0;
}
