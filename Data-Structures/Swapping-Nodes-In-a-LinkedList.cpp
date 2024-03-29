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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *ptr = head,newHead;
        vector<int> a;
        while(ptr!=NULL){
            a.push_back(ptr->val);
            ptr=ptr->next;
        }
        for(int i=0;i<a.size();i++){
            if((i+1)==k){
                swap(a[i],a[a.size()-i-1]);
                break;
            }
        }
        ptr=head;
        for(int i=0;i<a.size();i++){
            ptr->val = a[i];
            ptr = ptr->next;
        }
        return head;
    }
};

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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *leftPtr=head,*left_marked,*rightPtr=head;
        //int i=0;
        for(int i=1;i<k;i++){
            leftPtr = leftPtr->next;
        }
        left_marked = leftPtr;
        while(leftPtr->next!=NULL){
            rightPtr= rightPtr->next;
            leftPtr = leftPtr->next;
        }
        swap(left_marked->val,rightPtr->val);
        return head;
    }
};
