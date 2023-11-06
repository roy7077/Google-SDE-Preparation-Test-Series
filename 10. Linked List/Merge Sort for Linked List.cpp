
class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node *merge(Node *l1, Node *l2){
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->data > l2->data){
            l2->next = merge(l1, l2->next);
            return l2;
        }
        else{
            l1->next = merge(l1->next, l2);
            return l1;
        }
    }
    Node* mergeSort(Node* head) {
        if(!head || !head->next) return head;
        Node *slow = head, *fast = head, *tmp = NULL;
        while(fast && fast->next){
            tmp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        tmp->next = NULL;
        Node *l1 = mergeSort(head);
        Node *l2 = mergeSort(slow);
        return merge(l1, l2);
    }
};
