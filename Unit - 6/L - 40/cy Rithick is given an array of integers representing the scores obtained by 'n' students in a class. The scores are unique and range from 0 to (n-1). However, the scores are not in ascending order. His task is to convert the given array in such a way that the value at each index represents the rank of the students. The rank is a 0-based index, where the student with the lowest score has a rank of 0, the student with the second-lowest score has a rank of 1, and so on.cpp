










#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> convertToRanks(const vector<int>& scores) {
    // Create a copy of the scores array and sort it
    vector<int> sortedScores = scores;
    sort(sortedScores.begin(), sortedScores.end());

    // Map each score to its rank
    unordered_map<int, int> scoreToRank;
    for (int i = 0; i < sortedScores.size(); i++) {
        scoreToRank[sortedScores[i]] = i;
    }

    // Convert the original scores to their ranks
    vector<int> ranks;
    for (int score : scores) {
        ranks.push_back(scoreToRank[score]);
    }

    return ranks;
}

int main() {
    int n;
    cin >> n;

    // Validate array size
    if (n <= 0) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> scores(n);
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }

    vector<int> ranks = convertToRanks(scores);

    cout << "Input Array: ";
    for (int score : scores) {
        cout << score << " ";
    }
    cout << endl << "Converted Array: ";
    for (int rank : ranks) {
        cout << rank << " ";
    }
    cout << endl;

    return 0;
}
