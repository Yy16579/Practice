#include<iostream>
#include<vector>


using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* pre = new ListNode(0);
        ListNode* ans = pre;
        pre->next = head;

        ListNode* n = head;
        while(n != nullptr && n->next != nullptr){
            ListNode* next = n->next->next;
            pre->next = n->next;
            n->next->next = n;
            n->next = next;

            pre = n;
            n = next;
        }

        return ans->next;
    }
};          

int main(){


    return 0;
}