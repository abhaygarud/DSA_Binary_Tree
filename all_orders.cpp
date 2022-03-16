#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node*left;
    Node*right;
};

Node*Create_Order(int data)
{
    Node*n=new Node;
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

void Post_Order(Node*root)
{
    if(root!=NULL)
    {
        Post_Order(root->left);
        Post_Order(root->right);
        cout<<"-> "<<root->data<<" "<<endl;
    }
}
void Pre_Order(Node*root)
{
    if(root!=NULL)
    {
        cout<<"-> "<<root->data<<endl;
        Pre_Order(root->left);
        Pre_Order(root->right);
    }
}
inOrder(Node*root)
{
    if(root!=NULL)
    {
        inOrder(root->left);
        cout<<" "<<root->data<<endl;
        inOrder(root->right);
    }
}

int main(){
    /* 
      4
    /  \
    1   6
  /   \ 
  5    2

  postorder->5-2-1-6-4
  preorder-> 1-4-5-2-6
  inoder->5-1-2-4-6
     */



    Node*p=Create_Order(4);
    Node*p1=Create_Order(1);
    Node*p2=Create_Order(6);
    Node*p3=Create_Order(5);
    Node*p4=Create_Order(2);


    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    cout<<"Post Order"<<endl;
    Post_Order(p);
    cout<<"pre order"<<endl;
    Pre_Order(p);
    cout<<"inorder"<<endl;
    inOrder(p);

    
    return 0;
}