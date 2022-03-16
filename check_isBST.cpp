#include <iostream>
using namespace std;

struct  Node
{
    int data;
    Node*left;
    Node*right;
};

Node*Create_tree(int data)
{
    Node*n=new Node;
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
void Inorder(Node*root)
{
    if(root!=NULL){

    Inorder(root->left);
    cout<<" "<<root->data;
    Inorder(root->right);
    }
}

int isBST(Node*root)
{
    static Node*prev=NULL;
    if (root!=NULL)
    {
        if(!isBST(root->left))
        {
        return 0;

        }
        if(prev!=NULL && root->data <=prev->data)
        {

           return 0;
        }
    prev=root;
    return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

// Node*searching_BST(Node*root,int key)
// {
    
//     if(root==NULL)
//     {
//     return NULL;

//     }
//     if(root->data==key)
//     {

//     return root;
//     }
//     else if(root->data>key)
//     {
//         return searching_BST(root->left,key);
//     }
//     else{
//         return searching_BST(root->right,key);
//     }

// }

Node*searching_BST(Node*root,int key)
{
    while(root!=NULL)
    {

    if(key==root->data)
    {
        return root;
    }
    else if(key<root->data)
    {
        root=root->left;
    }
    else
    {
        root=root->right;
    }
    }
}


Node*insert(Node*root,int key)
{
    Node*prev=NULL;
    while(root!=NULL)
    {
        prev=root;
        if(root->data==key)
        {
            cout<<"operation performing already exist"<<endl;
            return NULL;
        }
        if(root->data>key)
        {
            root=root->left;
        }
        else{
            root=root->right;
        }
    }

    Node*p5=Create_tree(key);
    if(prev->data>key)
    {
            prev->left=p5 ;
    }
    else
    {
        prev->right=p5;
    }


}
    






int main(){
    Node*p=Create_tree(5);
    Node*p1=Create_tree(3);
    Node*p2=Create_tree(6);
    Node*p3=Create_tree(1);
    Node*p4=Create_tree(4);

   
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    
    cout<<"Inorder"<<endl;
    Inorder(p);
    cout<<endl;


   cout<<"----------------------------------------------------" <<endl;
   if(isBST(p))
   {
       cout<<"this is a BST"<<endl;
   }
   else{
       cout<<"this is not and BST"<<endl;
   }



    cout<<"---------------------------------------------------"<<endl;
    Node*n=searching_BST(p,9);
    if(n!=NULL)
    {
        cout<<"found ->"<<n->data;
    }
    else{
        cout<<"not found"<<endl;
    }
    insert(p,2);
    cout<<"-----------------------------------------------"<<endl;
    cout<<"inserted ->"<<p->left->left->right->data;
    Inorder(p);
    return 0;
}