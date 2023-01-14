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

//using loop
bool isCircular(Node* head){
    Node* temp=head;
    while(true){
        if(temp==NULL){
            return false;
        }
        temp=temp->next;
        if(temp==head){
            return true;
        }
    }
}

//using map
bool detectLoop(Node* head){
    if(head==NULL){
        return false;
    }

    map<Node*, bool> visited;

    Node* temp=head;
    while(temp!=NULL){
        if(visited[temp]==true){
            //cycle is present
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return false;
}

Node* floydDetectLoop(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node* slow=head;
    Node* fast=head;

    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;

        if(slow==fast){
            return slow;
        }
    }
    return NULL;    
}

Node* getStartingNode(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node* intersection = floydDetectLoop(head);
    Node* slow = head;

    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }

    return slow;
}

void removeLoop(Node*head){
    if(head==NULL){
        return;
    }
    Node* startOfLoop = getStartingNode(head);
    Node* temp = startOfLoop;
    while(temp->next!=startOfLoop){
        temp=temp->next;
    }
    temp->next=NULL;
}

int main(){

    Node* tail = NULL;
    InsertNode(tail,5,3);
    print(tail);
    
    InsertNode(tail,3,5);
    print(tail);
    
    InsertNode(tail,5,7);
    print(tail);

    InsertNode(tail,7,9);
    print(tail);
    
    InsertNode(tail,5,6);
    print(tail);
    Node* head =tail->next;

    cout<<head->data<<endl;
    cout<<tail->data<<endl;
    
    tail->next=head->next;
    cout<<tail->next->data<<endl;
    // cout<<isCircular(head)<<endl;
    // cout<<detectLoop(head);
    // Node* temp = floydDetectLoop(head);
    // if(temp==NULL){
    //     cout<<"No cycle found"<<endl;
    // }
    // else{
    //     cout<<"Node in the loop is: "<<temp->data<<endl;
    // }

    Node* loop = getStartingNode(head);

    cout<<"loop start at"<<loop->data<<endl;

    removeLoop(head);

    print(head);

    return 0;
}