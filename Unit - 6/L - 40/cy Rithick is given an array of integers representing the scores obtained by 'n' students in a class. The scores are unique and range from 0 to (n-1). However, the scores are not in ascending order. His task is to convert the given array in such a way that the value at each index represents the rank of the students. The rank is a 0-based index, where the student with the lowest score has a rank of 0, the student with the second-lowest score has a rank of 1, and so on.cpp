











#include <iostream>
#include <vector>

using namespace std;

vector<int> convertToRanks(vector<int>& scores) {
    int n = scores.size();
    vector<int> ranks(n);

    for (int i = 0; i < n; i++) {
        int rank = 0;
        for (int j = 0; j < n; j++) {
            if (i != j && scores[j] < scores[i]) {
                rank++;
            }
        }
        ranks[i] = rank;
    }

    return ranks;
}

int main() {
    int n;
    cin >> n;
    if(n<=0){
        cout<<"-1";
    }
    else{
    vector<int> scores(n);
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }
    cout<<"Input Array: ";
    for(int i=0;i<n;i++){
        cout<<scores[i]<<" ";
    }
    cout<<endl;

    vector<int> ranks = convertToRanks(scores);
cout<<"Converted Array: ";
    for (int i = 0; i < n; i++) {
        cout << ranks[i] << " ";
    }
    cout << endl;}

    return 0;
}

