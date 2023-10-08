class Solution{
public:
    Node *sortedInsert(struct Node* head, int data) {
        Node *curr = head;
        if(head->data>data){
            Node *new_head = new Node(data);
            new_head->next = head;
            return new_head;
        }

        while(curr->next!=NULL && curr->next->data<data) curr = curr->next;
        Node *temp = curr->next;
        curr->next = new Node(data);
        curr->next->next = temp;
        return head;
    }
};