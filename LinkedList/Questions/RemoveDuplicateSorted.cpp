# include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }

    ~Node(){
        int value= this->data;
        if(this->next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"Memory is free for node with data "<<value<<endl;
    }
};

Node* insertNode(Node* &head, int data){
    Node* temp = new Node(data);
    if(head==NULL){
        head=temp;
    }
    else{
        Node* ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
    return head;
}

void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* removeDuplicate(Node* &head){
    if(head==NULL){
        return NULL;
    }
    Node* temp = head;
    while(temp!=NULL){
        if((temp->next!=NULL) && temp->data==temp->next->data){
            Node* curr = temp->next;
            temp->next=curr->next;
            curr->next= NULL;
            delete curr;
        }
        else{
            temp=temp->next;
        }
    }
    return head;
}

int main(){

    Node* head=NULL;
    head = insertNode(head,1);
    print(head);
    
    head = insertNode(head,2);
    print(head);
    
    head = insertNode(head,2);
    print(head);
    
    head = insertNode(head,3);
    print(head);


    head = removeDuplicate(head);
    print(head);
    
    return 0;
}