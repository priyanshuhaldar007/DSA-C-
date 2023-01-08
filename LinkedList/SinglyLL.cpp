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

//Insertion in a LinkedList
void InsertAtHead(Node* &head, int d){
    //create new node
    Node* temp = new Node(d);
    temp->next=head;
    head=temp;
}

void InsertAtTail(Node* &tail, int d){
    //create new node
    Node* temp = new Node(d);
    tail->next=temp;
    tail=temp;
}

void InsertAtPosition(Node* &tail,Node* &head,int pos, int d){
    if(pos==1){
        InsertAtHead(head,d);
        return;
    }
    Node* temp = head;
    --pos;
    while(--pos){
        temp=temp->next;
    }
    if(temp->next==NULL){
        InsertAtTail(tail,d);
        return ;
    }
    //creating new node
    Node* newNode = new Node(d);
    newNode->next= temp->next;
    temp->next=newNode;
}

//traversing a LinkdList
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

//deleting at position in a Linked List
void deleteNode(int pos, Node* &head, Node* &tail){
    Node* temp = head;
    //deleting first node
    if(pos==1){
        head = head->next;
        
        temp->next=NULL;
        delete temp;
    }
    //deleting middle node
    else{
        pos--;
        while (--pos){
            temp=temp->next;
        }
        
        Node* temp2 = temp->next;
        // cout<<temp2->data<<" ";
        if(temp2->next==NULL){
            tail=temp;
        }

        temp->next=temp2->next;
        temp2->next=NULL;
        delete temp2;
    }
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
    InsertAtPosition(tail,head,2,25);
    print(head);
    InsertAtPosition(tail,head,1,5);
    print(head);
    InsertAtPosition(tail,head,6,35);
    print(head);

    deleteNode(6, head,tail); 
    print(head);
    cout<<"Head data: "<<head->data<<endl; 
    cout<<"Tail data: "<<tail->data<<endl;
    
    return 0;
}