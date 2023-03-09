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

bool checkValinMap(map<int, bool> &checkMap, int data){
    if(checkMap[data]==false){
        checkMap[data]=true;
        return false;
    }
    return true;
}

Node* removeDuplicate(Node* &head,map<int, bool> &checkMap){
    if(head==NULL){
        return NULL;
    }
    Node* temp = head;
    Node* prev=NULL;
    while(temp!=NULL){
        if(!checkValinMap(checkMap,temp->data)){
            prev = temp;
            temp=temp->next;
        }
        else{
            prev->next=temp->next;
            temp->next=NULL;
            delete temp;
            temp=prev->next;
        }
    }
    return head;
}

int main(){

    Node* head=NULL;
    head = insertNode(head,4);
    print(head);
    
    head = insertNode(head,2);
    print(head);
    
    head = insertNode(head,3);
    print(head);
    
    head = insertNode(head,4);
    print(head);

    head = insertNode(head,2);
    print(head);

    head = insertNode(head,1);
    print(head);

    head = insertNode(head,2);
    print(head);

    map<int , bool> checkMap;

    head = removeDuplicate(head, checkMap);
    print(head);
    
    return 0;
}