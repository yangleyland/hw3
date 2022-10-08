#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
    if (head==NULL)
    {
        return;
    }
    else if (head->val>pivot) {
        Node*nexthead=head->next;
        larger=head;
        larger->next=NULL;
        head=nexthead;
        llpivot(head,smaller, larger->next,pivot);
    }
    else {
        Node*nexthead=head->next;
        smaller=head;
        smaller->next=NULL;
        head=nexthead;
        llpivot(head,smaller->next, larger,pivot);
    }

}

