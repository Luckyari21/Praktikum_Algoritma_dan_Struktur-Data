#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<char> labels(N);
    for (int i = 0; i < N; i++) {
        cin >> labels[i];
    }
\
    vector<vector<int>> matrix(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Adjacency List:" << endl;
    for (int i = 0; i < N; i++) {
        cout << labels[i] << " -> ";
        bool hasEdge = false;
        bool first = true;
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] > 0) {
                if (!first) cout << ", ";
                cout << "(" << labels[j] << "," << matrix[i][j] << ")";
                first = false;
                hasEdge = true;
            }
        }
        if (!hasEdge) {
            cout << "-";
        }
        cout << endl;
    }

    return 0;
}