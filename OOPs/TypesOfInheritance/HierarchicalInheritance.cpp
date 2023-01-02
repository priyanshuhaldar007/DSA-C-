# include<bits/stdc++.h>
using namespace std;

class A{
    public:
    void func1(){
        cout<<"inside function1\n";
    }
};

class B: public A{
    public:
    void func2(){
        cout<<"inside function2\n";
    }
};
class C: public A{
    public:
    void func3(){
        cout<<"inside function3\n";
    }
};

int main(){

    A obj1;
    obj1.func1();
    
    B obj2;
    obj2.func1();
    obj2.func2();
    
    C obj3;
    obj3.func1();
    obj3.func3();
    
    return 0;
}