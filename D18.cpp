#include <iostream>
#include <vector>
using namespace std;
struct Node {
    int key;
    double probability;
    Node* left;
    Node* right;

    Node(int key, double probability) : key(key), probability(probability), left(nullptr), right(nullptr) {}
};
double expectedCost(const vector<double>& p, int i, int j) {
    if (i > j) {
        return 0; // Empty subtree has zero cost
    }
    double sum = 0;
    for (int k = i; k <= j; ++k) {
        sum += p[k];
    }
    int root = i;
    for (int k = i + 1; k <= j; ++k) {
        if (p[k] > p[root]) {
            root = k;
        }
    }
    return sum + expectedCost(p, i, root - 1) + expectedCost(p, root + 1, j);
}
Node* constructOBST(const vector<double>& p, int i, int j) {
    if (i > j) {
        return nullptr; // Empty subtree
    }
    int root = i;
    for (int k = i + 1; k <= j; ++k) {
        if (p[k] > p[root]) {
            root = k;
        }
    }

    Node* node = new Node(p[root], p[root]);
    node->left = constructOBST(p, i, root - 1);
    node->right = constructOBST(p, root + 1, j);
    return node;
}
int main() {
    int n; // Number of keys
    cout << "Enter the number of keys: ";
    cin >> n;
    vector<double> p(n); // Access probabilities for each key
    cout << "Enter the access probabilities for each key:\n";
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    double sum = 0;
    for (double prob : p) {
        sum += prob;
    }
    if (abs(sum - 1.0) > 1e-6) {
        cout << "Error: Probabilities must sum to 1.0\n";
        return 1;
    }
    Node* root = constructOBST(p, 0, n - 1);
    return 0;
}

