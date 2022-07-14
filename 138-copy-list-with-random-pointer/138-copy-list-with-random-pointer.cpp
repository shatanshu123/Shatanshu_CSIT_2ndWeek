/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
//STRIVER_SDE_SHEET

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        if(!head)
        {
            return head;
        }
        unordered_map<Node*,Node*>mp;
        Node*temp=head;
        
        Node*root=new Node(temp->val);
        Node*tail=root;
        //Storing address of old nodes and new nodes in map
        mp[temp]=root;
        temp=temp->next;
        while(temp!=NULL)
        {
            Node*node=new Node(temp->val);
            tail->next=node;
            tail=node;
            //Storing address of old nodes and new nodes in map
            mp[temp]=node;
            temp=temp->next;
        }
        //Creation of linked list finished
        Node*temp2=head;
     
        while(temp2!=NULL)
        {
            mp[temp2]->random=mp[temp2->random];
            temp2=temp2->next;
        }
        return root;
    }
};