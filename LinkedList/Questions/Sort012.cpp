# include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data = data;
        this->next=NULL;
    }
};

node* insertnode(node* &head, int data){
    node* temp = new node(data);
    if(head==NULL){
        head=temp;
    }
    else{
        node* ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
    return head;
}

void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void sortListApproach1(node* &head){
    int zeroCount=0;
    int oneCount=0;
    int twoCount=0;

    node* temp= head;
    while(temp!=NULL){
        if(temp->data==0){
            zeroCount++;
        }
        else if(temp->data==1){
            oneCount++;
        }
        else if(temp->data==2){
            twoCount++;
        }
        temp=temp->next;
        
    }
    cout<<zeroCount<<" "<<oneCount<<" "<<twoCount<<endl;
    temp= head;
    while(temp!=NULL){
        if(zeroCount>0){
            temp->data=0;
            zeroCount--;
        }
        else if(oneCount>0){
            temp->data=1;
            oneCount--;
        }
        else if(twoCount>0){
            temp->data=2;
            twoCount--;
        }
        temp=temp->next;
    }
}

int main(){

    node* head=NULL;
    head = insertnode(head,1);
    head = insertnode(head,0);
    head = insertnode(head,2);
    head = insertnode(head,1);
    head = insertnode(head,2);
    print(head);

    sortListApproach1(head);
    print(head);
    
    return 0;
}