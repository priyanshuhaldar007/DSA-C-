#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data=data;
        this->next=NULL;
    }
    ~node(){
        // if(this->next!=NULL){
        //     delete next;
        //     next=NULL;
        // }
    }
};

void insertHead(node* &head, int data){
    node* newNode = new node(data);
    if(head==NULL){
        head=newNode;
    }
    else{
        newNode->next=head;
        head=newNode;
    }
}

void insertTail(node* &head, int data){
    if(head==NULL){
        insertHead(head,data);
    }
    else{
        node* temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        node* newNode = new node(data);
        temp->next=newNode;
    }
}

void insertAny(node* &head,int data,int pos){
    if(head==NULL){
        insertHead(head,data);
    }
    else{
        pos-=2;
        node* temp = head;
        while(pos!=0){
            temp=temp->next;
            pos--;
        }
        node* newNode = new node(data);
        node* fwd = temp->next;
        temp->next=newNode;
        newNode->next=fwd;
        // cout<<temp->data<<endl;
    }
}

void print(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data;
        if(temp->next!=NULL){
            cout<<"->";
        }
        temp=temp->next;
    }
    cout<<endl;
}

void deleteAny(node* &head, int pos){
    node* temp = head;
    if(pos==1){
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        pos-=2;
        while(pos!=0){
            temp=temp->next;
            pos--;
        }
        node* fwd = temp->next;
        temp->next=fwd->next;
        // cout<<temp->data;
        fwd->next=NULL;
        delete fwd;
    }
}

int main(){
    node* head = NULL;
    insertHead(head,2);
    insertHead(head,1);
    insertTail(head,3);
    insertTail(head,4);
    insertTail(head,5);
    insertAny(head,6,4);
    print(head);
    deleteAny(head,3);
    print(head);
}