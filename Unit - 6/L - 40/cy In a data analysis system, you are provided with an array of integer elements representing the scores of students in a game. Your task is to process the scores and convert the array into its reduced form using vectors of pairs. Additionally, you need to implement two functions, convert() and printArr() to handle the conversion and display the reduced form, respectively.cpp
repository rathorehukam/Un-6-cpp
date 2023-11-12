



// You are using GCC
#include <bits/stdc++.h> 
using namespace std; 
void convert(int arr[], int n) {
    vector <pair<int, int> > v; 
    for (int i = 0; i < n; i++) 
        v.push_back(make_pair(arr[i], i)); 
    sort(v.begin(), v.end()); 
    for (int i=0; i<n; i++) 
        arr[v[i].second] = i; 
} 
void printArr(int arr[], int n) { 
    for (int i=0; i<n; i++) 
        cout << arr[i] << " "; 
} 
int main(){ 
    int n; 
    cin>>n;
    if(n<1||n>15) {
        cout<<"-1";
        return 0;
    }
    int arr[n];
    for(int i =0;i<n;i++)
        cin>>arr[i];
    cout<<"Input Array: ";
    printArr(arr, n); 
    convert(arr , n); 
    cout << "\nConverted Array: "; 
    printArr(arr, n); 
    return 0; 
} 
