# include<bits/stdc++.h>
using namespace std;

class Hero{

    //properties
    private:
    int health = 70;

    public:
    char *name;
    char level ='B';
    static int TimeToComplete;

    void print(){
        cout<<"[ Name: "<<this->name<<" ,";
        cout<<"Health: "<<this->health<<" ,";
        cout<<"Level: "<<this->level<<" ]\n";
    }

    //constructor
    Hero(){
        cout<<"constructor called"<<endl;
        name = new char[100];
    }

    //parameterised costructor
    Hero(int health, char level){
        this->health=health;
        this->level=level;
    }

    //copy constructor {makes shallow copy}
    // Hero(Hero& temp){
    //     cout<<"copy constructor called"<<endl;
    //     this->name=temp.name;
    //     this->health=temp.health;
    //     this->level=temp.level;
    // }

    //copy constructor {makes deep caopy}
    Hero(Hero& temp){
        char *ch = new char(strlen(temp.name));
        strcpy(ch, temp.name);
        this->name = ch;

        cout<<"copy constructor called"<<endl;
        this->health=temp.health;
        this->level=temp.level;
    }

    // getter & setter concept
    int getHealth(){
        return health;
    }
    
    char getLevel(){
        return level;
    }

    void setHealth(int h){
        health = h;
    }

    void setLevel(char ch){
        level = ch;
    }

    void setName(char name[]){
        strcpy(this->name, name);
    }

    //static function -> can only access static members, doesn't has this keyword, belongs to class
    static int  random(){
        cout<<TimeToComplete<<endl;
        return 0;
    }

    //destructor
    ~Hero(){
        cout<<"destructor called"<<endl;
    }
};

int Hero::TimeToComplete = 5;
//datatype className ::{scope resolution operator} fieldName = value;

int main(){

    //static keyword:- needn't make any object to access static data members of the class {initialised outside the class}
    cout<<Hero::TimeToComplete;  //static dataMember
    /*
    //destructor:- similar to constructor-> deallocates memeory for object when about to go out of scope
    Hero a; // automatically called for static allocation
    Hero *b = new Hero(); // have to explicitly call for dynamic allocation
    delete b;
    */
    /*
    // Shallow Copy-> done by default copy constructor: shares the same memory space, variables share same memory space and change in one is reflected in the other.

    // Deep Copy-> done by constructor: has a seperate memory address, variables have seperate memory and chaneg in one doesn't affect the other


    Hero hero1;

    hero1.setHealth(12);
    hero1.setLevel('D');
    char name[6] = "Dolly";
    hero1.setName(name);

    hero1.print();

    Hero hero2(hero1);
    hero2.print();

    hero1.name[0] = 'P';

    cout<<"\nafter changing in hero1\n";

    hero1.print();
    hero2.print();

    cout<<endl<<"copy assignmnet operator {hero1=hero2}\n";
    hero1=hero2;

    hero1.print();
    hero2.print();
    */

    /*
    Hero S(60,'c');
    S.print();

    //copy constructor
    Hero B(S);
    B.print();
    */

    /*
    // static allocaion
    Hero h1;

    h1.setHealth(50);
    h1.level = 'A';

    cout<<sizeof(h1)<<endl;
    cout<<h1.getHealth()<<endl;
    cout<<h1.level<<endl;


    //dynamic allocation
    Hero *h2 = new Hero; 
    cout<<(*h2).getHealth()<<endl;
    cout<<(*h2).level<<endl;

    cout<<h2->getHealth()<<endl;
    cout<<h2->level<<endl;
    */


    return 0;    
}

// padding & greedy alignment