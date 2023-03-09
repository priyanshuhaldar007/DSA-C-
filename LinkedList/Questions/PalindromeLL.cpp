#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

node *insertnode(node *&head, int data)
{
    node *temp = new node(data);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    return head;
}

void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Approach 1:- TC: O(n)  |   SC: O(n)
bool checkPalindrome(vector<int> arr){
    int e = arr.size()-1;
    int s = 0;
    while(s<=e){
        if(arr[s]!=arr[e]){
            return false;
        }
        s++;
        e--;
    }
    return true;
}

bool isPalindrome(node* head){
    vector<int> arr;
    node* temp = head;
    while(temp!=NULL){
        arr.push_back(temp->data);
        temp=temp->next; 
    }

    return checkPalindrome(arr);
}

// Approach II:
// Find middle node
// Reverse the LL after that
// compare the two halves
node* findMiddle(node* &head){
    node *slow = head;
    node *fast = head->next;
    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
        }
    }
    return slow;
}
node* reverse(node* head){
    node* prev = NULL;
    node* fwd = NULL;
    node* curr = head;
    while(curr!=NULL){
        fwd=curr->next;
        curr->next=prev;
        prev=curr;
        curr=fwd;
    }
    return prev;
}

bool checkPalindrome2(node* head){
    node* head2 = findMiddle(head);
    head2 = reverse(head2);
    node* temp2 =head2;
    node* temp =head;
    while(temp2!=NULL){
        if(temp->data!=temp2->data){
            return false;
        }
        temp=temp->next;
        temp2=temp2->next;
    }
    return true;
}

int main()
{
    node *head = NULL;
    insertnode(head, 1);
    insertnode(head, 2);
    insertnode(head, 3);
    insertnode(head, 1);
    print(head);
    cout<<checkPalindrome2(head);
    // cout<<temp->data;
    // cout<<temp->next->data;
    // print(temp);

    return 0;
}