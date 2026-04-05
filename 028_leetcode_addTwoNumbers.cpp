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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(0);
        ListNode* cur = ans;
        int flag = 0;

        while(l1 != nullptr || l2 != nullptr){
            int x = (l1 == nullptr ? 0 : l1->val);
            int y = (l2 == nullptr ? 0 : l2->val);
            int sum = x + y + flag;
            flag = sum / 10;
            ListNode* n = new ListNode(sum % 10);
            cur->next = n;
            cur = n;
            
            if(l1 != nullptr){
                l1 = l1->next;
            }
            if(l2 != nullptr){
                l2 = l2->next;
            }
        }

        if(flag != 0){
            ListNode* n = new ListNode(flag);
            cur->next = n;
        }

        return ans->next;
    }
};

int main(){


    return 0;
}