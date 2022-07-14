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
    ListNode* rotateRight(ListNode* head, int k) {
        // Base case
        if (k == 0 || head == nullptr || head->next == nullptr) return head;
        
        vector<ListNode*> nodes = getNodes(head);
        // Get k in base of the size
        int rot = k % nodes.size();
        // If k is same as size means it is not necessary rotate it!
        if (rot == 0) return head;
        // Where to start 
        int target = nodes.size()-rot;
        // Get the rotated linked list
        rotateNodes(nodes, target);

        return nodes[target];
    }
    
private:
    vector<ListNode*> getNodes(ListNode* head) {
        vector<ListNode*> nodes;
        while (head != nullptr) {
            nodes.push_back(new ListNode(head->val));
            head = head->next;
        }
        return nodes;
    }
    
    void rotateNodes(vector<ListNode*> nodes, int target) {
        for (int i = target; i < nodes.size()-1; ++i) {
            nodes[i]->next = nodes[i+1];
        }
        
        for (int i = 0; i < target; ++i) {
            if (i == 0) nodes[nodes.size()-1]->next = nodes[i];
            else nodes[i-1]->next = nodes[i];
        }
    }
};