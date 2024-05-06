#include <iostream>
#include <vector>
#include <string>
using namespace std;
// Node struct to represent chapters, sections, and subsections
struct Node {
    string title;
    vector<Node*>child;
    Node(const string &title):title(title) {}
    ~Node() {
        for (Node*ch:child) {
            delete ch; }
    }
};
void printtree(Node*node,int depth=0) {
    for(int i=0;i<depth;i++) {
        cout<<""<<endl; }
    cout<<"-"<<node->title<<endl;
    for (Node*ch:node->child) {
        printtree (ch,depth+1) }
};
int main() {
    // Create root node for the book
    Node* book = new Node("Book Title");

    // Create child nodes for chapters
    Node* chapter1 = new Node("Chapter 1");
    Node* chapter2 = new Node("Chapter 2");
    book->child.push_back(chapter1);
    book->child.push_back(chapter2);

    // Create child nodes for sections within chapters
    Node* section1_1 = new Node("Section 1.1");
    Node* section1_2 = new Node("Section 1.2");
    chapter1->child.push_back(section1_1);
    chapter1->child.push_back(section1_2);

    Node* section2_1 = new Node("Section 2.1");
    chapter2->child.push_back(section2_1);

    // Create child nodes for subsections (optional)
    Node* subsection1_1_1 = new Node("Subsection 1.1.1");
    section1_1->child.push_back(subsection1_1_1);

    // Print the tree structure
    printTree(book);

    // Clean up memory (optional)
    delete book; // Delete recursively to avoid memory leaks
    return 0;
}
