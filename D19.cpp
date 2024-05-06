#include <iostream>
#include <string>
using namespace std;
struct Node {
    string key,value;
    Node *left;
    Node *right;
    int height; };
class Dictionary {
public: Dictionary() : root(nullptr) {}
    void add(const string &key, const string &value) {
        root = add(root, key, value);
    }
    void remove(const string &key) {
        root = remove(root, key);
    }
    void update(const string &key, const string &value) {
        Node *node = find(root, key);
        if (node != nullptr) {
            node->value = value;
        } else {
            cout << "Key not found." << endl;
        }
    }
    void displayAscending() {
        displayAscending(root); }
    void displayDescending() {
        displayDescending(root);  }
    int getMaxComparisons() {
        return root ? root->height : 0; }
private: Node *root;
    Node *createNode(const string &key, const string &value) {
        Node *node = new Node;
        node->key = key;
        node->value = value;
        node->left = node->right = nullptr;
        node->height = 1;
        return node;
    }
    int height(Node *node) {
        if (!node) return 0;
        return node->height;
    }
    Node *rightRotate(Node *y) {
        Node *x = y->left;
        Node *T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }
    Node *leftRotate(Node *x) {
        Node *y = x->right;
        Node *T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }
    int getBalance(Node *node) {
        if (!node) return 0;
        return height(node->left) - height(node->right);
    }
    Node *add(Node *node, const string &key, const string &value) {
        if (!node) return createNode(key, value);
        if (key < node->key) {
            node->left = add(node->left, key, value);
        } else if (key > node->key) {
            node->right = add(node->right, key, value);
        } else { node->value = value;
            return node;
        }
        node->height = max(height(node->left), height(node->right)) + 1;
        int balance = getBalance(node);
        if (balance > 1 && key < node->left->key) {
            return rightRotate(node);
        }
        if (balance < -1 && key > node->right->key) {
            return leftRotate(node);
        }
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }
    Node *minValueNode(Node *node) {
        Node *current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }
    Node *remove(Node *root, const string &key) {
        if (!root) return root;
        if (key < root->key) {
            root->left = remove(root->left, key);
        } else if (key > root->key) {
            root->right = remove(root->right, key);
        } else {
            if (!root->left || !root->right) {
                Node *temp = root->left ? root->left : root->right;
                if (!temp) {
                    temp = root;
                    root = nullptr;
                } else {
                    *root = *temp;
                }
                delete temp;
            } else {
                Node *temp = minValueNode(root->right);
                root->key = temp->key;
                root->value = temp->value;
                root->right = remove(root->right, temp->key);
            }
        }
        if (!root) return root;
        root->height = max(height(root->left), height(root->right)) + 1;
        int balance = getBalance(root);
        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);
        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);
        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
    }
    Node *find(Node *node, const string &key) {
        if (!node) return nullptr;
        if (key == node->key)
            return node;
        else if (key < node->key)
            return find(node->left, key);
        else
            return find(node->right, key);
    }
    void displayAscending(Node *node) {
        if (!node) return;
        displayAscending(node->left);
        cout << node->key << ": " << node->value << endl;
        displayAscending(node->right);
    }
    void displayDescending(Node *node) {
        if (!node) return;
        displayDescending(node->right);
        cout << node->key << ": " << node->value << endl;
        displayDescending(node->left);
    } };
int main() {
    Dictionary dict;
    dict.add("apple", "A fruit");
    dict.add("banana", "Another fruit");
    dict.add("carrot", "A vegetable");
    dict.update("apple", "A juicy fruit");
    cout << "Dictionary in ascending order:" << endl;
    dict.displayAscending();
    cout << endl;
    cout << "Dictionary in descending order:" << endl;
    dict.displayDescending();
    cout << endl;
    dict.remove("banana");
    cout << "After deleting 'banana', dictionary in ascending order:" << endl;
    dict.displayAscending();
    cout << endl;
    cout << "Max comparisons required to find a keyword: " << dict.getMaxComparisons() << endl;
    return 0; }

