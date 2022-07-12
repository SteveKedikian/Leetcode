/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k <= 0) {
            return head;
        }

        ListNode *tmp = head;
        int size = 0;
        while (tmp) {
            tmp = tmp->next;
            ++size;    
        }
        tmp = head;

        int rotate = k % size;
        for (int i = 0; i < size - rotate - 1; ++i) {
             head = head->next;
        }

        ListNode *last = head;
        while (last->next != nullptr) {
            last = last->next;
        }

        last->next = tmp;
        tmp = head->next;
        head->next = nullptr;
        head = tmp;
        
        return head;
    }
};

