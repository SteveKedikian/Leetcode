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
 
 
 
 /**
 	GOOD SOLUTION !
 */
 class Solution {
public:
    bool isPalindrome (ListNode* head) {
        std::vector<int> arr;
        
        ListNode* tmp = head;
        while (tmp) {
            arr.push_back(tmp->val);
            tmp = tmp->next;
        }
        
        int right_index = arr.size() - 1;
        for (int i = 0; i < arr.size()/2; ++i) {
            if (arr[i] != arr[right_index - i]) {
                return false;
            }
        }
        return true;
    }
};
 
 
 /**
 	BAD SOLUTION !
 */
class Solution {
public:
    bool isPalindrome (ListNode* head) {
        if (head->next != nullptr) {
        int size = 2;
        ListNode *left = head->next;
        while (left->next != nullptr) {
            ++size;
            left = left->next;
        }
        left = head;

        ListNode *right = head;
        int mid = 0;
        while (mid != size/2) {
            ++mid;
            right = right->next;
        }
        if (size%2 != 0) {
            right = right->next;
        }

        while (right != nullptr) {
            for(int i = 1; i < mid; ++i){
                left = left->next;
            }

            if (left->val != right->val) {
                return false;
            }
            --mid;
            left = head;
            right = right->next;
        }
    }
    return true;
    }
};
