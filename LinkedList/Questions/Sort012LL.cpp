# include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void insertNode(node* &head, int data){
    node* newNode = new node(data);
    if(head==NULL){
        head=newNode;
    }
    else{
        node* temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
}

void print(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}

//sort by making 3 small LL, finally merging them
node* sort012Process1(node* head){
    node* head0 = NULL;
    node* head1 = NULL;
    node* head2 = NULL;
    node* temp  = head;

    while(temp!=NULL){
        node* newNode = temp;
        if(newNode->data==0){
            insertNode(head0,newNode->data);
        }
        else if(newNode->data==1){
            insertNode(head1,newNode->data);
        }
        else if(newNode->data==2){
            insertNode(head2,newNode->data);
        } 
        temp=temp->next;
    }
    
    // merging all the small LinkedLists
    temp  = head0;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head1;
    // cout<<"hii";
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head2;
    
    return head0;
}

int main(){
    node* head=NULL;
    insertNode(head,1);
    print(head);
    
    insertNode(head,0);
    print(head);
    
    insertNode(head,2);
    print(head);
    
    insertNode(head,1);
    print(head);

    insertNode(head,2);
    print(head);

    cout<<"\nSorted LinkedList using Process1:\n";
    head = sort012Process1(head);
    print(head);
    
    return 0;
}