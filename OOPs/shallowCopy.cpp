# include<bits/stdc++.h>
using namespace std;

class car{
    public:
    int a;
    char *b;

    car(){
        cout<<"simple constructor called"<<endl;
        b = new char;
    }

    void print(){
        cout<<this->a<<" ";
        cout<<this->b<<" ";
        cout<<endl;
    }

    //copy constructor for shallow copy
    car(car &temp){
        this->a=temp.a;
        this->b=temp.b;
    }
};

int main(){
    // creating a c object
    car c;

    //adding values to int a of c object
    c.a=10;

    // adding values to char *b of c object
    char xyz = 'a';
    //since b is a character pointer, so it stores addres of xyz
    c.b = &xyz; 

    // printing the values of it a abd char b of c object
    c.print();

    // creating another object c1 using copy constructor
    car c1(c);

    // c1 is created using copy constructor with shallow copy method, that means they refer same memory location in heap. 

    // printing contents of c1 object
    c1.print();

    // changing the b value of c object
    xyz='b';
    c.b = &xyz; 

    // printing all values of c and c1 object
    c.print();
    c1.print();

    // since they refer same memory locaition therefore change in one reflects in other too.

    // similarly changing b value of c1
    xyz='c';
    c1.b = &xyz;

    // printing all values of c and c1 object
    c.print();
    c1.print();

    // this doesn't happen with variables in stack memory, verifying by changing a of c object
    c.a=20;

    // printing all values of c and c1 object
    c.print();
    c1.print();

    return 0;
}