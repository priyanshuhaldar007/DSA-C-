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
    }

    //copy constructor for deep copy
    car(car &temp){
        this->a=temp.a;
        char m ;
        m=*(temp.b);
        this->b=&m;
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
    cout<<endl;

    // creating another object c1 using copy constructor
    car c1(c);

    // c1 is created using copy constructor with deep copy method, that means they refer different memory location in heap. 

    // printing contents of c1 object
    c1.print();
    cout<<endl;

    // changing the b value of c object
    xyz='b';
    c.b = &xyz; 

    // printing all values of c and c1 object
    c.print();
    c1.print();
    cout<<endl;

    // since they refer different memory locaition therefore change in one doesn't reflects in other.

    // similarly changing b value of c1
    char xy='c';
    c1.b = &xy;

    // printing all values of c and c1 object
    c.print();
    c1.print();
    cout<<endl;

    return 0;
}