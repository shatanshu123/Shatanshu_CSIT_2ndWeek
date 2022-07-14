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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         ListNode *temp1=l1,*temp2=l2,*prev=NULL;
    int carry=0,sum=0;
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1!=NULL && temp2!=NULL)
        { 
            prev=temp1;
        }
        if(temp1!=NULL && temp2!=NULL)
        {
            sum=temp1->val+temp2->val+carry;
            if(sum>=10)
            {
                carry=sum/10;    
                sum=sum%10;
            }
            else
            {
                carry=0;
            }
            temp1->val=sum;
            if(temp1->next==NULL && temp2->next!=NULL)
            {
                ListNode *NewNode=new ListNode();
                NewNode->val=0;
                temp1->next=NewNode;
                
            }        
            if(temp1->next!=NULL && temp2->next==NULL)
            {
                if(temp1->next->val+carry<10)
                {
                    temp1->next->val=temp1->next->val+carry;
                    return l1;
                }
                else
                {
                    temp1=temp1->next;
                    cout<<"HELLO";
                    while(carry!=0)
                    {
                        int sum2=temp1->val+carry;
                        carry=sum2/10;
                        temp1->val=sum2%10;
                        if(temp1->next==NULL && carry!=0)
                        {
                            ListNode *NewNode=new ListNode();
                            NewNode->val=0;
                            temp1->next=NewNode;
                        }
                        temp1=temp1->next;
                    }
                    return l1;
                }
            }
            temp1=temp1->next;
            temp2=temp2->next;

        }
    }
    cout<<carry;
    if(carry!=0)
    {
        ListNode *NewNode=new ListNode();
        NewNode->val=carry;
        prev->next=NewNode;
    }
    return l1;
    

    }
};