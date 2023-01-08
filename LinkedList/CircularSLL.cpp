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

//insertion
void InsertNode(Node* &tail,int element, int data){
    Node* temp = new Node(data);

    if(tail==NULL){
        tail=temp;
        tail->next=tail;
    }
    else{
        Node* curr = tail;
        while(curr->data!=element){
            curr=curr->next;
        }
        temp->next=curr->next;
        curr->next=temp;
    }
}

//traversal
void print(Node* &tail){
    if(tail==NULL){
        cout<<"List already empty\n";
        return;
    }
    Node* curr = tail;
    do{
        cout<<curr->data<<" ";
        curr=curr->next;
    } while (curr!=tail);
    cout<<endl;
    return;
}

//deletion
void deleteNode(Node* &tail, int data){
    if(tail==NULL){
        cout<<"List already empty\n";
    }
    else{
        Node* temp=tail;
        while(temp->next->data!=data){
            temp=temp->next;
        }
        Node* curr=temp->next;
        temp->next=curr->next;

        //single node LL
        if(curr == temp){
            tail=NULL;
        }

        //more than 1 noe LL
        if(curr==tail){
            tail=temp;
        }
        curr->next=NULL;
        delete curr;
        return;
    }
}

int main(){

    Node* tail = NULL;
    InsertNode(tail,5,3);
    print(tail);
    
    // InsertNode(tail,3,5);
    // print(tail);
    
    // InsertNode(tail,5,7);
    // print(tail);

    // InsertNode(tail,7,9);
    // print(tail);
    
    // InsertNode(tail,5,6);
    // print(tail);
    
    deleteNode(tail,3);
    print(tail);
    
    return 0;
}