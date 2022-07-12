#include <string>
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
    int getDecimalValue(ListNode* head) {
        std::string binar = "";
        while (head) {
            binar += std::to_string(head->val);
            head = head->next;
        }

        int sum = 0;
        for (int i = 0; i < binar.length(); ++i) {
            if (binar[i] == '1') {
                int temp = 1;
                int p = binar.size() - i - 1;
                while(p){
                    temp *= 2;
                    --p;
                }
                sum += temp;
            }
        }
        return sum;
    }
};
