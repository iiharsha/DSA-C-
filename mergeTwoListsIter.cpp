#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *prev = new ListNode(-1); // Dummy node
        ListNode *curr = prev;
        
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        // Attach the remaining nodes
        curr->next = (l1 == nullptr) ? l2 : l1;
        
        ListNode *mergedHead = prev->next;
        delete prev; // Free the dummy node
        return mergedHead;
    }
};

// Print function
void printList(ListNode *head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to create lists using array
ListNode* createList(const int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode *head = new ListNode(arr[0]);
    ListNode *current = head;
    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Function to delete lists and free memory
void cleanupList(ListNode *head) {
    ListNode *current = head;
    while (current != nullptr) {
        ListNode *next = current->next;
        delete current;
        current = next;
    }
}

int main() {
    Solution sol;

    int arr1[] = {1, 2, 3};
    int arr2[] = {1, 1, 4};

    ListNode *l1 = createList(arr1, 3);
    ListNode *l2 = createList(arr2, 3);

    ListNode* mergedList = sol.mergeTwoLists(l1, l2);
    cout << "Iterative Method" << endl;
    printList(mergedList);
    cleanupList(mergedList);

    return 0;
}
