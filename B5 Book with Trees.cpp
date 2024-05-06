#include <iostream>
#include <vector>
#include <string>
struct Node {
    std::string data;
    std::vector<Node*> c;  // Vector to store child nodes
    Node(const std::string& data) : data(data) {}
};

void printTree(const Node* n) {
    if (n == NULL) {
        return;
    }
    std::cout << n->data << std::endl;
    for (const Node* child : n->c) {
        printTree(child);
    }
}

int main() {
    Node* root = new Node("Book");
    Node* chapter1 = new Node("Chapter 1");
    Node* chapter2 = new Node("Chapter 2");
    n->c.push_back(chapter1);
	n->c.push_back(chapter2);

    Node* section1_1 = new Node("Section 1.1");
    Node* section1_2 = new Node("Section 1.2");
    chapter1->c.push_back(section1_1);
    chapter1->c.push_back(section1_2);

    Node* section2_1 = new Node("Section 2.1");
    chapter2->c.push_back(section2_1);

    Node* subsection1_1_1 = new Node("Subsection 1.1.1");
    section1_1->children.push_back(subsection1_1_1);
    printTree(n);
    delete n; // Delete recursively to avoid memory leaks
    return 0;
}
