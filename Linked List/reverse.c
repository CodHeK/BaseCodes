Node* Reverse(Node *head)
{
  // Complete this method
    struct Node *tmp, *prev, *fwd;
    prev = NULL;
    tmp = head;
    while(tmp != NULL) {   
            fwd = tmp->next;
        tmp->next = prev;
        prev = tmp;
        tmp = fwd;
    }
    head = prev;
    return head;
}