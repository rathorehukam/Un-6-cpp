






// You are using GCC
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
using namespace std;
long hashcode(string s){
   long seed = 31; 
   long hash = 0;
   for(int i = 0; i < s.length(); i++){
       hash = (hash * seed) + s[i];
   }
   return hash % 10007;
};

int main(){
   int count = 0;
   int collisions = 0;
    string x;
    int array[30000];
     //File stream
     cin>>x;
     while(x!="."){
        array[count] = hashcode(x);
        for(int i = 0; i<count; i++){
            if(array[i]==array[count]){
                collisions++;
                break;
            }
       }
        count++;
        cin>>x;
    }
    cout<<"Total Input: " <<count<<endl;
    cout<<"Collision: "<<collisions;
}

