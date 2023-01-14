# include<bits/stdc++.h>
using namespace std;

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

Node* findMiddle(Node* &head){
    Node* fast=head->next;
    Node* slow=head;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
    }
    return slow;
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    print(head);
    InsertAtTail(tail,12);
    print(head);
    InsertAtTail(tail,15);
    print(head);
    InsertAtTail(tail,25);
    print(head);
    // InsertAtTail(tail,5);
    // print(head);

    Node* ans = findMiddle(head);
    cout<<ans->data<<endl;
    
    return 0;
}