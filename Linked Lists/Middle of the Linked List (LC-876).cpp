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

// Method 2:

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp=head;
        int count=0;
// Count the total number of nodes present in the list
        while(temp){
            count++;
            temp=temp->next;
        }
        int mid=count/2+1;
        int nodecount=1;
// Find the middle node (nodecount equals to the middle of count)
        while(head){
            if(nodecount==mid)
                return head;
            nodecount++;
            head=head->next;
        }
        return NULL;
    }
};
