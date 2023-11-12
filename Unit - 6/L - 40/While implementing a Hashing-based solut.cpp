










#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
int main(){
   int totalRecords;
   cin>>totalRecords;
   double loadFactor=0.75;
   double numberOfBuckets = totalRecords/loadFactor;
   double newRecordCount = numberOfBuckets * 1.1;
   cout<<"The number of buckets required to store "<<totalRecords<<" with load factor of 0.75 is "<<setprecision(2)<<numberOfBuckets<<endl;
   cout<<"The increased capacity if the load factor was increased to 1.1 is "<<setprecision(2)<<newRecordCount<<endl;
   return 0;                           
}
