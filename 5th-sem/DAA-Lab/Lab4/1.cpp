#include <bits/stdc++.h>

using namespace std;

vector<vector<float>> findWeights(vector<vector<float>> ar) {
    int n = ar.size(), m = ar[0].size();
    vector<vector<float>> wt;
    vector<float> temp;
    for (int i = 0; i < n; i++) {
        temp.clear();
        for (int j = 0; j < m; j++) {
            temp.push_back(-log2(ar[i][j]));
        }
        wt.push_back(temp);
    }
    return wt;
}

void shortestPath(vector<vector<float>> wt, vector<vector<float>> ed, unordered_map<int, string> mp) {
    int n = wt.size(), m = wt[0].size();

    vector<float> pi(n, 2>>10), values(n, 1);
    pi[0] = 0;
    vector<int> path(n, 0);
    path[0] = -1;
    bool val = 1;
    for (int i = 0; i < n+1; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (pi[k] > pi[j] + wt[j][k]) {
                    if (i == n && val) {
                        cout << "Negative Cycle\n";
                        val = 0;
                        break;
                    }
                    pi[k] = pi[j] + wt[j][k];
                    values[k] = values[j]*ed[j][k];
                    path[k] = j;
                }
            }
        }
    }
    cout << "\n\n\n";
    int cur = n-1;
    // while (cur != 0) {
    //     cout << mp[cur] << " <- ";
    //     cur = path[cur];
    // }
    cout << endl;
    printf("Shortest path value = %f \n", values[n-1]);
}

void fillRest(vector<vector<float>> &curr) {
    int n = curr.size(), m = curr[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j < i) curr[i][j] = 1/curr[j][i];
            else break; 
        }
    }
} 

int main() {
    unordered_map<int, string> mp;
    mp[0] = "Gold";
    mp[1] = "Australian Dollar";
    mp[2] = "Euro";
    mp[3] = "Pound";
    mp[4] = "Cannadian Dollar";
    mp[5] = "Indian Rupee";
    mp[6] = "Swiss Franc";
    mp[7] = "Chinese Yuan";
    mp[8] = "Yen";
    mp[9] = "US Dollar";

    vector<vector<float>> currConvert= {
        {1, 2398.4, 1490.6, 1282.9, 2198.1, 128100, 1615.6, 11154, 193250, 1725.3},
        {1, 1, 0.62151, 0.53495, 0.91656, 53.409, 0.67341, 4.6498, 80.566, 0.71931},
        {1, 1, 1, 0.86070, 1.4750, 85.94, 1.0836, 7.4813, 129.63, 1.1573},
        {1, 1, 1, 1, 1.7134, 99.865, 1.2591, 8.6921, 150.64, 1.3448},
        {1, 1, 1, 1, 1, 58.28, 0.73481, 5.0730, 87.923, 0.78475},
        {1, 1, 1, 1, 1, 1, 0.012608, 0.087042, 1.5086, 0.013467},
        {1, 1, 1, 1, 1, 1, 1, 6.9028, 119.65, 1.0680},
        {1, 1, 1, 1, 1, 1, 1, 1, 17.333, 0.15472},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 0.0089264},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };
    fillRest(currConvert);

    vector<vector<float>> weights = findWeights(currConvert);
    cout << "Hello" << endl;

    shortestPath(weights, currConvert, mp);
    
}