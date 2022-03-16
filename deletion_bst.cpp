#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node*left;
    Node*right;
};
Node*create_tree(int data)
{
    Node*n=new Node;
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;

}
void inorder(Node*root)
{
    if(root!=NULL)
    {
    inorder(root->left);
    cout<<" "<<root->data<<"->";
    inorder(root->right);

    }
}

Node*predessor(Node*root)
{
    root=root->left;
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root;

}

Node*deletion(Node*root,int key)
{
    Node*ipre;
    if(root==NULL)
    {
    return NULL;

    }
    if(root->left==NULL && root->right==NULL)
    {
        free(root);
        return NULL;
    }
    {
        
    }
    if(root->data>key)
    {
        root->left=deletion(root->left,key);
    }
    else if(root->data<key)
    {
        root->right=deletion(root->right,key);
    }
    else{
        ipre=predessor(root);
        root->data=ipre->data;
        root->left=deletion(root->left,ipre->data); 
        }
    return root;
}

int main(){
    int m;
 Node*p=create_tree(8);
 Node*p1=create_tree(3);
 Node*p2=create_tree(10);
 Node*p3=create_tree(1);
 Node*p4=create_tree(6);
 Node*p5=create_tree(14);
 Node*p6=create_tree(4);
 Node*p7=create_tree(7);
 Node*p8=create_tree(13);


p->left=p1;
p->right=p2;
p2->right=p5;
p5->left=p8;
p1->right=p4;
p1->left=p3;
p4->left=p6;
p4->right=p7;
cout<<"inorder";
inorder(p);
cout<<endl;

// cout<<"enter the number to be delte :"<<endl;
// cin>>m;
deletion(p,14);
cout<<"order after deletion"<<endl;
inorder(p);

    
return 0;
}