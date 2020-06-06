//
// Created by Karan on 2/28/2020.
//
#include<iostream>
#include<stdlib.h>
using namespace std;
class poly
{
public:
    int choice,value;
    struct node
    {
        int coeff,expo;
        struct node *next;
    }*p1=NULL,*p2=NULL,*p3=NULL,*p,*q,*r,*s,*t;
    void get_data()
    {

        cout<<"After end of polynomials, enter coefficient as 0\n";
        cout<<"Enter first polynomial equation:\n";
        get_equation(1);
        cout<<"Enter second polynomial equation:\n";
        get_equation(2);
        sort(p1);
        sort(p2);
        int choice;
        cout<<"Select an option:\n1.Addition of polynomials\n2.Subtraction of polynomials\n";
//        do {
        cin >> choice;
        switch (choice)
        {
            case 1:
                addition();
                break;
            case 2:
                subtraction();
                break;
            default:
                cout << "Invalid option.\n";
        }
//        }while(choice!=1 || choice!=2);
    }
    void get_equation(int i)
    {
        int temp1,temp2;
        while(1)
        {
            cout<<"Coefficient:";
            cin>>temp1;
            if(temp1==0)
            {
                break;
            }
            cout<<"Exponential:";
            cin>>temp2;
            p=(struct node*)malloc(sizeof(node));
            p->coeff=temp1;
            p->expo=temp2;
            p->next=NULL;
            if(i==1)//if first polynomial
            {
                if(p1==NULL)
                {
                    p1=p;//FOR SORTING
                }
                else
                {
                    q=p1;
                    while(q->next!=NULL)
                    {
                        q=q->next;
                    }
                    q->next=p;
                }
            }
            else if(i==2)//if second polynomial
            {
                if(p2==NULL)
                {
                    p2=p;//FOR SORTING
                }
                else
                {
                    q=p2;
                    while(q->next!=NULL)
                    {
                        q=q->next;
                    }
                    q->next=p;
                }
            }
        }
    }
    void sort(struct node *x)
    {
        int temp;
        q=x;
        while(q!=NULL)
        {
            r=q->next;
            while(r!=NULL)
            {
                if(q->expo<r->expo)
                {
                    temp=q->coeff;
                    q->coeff=r->coeff;
                    r->coeff=temp;
                    temp=q->expo;
                    q->expo=r->expo;
                    r->expo=temp;
                }
                r=r->next;
            }
            q=q->next;
        }
    }
    void addition()
    {
        q=p1;r=p2;
        p3 = (struct node *) malloc(sizeof(node));
        p=p3;
        while(q!=NULL && r!=NULL)
        {
            if (q->expo > r->expo)
            {
                p->coeff = q->coeff;
                p->expo = q->expo;
                q = q->next;
            }
            else if (q->expo < r->expo)
            {
                p->coeff = r->coeff;
                p->expo = r->expo;
                r = r->next;
            }
            else if (q->expo == r->expo)
            {
                p->coeff = q->coeff + r->coeff;
                p->expo = q->expo;
                q = q->next;
                r = r->next;
            }
            p->next = (struct node *) malloc(sizeof(node));
            s=p;
            p=p->next;
        }
        if(q==NULL)
        {
                s->next=r;
        }
        else if(r==NULL)
        {
                s->next=q;
        }
    }
    void subtraction()
    {
        q=p1;r=p2;
        p3 = (struct node *) malloc(sizeof(node));
        p=p3;
        while(q!=NULL && r!=NULL)
        {
            if (q->expo > r->expo)
            {
                p->coeff = q->coeff;
                p->expo = q->expo;
                q = q->next;
            }
            else if (q->expo < r->expo)
            {
                p->coeff = r->coeff;
                p->expo = r->expo;
                r = r->next;
            }
            else if (q->expo == r->expo)
            {
                p->coeff = q->coeff - r->coeff;
                p->expo = q->expo;
                q = q->next;
                r = r->next;
            }
            p->next = (struct node *) malloc(sizeof(node));
            s=p;
            p=p->next;
        }
        if(q==NULL)
        {
            s->next=r;
        }
        else if(r==NULL)
        {
            s->next=q;
        }
    }
    void show_data()
    {
        q = p3;
        cout << "Result:\n";
            cout << q->coeff << "X^" << q->expo;
            q = q->next;
            p = q;
            while (p!= NULL)
            {
                if(q->coeff>0)
                {
                    cout <<" + "<< q->coeff << "X^" << q->expo;
                }
                else if(q->coeff<0)
                {
                    cout << q->coeff << "X^" << q->expo;
                }
                q = q->next;
                p = q;
            }
        cout << "\n";
    }
};
int main()
{
    poly obj1;
    obj1.get_data();
    obj1.show_data();
    return 0;
}
//10 10 8 5 7 3 45 0 0
//12 10 3 8 7 5 5 2 4 1 0
