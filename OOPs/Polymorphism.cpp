# include<bits/stdc++.h>
using namespace std;

//compile time polymorphism/ static polymorphism 

class A{
    public:
    //method overloading-> using same name for two methods/ functions but with different parameters
        void sayHello(){
            cout<<"Hello Priyanshu"<<endl;
        }
        void sayHello(char a){
            cout<<"Hello Priyanshu"<<endl;
        }

};

class B{
    public:
        int a;
        int b;

    public: 
        int add(){
            return a+b;
        }
    //operator overloading-> making operators do something else than their default task
    // syntax-> returnType operator<operator> (<i/p arg>)
        void operator+ (B &obj){
            // int value1 = this->a;
            // int value2 = obj.a;

            // cout<<"output: "<<value2-value1<<endl;

            cout<<"Hello world!"<<endl;
        }

        void operator() (){
            cout<<"Bracket overloaded, calling object a value: "<<this->a<<endl;
        }
};


//run time polymorphism / dynamic polymorphism
class Animal{
    public:
        void speak(){
            cout<<"speaking"<<endl;
        }
};

class Dog:public Animal{
    public:
    void speak(){
        cout<<"Barking"<<endl;
    }
};


int main(){
    Dog obj;
    obj.speak();

/*
    B obj1, obj2;
    obj1.a = 4;
    obj2.a = 7;

    obj1 + obj2;

    obj1();
*/
    // A obj;
    // obj.sayHello();
    
    return 0;
}