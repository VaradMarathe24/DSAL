#include<iostream>
#include<string>
#include<stack>
using namespace std;
//B11
//DICTIONARY
class Node
{
    public:
    Node *left,*right;
    string word,meaning;
    Node(){
        word ="";
        meaning = "";
        left=right = NULL;
    }
    Node(string s1,string s2){
        word =s1;
        meaning = s2;
        left=right = NULL;
    }
    bool compare(string s1,string s2){
        if(s1.empty() || s2.empty())
            return true;
        if(s1[0]>s2[0])
            return true;
        else if(s1[0]==s2[0])
            return compare(s1.substr(1),s2.substr(1));
        else 
            return false;
    }
    Node* insert(Node *root,string s1,string s2){
        if(root==NULL){
            root = new Node(s1,s2);
            return root;
        }
        if(compare(root->word,s1)){
            root->left = insert(root->left,s1,s2);
        }
        else
        {
            root->right = insert(root->right,s1,s2);
        }
        return root;
    }
    //ascending ORDER
    void inOrder(Node *root){
        if(root==NULL)
            return;
        inOrder(root->left);
        cout<<"Word: "<<root->word<<", Meaning: "<<root->meaning<<endl;
        inOrder(root->right);
    }
    //descending ORDER
    stack<string> desecendingOrder(Node *root,stack<string> s){
        if(root==NULL)
            return s;
        s=desecendingOrder(root->left,s);
        s.push(root->word);
        s=desecendingOrder(root->right,s);
        return s;
    }
    //SEARCH
    void search(Node *root,string word){
        if(root==NULL){
            cout<<endl<<"not found ";
            return;
        }
        if(root->word == word){
            cout<<endl<<"found";
            return;
        }
        if(compare(root->word,word))
            search(root->left,word);
        else
            search(root->right,word);
    }
    //UPDATE
    void update(Node *root,string word,string updateMeaning){
        if(root==NULL)
            return;
        if(root->word==word){
            root->meaning=updateMeaning;
            cout<<"\nUPDATED!~\n";
            return;
        }
        if(compare(root->word,word))
            update(root->left,word,updateMeaning);
        else
            update(root->right,word,updateMeaning);
    }
    //DELETE
    /*Node* deleteWord(Node *root,string word,string meaning){
        
        if(root==NULL)
            return NULL;

        if(compare(root->word,word))
            deleteWord(root->left,word,meaning);

        else if(!compare(root->word,word))
            deleteWord(root->right,word,meaning);

        else{ //the word matches!!

            if(root->left == NULL && root->right==NULL) 
                return NULL;
            else if(root->left==NULL)
                return root->right;
            else if(root->right==NULL)
                return root->left;
            else
            {
                //find the inOrder successor and replace 
                Node *succ = getSuccessor(root->right);
                root->word = succ->word;
                root->meaning = succ->meaning;
                //basically shifting everything towards left!!
                root->right = deleteWord(root->right,succ->word,succ->meaning);
            }
        }
    
        return root;

    }*/
    
    Node* getSuccessor(Node *root){
        while(root->left!=NULL)
        {
            root=root->left;
        }
        return root;
    }
    //MAX height
    int height(Node *root){
        if(root == NULL)
            return 0;
        int leftH = (height(root->left));
        int rightH = height(root->right);
        int max = (leftH>rightH) ? leftH : rightH;
        return max+1;
    }

};

int main(){

    cout<<endl<<"hello mf world\n";
    Node *root=NULL;
    root=root->insert(root,"Passion","Follow yours");
    root=root->insert(root,"Apple","Yum yum");
    root=root->insert(root,"Ball","smol smol");
    root=root->insert(root,"Zyzz","We go JIMMM");
    root=root->insert(root,"Pull ups","Somethin fatty cant do");
    root->inOrder(root);
    root->search(root,"passion");
    root->update(root,"Ball","big");
    cout<<endl<<root->height(root);
    string word,meaning;
    
    root->insert(root,"WEEWEE","Smol");
    root->inOrder(root);
    cout<<endl;
    stack<string>s;
    s= root->desecendingOrder(root,s);
    while(!s.empty()){
        cout<<endl<<s.top();
        s.pop();
    }
    cout<<endl<<endl;
}
