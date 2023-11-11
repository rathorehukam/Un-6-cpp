









#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function template to process URLs
template<typename T>
void processURLs(const vector<T>& urls) {
    for (const auto& url : urls) {
        cout << url.first << ": ";
        if (url.second == 1) {
            cout << "Indexed successfully";
        } else {
            cout << "Indexing failed";
        }
        cout << endl;
    }
}

int main() {
    int N;
    cin >> N;
    vector<pair<string, int>> urls;

    for (int i = 0; i < N; i++) {
        string url;
        int status;
        cin >> url >> status;
        urls.push_back(make_pair(url, status));
    }

    processURLs(urls);

    return 0;
}
