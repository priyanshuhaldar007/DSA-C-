# include<bits/stdc++.h>
using namespace std;

class Human{

    public:
        int height;
        int weight;
        int age;

    public:
    int getAge(){
        return this->age;
    }

    void setWeight(int w){
        this->weight = w;
    }
};

class Male: public Human{
    public:
    string color;

    void sleep(){
        cout<<"Male sleeping"<<endl;
    }
};

int main(){

    Male object1;
    object1.setWeight(50);
    cout<<object1.age<<endl;
    cout<<object1.weight<<endl;
    cout<<object1.height<<endl;
    cout<<object1.color<<endl;
    object1.sleep();

    
    return 0;
}

/*
protected-> DM can be accessed inside same class or child class
*/

/*

SuperClass                 SubClass                 Data Member type
(access modifier           (Mode of                 upon creating object
property                   inhferitence) 
Data Member)
---------------------------------------------------------------
public                     public                   public
public                     protected                protected
public                     private                  private
---------------------------------------------------------------
protected                  public                   protected
protected                  protected                protected
protected                  private                  private
---------------------------------------------------------------
private                    public                   Not Accessible
private                    protected                Not Accessible
private                    private                  Not Accessible
*/