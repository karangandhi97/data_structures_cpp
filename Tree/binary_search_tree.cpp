//
// Created by Karan on 3/19/2020.
//
#include<iostream>
#include<stdlib.h>
using namespace std;
class bst
{
public:
    int value,count;
    bool exist1,exist2;
    bst()
    {
        count=0;
        exist1=exist2=false;
    }
    struct node
    {
        int data;
        struct node *right;
        struct node *left;
    }*list=NULL,*p,*q,*r,*s,*t,*z,*temp;
    void get_data()
    {
        int choice;
        do
        {
            cout<<"Enter choice:\n1.Insert\t2.Delete\t3.Display\t4.Search\t5.Traverse\t6.Exit\n";
            cin>>choice;
            switch(choice)
            {
                case 1:
                    cout<<"Enter data:";
                    cin>>value;
                    p=(struct node*)malloc(sizeof(node));
                    p->data=value;
                    p->left=NULL;
                    p->right=NULL;
                    insert(p,list);
                    break;
                case 2:
                    if(list==NULL)
                    {
                        cout<<"BST Empty!\n";
                    }
                    else
                    {
                        cout << "Enter Key to be deleted:";
                        cin >> value;
                        search(list, value);
                        if(exist1==true ^ exist2==true)
                        {
                            cout<<"Key does not exist.\n";
                        }
                        else
                        {
                            delet(list,value);
                        }
                    }
                    break;
                case 3:
                    if(list==NULL)
                    {
                        cout<<"Tree is empty.\n";
                        break;
                    }
                    else
                    {
                        cout<<"Levels:\n0\t1\t2\t3\t4";
                        show_data(list,0);
                    }
                    break;
                case 4:
                    if(list==NULL)
                    {
                        cout<<"BST Empty!\n";
                    }
                    else
                    {
                        cout << "Enter Key to be searched:";
                        cin >> value;
                        search(list, value);
                    }
                    if(exist1==true ^ exist2==true)
                    {
                        cout<<"Key does not exist.\n";
                    }
                    break;
                case 5:
                    traverse();
                    break;
                case 6:
                    break;
                default:
                    cout<<"Incorrect choice.\n";
                    break;
            }
        }while(choice!=6);
    }
    void insert(node* n,node* parent)//n=new node,parent=Current node
    {
        if (list == NULL)
        {
            list=n;
            cout<<"Root Node is Added"<<endl;
            cout<<"Data:"<<list->data<<"\tLEFt:"<<list->left<<"\tright:"<<list->right;
            return;
        }
        if (parent->data == n->data)
        {
            cout<<"Duplicate value"<<endl;
            return;
        }
        if (parent->data > n->data)//then insert on left
        {
            if (parent->left != NULL)//if left is not empty
            {
                insert(n, parent->left);
            }
            else//if left is empty
            {
                parent->left = n;
                s=parent;
                cout<<"\nNode Added To Left of "<<parent->data<<endl;
                parent=parent->left;
                return;
            }
        }
        else if(parent->data < n->data)
        {
            if (parent->right != NULL)
            {
                insert(n,parent->right);
            }
            else
            {
                parent->right = n;
                s=parent;
                cout<<"Node Added To Right of "<<parent->data<<endl;
                parent=parent->right;
                return;
            }
        }
    }

