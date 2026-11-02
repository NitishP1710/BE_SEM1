#include<bits/stdc++.h>
using namespace std;
struct Node
{
    char ch;
    int frq;
    Node *left,*right;
    Node(char c, int f){
        ch=c;
        frq=f;
        left=right=nullptr;
    }
};
struct Comparator{
 bool operator()(Node* &A, Node* &B){
    return A->frq > B-> frq;
 }
};
void encode(Node * root, string code){
    if(root==nullptr){
        return ;
    }
    if(root->left==nullptr && root->right==nullptr){
        if(code.size()>0){
            cout<<"Char "<<root->ch<<" : "<<code<<endl;
        }
        else{
            cout<<"Char "<<root->ch<<" : "<<"0"<<endl;
        }
        return; 
    }
    encode(root->left,code+'0');
    encode(root->right,code+'1');
    return;
}
int main(){
   int n;
   cout<<"Enter a number of charcters :";
   cin>>n;
   priority_queue<Node*,vector<Node*>,Comparator> pq;
   for(int i=0;i<n;i++){
     char ch;
     int frq;
     cout<<"Enter char and its frequency :";
     cin>>ch>>frq;
     pq.push(new Node(ch,frq));
   }
   while(pq.size()>1){
    Node*leftNode=pq.top();
    pq.pop();
    Node*rightNode=pq.top();
    pq.pop();
    Node* parent=new Node('#',leftNode->frq+rightNode->frq);
    parent->left=leftNode;
    parent->right=rightNode;
    pq.push(parent);
   }

   Node*root=pq.top();
   cout<<"Huffman Codes"<<endl;
   encode(root,"");

}