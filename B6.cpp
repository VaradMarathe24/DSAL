#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left,*right;
    Node(int data) {
        this->data = data;
        left = right = NULL;
    } };
class BinarySearchTree {
private: Node* root;
    Node* insertHelper(Node* current, int data) {
        if (current == NULL) {
            return new Node(data);
        }
        if (data < current->data) {
            current->left = insertHelper(current->left, data);
        } else if (data > current->data) {
            current->right = insertHelper(current->right, data);
        }
        return current;
    }
    int findLongestPath(Node* current, int pathLength) {
        if (current == NULL) {
            return pathLength;
    }
        int leftPathLength = findLongestPath(current->left, pathLength + 1);
        int rightPathLength = findLongestPath(current->right, pathLength + 1);
        return max(leftPathLength, rightPathLength);
    }
    int findMin(Node* current) {
        if (current == NULL) {
            return INT_MAX; // Handle empty tree case
        }
        int leftMin = findMin(current->left);
        return min(current->data, leftMin);
    }
    void swapLeftRight(Node* current) {
        if (current == NULL) {
            return;
        }
        Node* temp = current->left;
        current->left = current->right;
        current->right = temp;
        swapLeftRight(current->left);
        swapLeftRight(current->right);
    }
    Node* searchHelper(Node* current, int data) {
        if (current ==NULL || current->data == data) {
            return current;
        }
        if (data < current->data) {
            return searchHelper(current->left, data);
        } else {
            return searchHelper(current->right, data);
        }
    }
public: BinarySearchTree() {
        root = NULL;
    }
    void insert(int data) {
        root = insertHelper(root, data);
    }
    int findLongestPath() {
        return findLongestPath(root, 0);
    }
    int findMin() {
        return findMin(root);
    }
    void swapLeftRight() {
        swapLeftRight(root);
    }
    bool search(int data) {
        return searchHelper(root, data) != NULL;
    }
};
int main() {
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);
    cout << "Longest path length: " << bst.findLongestPath() << endl;
    cout << "Minimum value: " << bst.findMin() << endl;
    bst.swapLeftRight();
    if (bst.search(70)) {
        cout << "70 found in the tree (after swap)" << endl;
    } else {
        cout << "70 not found in the tree (after swap)" << endl;
    }
    return 0;
}