    struct node* delet(node* parent, int key)
    {
        if(parent==NULL)//node does not exist
        {
            return parent;//end recursion cycle for the node
        }
        if(key<parent->data)//left subtree
        {
            parent->left=delet(parent->left,key);
        }
        else if(key>parent->data)//right subtree
        {
            parent->right=delet(parent->right,key);
        }
        else//found node
        {
            if(parent->left==NULL)//no left child
            {
                r=parent->right;
                free(parent);
                return r;
            }
            else if(parent->right==NULL)//no right child
            {
                r=parent->left;
                free(parent);
                return r;
            }
            r=parent->right;
            while (r!=NULL && r->left != NULL)//finding inorder successor. always the most left leaf node of the right child
            {
                r=r->left;
            }
            parent->data=r->data;
            parent->right=delet(parent->right,r->data);//free inorder successor node which will be copied
        }
        return parent;
    }
    void search(node* n, int key)
    {
        if(n->data==key)
        {
            exist1=exist2=true;
            cout<<"Key found!\n";
            cout<<"Child Nodes of Key:\t";
            if(n->left==NULL)
            {
                cout<<"Left Child: 0\t";
            }
            else
            {
                cout<<"Left Child: "<<n->left->data<<"\t";
            }
            if(n->right==NULL)
            {
                cout<<"Right Child: 0\t";
            }
            else
            {
                cout<<" Right Child: "<<n->right->data<<"\n";
            }
        }
        else if(n->data< key)
        {
            if(n->right!=NULL)
            {
                exist1=true;
                search(n->right, key);
            }
            else
            {
                exist1=false;
            }
        }
        else if(n->data>key)
        {
            if(n->left!=NULL)
            {
                exist2=true;
                search(n->left, key);
            }
            else
            {
                exist2 = false;
            }
        }
    }
    void traverse()
    {
        int order,rec;
        cout<<"1.Recursively\t2.Non-recursively\n";
        cin>>rec;
        if(rec==1)
        {
            cout<<"1.Inorder\t2.Preorder\t3.Postorder\n";
            cin>>order;
            switch(order)
            {
                case 1:
                    r_inorder(list);
                    cout<<"\n";
                    break;
                case 2:
                    r_preorder(list);
                    cout<<"\n";
                    break;
                case 3:
                    r_postorder(list);
                    cout<<"\n";
                    break;
                default:
                    cout<<"Invalid choice.\n";
            }
        }
        else if(rec==2)
        {
            cout<<"1.Inorder\t2.Preorder\t3.Postorder\n";
            cin>>order;
            switch(order)
            {
                case 1:
                    nr_inorder(list);
                    cout<<"\n";
                    break;
                case 2:
                    nr_preorder(list);
                    cout<<"\n";
                    break;
                case 3:
                    nr_postorder(list);
                    cout<<"\n";
                    break;
                default:
                    cout<<"Invalid choice.\n";
            }
        }
        else
        {
            cout<<"Invalid choice.\n";
            traverse();
        }
    }
    void r_inorder(node* parent)
    {
        if (parent != NULL)
        {
            r_inorder(parent->left);
            cout<<parent->data<<" ";
            r_inorder(parent->right);
        }
    }
    void r_preorder(node* parent)
    {
        if (parent != NULL)
        {
            cout<<parent->data<<" ";
            r_preorder(parent->left);
            r_preorder(parent->right);
        }
    }
    void r_postorder(node* parent)
    {
        if (parent != NULL)
        {
            r_postorder(parent->left);
            r_postorder(parent->right);
            cout<<parent->data<<" ";
        }
    }
    void nr_inorder(node* parent)
    {
        if (parent == NULL)
            cout<<"Tree is empty.\n";
        else
        {
            while (parent != NULL)
            {
                if (parent->left == NULL)//last node in left subtree
                {
                    cout << parent->data<< " " ;//L absent. print D.
                    parent = parent->right;//go to R
                }
                else
                {
                    p = parent->left;
                    while (p->right != NULL && p->right != parent)
                    {
                        p = p->right;
                    }
                    if (p->right == NULL)
                    {
                        p->right = parent;//keep a pointer at parent node
                        parent = parent->left;//move parent towards left subtree
                    }
                    else
                    {
                        p->right = NULL;
                        cout << parent->data<< " ";
                        parent = parent->right;
                    }
                }
            }
        }
    }
    void nr_preorder(node* parent)
    {
        while (parent!=NULL)
        {
            if (parent->left == NULL)
            {
                cout<<parent->data<<" ";
                parent = parent->right;
            }
            else
            {
                p = parent->left;
                while (p->right && p->right != parent)
                {
                   p = p->right;
                }
                if (p->right == parent)
                {
                    p->right = NULL;
                    parent = parent->right;
                }
                else
                {
                    cout<<parent->data<<" ";
                    p->right = parent;
                    parent = parent->left;
                }
            }
        }
    }
    void nr_postorder(node* parent)
    {
        p=(struct node*)malloc(sizeof(node));
        p->left = parent;
        q = p;
        while (count!=2)
        {
            if (q->left == NULL)
            {
                q = q->right;
            }
            else
            {
                z = q->left;
                while (z->right != NULL && z->right != q)
                {
                    z = z->right;
                }
                if (z->right == NULL)
                {
                    z->right = q;
                    q = q->left;
                }
                else
                {
                    r = q;
                    s = q->left;
                    while (s != q)
                    {
                        if(s==list)
                        {
                            count++;
                        }
                        t = s->right;
                        s->right = r;
                        r = s;
                        s = t;
                    }
                    r = q;
                    s = z;
                    while (s != q)
                    {
                        cout << s->data << " ";
                        if(s==list)
                        {
                            count++;
                        }
                        t = s->right;
                        s->right = r;
                        r = s;
                        s = t;
                    }
                    z->right = NULL;
                    q = q->right;
                }
            }
        }
    }
    void show_data(node* parent,int space)
    {
        if(parent==NULL)// to end particular recursion if the node does not exist
        {
            return;
        }
        space+=8;
        show_data(parent->right,space);
        cout<<"\n";
        for(int i=8;i<space;i++)
        {
            cout<<" ";
        }
        cout<<parent->data<<"\n";
        show_data(parent->left,space);
    }
};
int main()
{
    bst obj1;
    obj1.get_data();
}

