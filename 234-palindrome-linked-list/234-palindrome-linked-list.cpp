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
//STRIVER_SDE_SHEET
class Solution {
public:
    bool isPalindrome(ListNode* head) 
    {
        stack<int>s;
        ListNode*temp=head;
        while(temp!=NULL)
        {
            s.push(temp->val);
            temp=temp->next;
        }
        while(head!=NULL)
        {
            if(head->val==s.top())
            {
                s.pop();
            }
            head=head->next;
        }
        if(!s.empty())
        {
            return false;
        }
        return true;
    }
};