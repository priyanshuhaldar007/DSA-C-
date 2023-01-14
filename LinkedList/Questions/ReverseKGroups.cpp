// Reverse the SLL in groups of k terms 
# include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    ~Node(){
        int value = this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"Memory is free for node with data "<<value<<endl;
    }
};

void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void InsertAtTail(Node* &tail, int d){
    //create new node
    Node* temp = new Node(d);
    tail->next=temp;
    tail=temp;
}

Node* kReverse(Node* head, int k){
    if(head==NULL){
        return NULL;
    }

    //step 1: reverse first k nodes
    Node* fwd=NULL;
    Node* curr=head;
    Node* prev=NULL;
    int count=0;
    while(curr!=NULL && count<k){
        fwd=curr->next;
        curr->next=prev;
        prev=curr;
        curr=fwd;
        count++;
    }

    //step 2: recursive call
    if(fwd!=NULL){
        head->next = kReverse(fwd,k);
    }

    //step 3: return head of reversed list
    return prev;
}

/*
//using recursion method-I
void reverse(Node* &head, Node* curr, Node* prev){
    //base case
    if(curr==NULL){
        head = prev;
        return;
    }
    Node* fwd = curr->next;
    reverse(head,fwd,curr);
    curr->next=prev;

}

Node* RecursiveReverseSLL(Node* head){
    Node* curr= head;
    Node* prev= NULL;

    reverse(head,curr,prev);
    return head;
}

// using recursion method-II
Node* RRSLL2(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* head2 = RRSLL2(head->next);
    head->next->next = head;
    head->next =NULL;
    return head2;
}
*/
int main(){
    Node* node1 = new Node(3);
    Node* head = node1;
    Node* tail = node1;

    print(head);
    InsertAtTail(tail,7);
    print(head);
    InsertAtTail(tail,8);
    print(head);
    InsertAtTail(tail,11);
    print(head);
    InsertAtTail(tail,17);
    print(head);
    // InsertAtTail(tail,2);
    // print(head);

    head=kReverse(head,2);
    print(head);
    
    return 0;
}