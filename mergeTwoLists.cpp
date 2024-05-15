#include<iostream>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x,ListNode  *next) : val(x), next(next) {}
};
class Solution {
  public: 
    //recurrsive method
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == NULL) return l2;

    if (l2 == NULL) return l1;

    if (l1->val <= l2->val) {
      l1->next = mergeTwoLists(l1->next, l2);
      return l1;
    } else {
      l2->next = mergeTwoLists(l1,l2->next);
      return l2;
    }
  }
};

void printlist(ListNode *head) {
  while (head != nullptr) {
    cout<<head->val<<" ";
    head = head->next;
  }
  cout<<endl;
}

ListNode* createlist(const int arr[] , int size) {
  if (size == 0 ) return nullptr;
  ListNode *head = new ListNode(arr[0]);
  ListNode *current = head;
  for (int i = 1; i < size; i++) {
    current->next = new ListNode(arr[i]);
    current = current->next;
  }
  return head;
}


int main() {
Solution sol;
int arr1[] = {1,2,3};
int arr2[] = {1,1,4};

ListNode *l1 = createlist(arr1, 3);
ListNode *l2 = createlist(arr2, 3);

ListNode* mergedList = sol.mergeTwoLists(l1,l2);
cout<<"Recurrsive Method"<<endl;
printlist(mergedList);

ListNode *current = mergedList;
while (current != nullptr){
  ListNode *next = current->next;
  delete current;
  current = next;
}
return 0;
}
