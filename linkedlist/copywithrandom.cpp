//LeetCode Qn 138
//O(n) time
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return NULL;
        Node* curr=head;
        //Insert copies of original nodes just after each node
        while(curr)
        {
            Node* node=new Node(curr->val);
            node->next=curr->next;
            curr->next=node;
            curr=node->next;
        }
        //7->7->13->13->11->11->10->10->1->1
        Node* newHead=head->next;
        curr=head;
        //for each node in original list
        //make its copy node's random pointer
        //to point to node's random pointer's copy
        while(curr)
        {
            if(curr->random)
                curr->next->random=curr->random->next;
            curr=curr->next->next;
        }
        curr=head;
        Node* next=NULL;
        //Now remove the copy links and restablish original links
        while(curr)
        {
            next=curr->next->next;
            if(next)
                curr->next->next=next->next;
            else
                curr->next->next=NULL;
            curr->next=next;
            curr=next;
        }
        return newHead;
    }
};
//LeetCode Qn 138
//O(n) time
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return NULL;
        Node* newHead=NULL;
        Node* curr=head;
        while(curr)
        {
            Node* node=new Node(curr->val);
            node->next=curr->next;
            curr->next=node;
            curr=curr->next->next;
        }
        newHead=head->next;
        curr=head;
        while(curr)
        {
            if(curr->random)
                curr->next->random=curr->random->next;
            curr=curr->next->next;
        }
        curr=head;
        Node* next=NULL;
        while(curr)
        {
            next=curr->next->next;
            if(next)
                curr->next->next=next->next;
            curr->next=next;
            curr=curr->next;
        }
        return newHead;
    }
};