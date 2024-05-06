#include <iostream>
#include <vector>
#include <string>

// Node struct to represent chapters, sections, and subsections
struct Node {
    std::string data;
    std::vector<Node*> children;  // Vector to store child nodes

    Node(const std::string& data) : data(data) {}
};

// Function to print all nodes in a preorder traversal
void printTree(const Node* root) {
    if (root == nullptr) {
        return;
    }
    std::cout << root->data << std::endl;
    for (const Node* child : root->children) {
        printTree(child);
    }
}

int main() {
    // Create root node for the book
    Node* root = new Node("Book");

    // Create child nodes for chapters
    Node* chapter1 = new Node("Chapter 1");
    Node* chapter2 = new Node("Chapter 2");
    root->children.push_back(chapter1);
    root->children.push_back(chapter2);

    // Create child nodes for sections within chapters
    Node* section1_1 = new Node("Section 1.1");
    Node* section1_2 = new Node("Section 1.2");
    chapter1->children.push_back(section1_1);
    chapter1->children.push_back(section1_2);

    Node* section2_1 = new Node("Section 2.1");
    chapter2->children.push_back(section2_1);

    // Create child nodes for subsections (optional)
    Node* subsection1_1_1 = new Node("Subsection 1.1.1");
    section1_1->children.push_back(subsection1_1_1);

    // Print the tree structure
    printTree(root);

    // Clean up memory (optional)
    delete root; // Delete recursively to avoid memory leaks
    return 0;
}
