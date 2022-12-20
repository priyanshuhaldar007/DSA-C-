/*
Binary & truth table
--------------------
A   B   O
----------
0   0   0
0   1   0
1   0   0
1   1   1

Binary | truth table
--------------------
A   B   O
----------
0   0   0
0   1   1
1   0   1
1   1   1

*/

#include<iostream>
using namespace std;

/*
getBit:
----------------
(n & (1<<pos)) =>
----------------
Eg: 
n = 5 = 0 1 0 1
index-> 3 2 1 0

+++++++++++++++++++++++
pos = 0        
               
1<<0 => 0 0 0 0
index-> 3 2 1 0
               
binary & =>    
0 1 0 1        
0 0 0 1        
-------        
0 0 0 1 

ans-> 1

+++++++++++++++++++++++
pos = 1        
               
1<<1 => 0 0 1 0
index-> 3 2 1 0
               
binary & =>    
0 1 0 1        
0 0 1 0        
-------        
0 0 0 0 

ans-> 0

+++++++++++++++++++++++
pos = 2        
               
1<<2 => 0 1 0 0
index-> 3 2 1 0
               
binary & =>    
0 1 0 1        
0 1 0 0        
-------        
0 1 0 0 

ans-> 4

+++++++++++++++++++++++
pos = 3        
               
1<<1 => 1 0 0 0
index-> 3 2 1 0
               
binary & =>    
0 1 0 1        
1 0 0 0      
-------        
0 0 0 0 

ans-> 0
++++++++++++++++++++++++

According to above cases,
(n & (1<<pos)) => 1   0   4   0
if((n & (1<<pos))==0) --> yes, that position had 0                      ----->   return 1
                      ↳-> no, that position did not had 0, and had 1    ----->   return 0

so for knowing the bit value.... we flip the if condition and return.

*/
int getBit(int n, int pos){
    int mask = 1<<pos;
    //if n & mask == 0 then desired bit is 0 else 1 => so we develop below equaation
    return ((n & mask)!=0);
}

// setBit -> set the desired bit to 1
int setBit(int n, int pos){
    int mask = 1<<pos;
    return (n | mask);
}

// resetBit -> set the desired bit to 0
int resetBit(int n, int pos){
    int mask = 1<<pos;
    mask= ~mask;
    return (n & mask);
}
int updateBit(int n, int pos, int val){
    int mask = ~(1<<pos);
    n = n & mask;
    return (n | (val<<pos));
}

int main(){
    // cout<<((5 & (1<<3))!=0)<<endl;
    cout<<getBit(5,2)<<endl;
    cout<<setBit(5,2)<<endl;
    cout<<resetBit(5,2)<<endl;
    // cout<<clearBit(5,2)<<endl;
    // cout<<updateBit(5,1,1)<<endl;

    return 0;
}


/*

n = 5 = 0 1 0 1     
    4 = 0 1 0 0
XOR---------------
        0 0 0 1    =  1

index of rightmost set bit-> xor val-1

n = 14 = 1 1 1 0
    13 = 1 1 0 1
XOR---------------
         0 0 1 1    =  3

n = 364 = 1 0 1 1 0 1 1 0 0
    363 = 1 0 1 1 0 1 0 1 1
XOR--------------------------
          0 0 0 0 0 0 1 1 1     =  7



0 1 0 1
1 0 1 0
--------
1 1 1 1

*/