#include<iostream>
#include<stdlib.h>
using namespace std;
class dllist
{
	public:
	int choice,value;
	struct node
	{
	int data;
	struct node *next;
	struct node *prev;
	}*list=NULL,*p,*q,*r,*s,*t;
	void get_data()
	{
		do
		{
			cout<<"Enter choice:\n";
			cout<<"1.Insertion from beginning.\n2.Insertion from end.\n3.Insertion before an element.\n4.Insertion after an element.\n5.Deletion from beginning.\n6.Deletion from end.\n7.Deletion of an element.\n8.Counting number of elements.\n9.Reverse of linked list.\n10.Sorting of linked list.\n11.Display.\n12.Exit\n";
			cin>>choice;
			switch(choice)
			{
				case 1:
					insertb();
				break;

				case 2:
					inserte();
				break;

				case 3:
					insertbe();
				break;

				case 4:
					insertae();
				break;

				case 5:
					deleteb();
				break;

				case 6:
					deletee();
				break;

				case 7:
					deletes();
				break;

				case 8:
					count();
				break;

				case 9:
					reverse();
				break;

				case 10:
				    sort();
				break;

                case 11:
                    show_data();
                break;

				case 12:
				break;

				default:
					cout<<"Invalid choice.\n";
			}
		}while(choice!=12);
	}
	void insertb()
	{
		int temp;
		p=(struct node*)malloc(sizeof(node));
		cout<<"Enter data:\t";
		cin>>temp;
		p->data=temp;
		if(list==NULL)
        {
		    cout<<"Linked list does not exist.\nFirst node has been created\n";
			p->next=NULL;
			p->prev=NULL;
			list=p;		
		}
		else
		{
            p->next=list;
            p->prev=NULL;
            list->prev=p;
            list=p;
		}
	}
	void inserte()
	{
		int temp;
		cout<<"Enter data:\t";
		cin>>temp;
		p=(struct node*)malloc(sizeof(node));
		p->data=temp;
		p->next=NULL;
		if(list==NULL)
		{
            cout<<"Linked list does not exist.\nFirst node has been created\n";
            p->prev=NULL;
			list=p;
		}		
		else
		{
			q=list;
			while(q->next!=NULL)
			{
				q=q->next;	
			}
			q->next=p;
			p->prev=q;		
		}
	}
	void insertbe()
	{
		int temp;
		cout<<"Enter data to be inserted:\t";
		cin>>temp;
		p=(struct node*)malloc(sizeof(node));
		p->data=temp;
		cout<<"Enter element before which you want to insert "<<temp<<" :\t";
		cin>>value;
		q=list;
        if(list==NULL)//linked list does not exist
        {
            cout<<"Linked list does not exist.\n";
        }
        else
        {
            while (q->data != value && q != NULL)
            {
                r = q;
                q = q->next;
            }
            if (q == NULL)
            {
                cout << value << " does not exist.\n";
            }
            else if (q->data == value)
            {
                if (list->data == value)
                {
                    p->next = list;
                    p->prev = NULL;
                    list->prev = p;
                    list = p;
                }
                else
                {
                    r->next = p;
                    p->prev = r;
                    p->next = q;
                    q->prev = p;
                }
            }
        }
	}
	void insertae() {
        int temp;
        cout << "Enter data to be inserted:\t";
        cin >> temp;
        p = (struct node *) malloc(sizeof(node));
        p->data = temp;
        cout << "Enter element after which you want to insert " << temp << " :\t";
        cin >> value;
        q = list;
        if (list == NULL)//linked list does not exist
        {
            cout << "Linked list does not exist.\n";
        }
        else
        {
            while (q->data != value && q != NULL)//finding element
            {
                q = q->next;
            }
            r = q->next;
            if (q == NULL)//element not found
            {
                cout << value << " does not exist.\n";
            }
            else if (q->data == value)//element found
            {
                if (q->next == NULL)//element found in last node
                {
                    q->next = p;
                    p->prev = q;
                    p->next = NULL;
                }
                else
                {
                    q->next = p;
                    p->prev = q;
                    p->next = r;
                    r->prev = p;
                }
            }
        }
    }
	void deleteb()
	{
		if(list==NULL)
		{
			cout<<"Linked List is empty.\n";
		}
		else
		{
			q=list;
			if(list->next==NULL)
            {
                cout << q->data << " is deleted.\n";
                free(q);
                list=NULL;
            }
			else
			{
                list = list->next;
                list->prev = NULL;
                cout << q->data << " is deleted.\n";
                free(q);
            }
		}
	}
	void deletee()
	{
		if(list==NULL)
		{
			cout<<"Linked List is empty.\n";
		}
		else
		{
			q=list;
			while(q->next!=NULL)
			{
				r=q;				
				q=q->next;	
			}
            if(list->next==NULL)//element found in first node
            {
                cout << q->data << " is deleted.\n";
                free(q);
                list=NULL;
            }
            else
            {
			r->next=NULL;			
			cout<<q->data<<" is deleted.\n";
			free(q);
		    }
		}
	}
	void deletes()
	{
		if(list==NULL)
		{
			cout<<"Linked List is empty.\n";
		}
		else
		{
			cout<<"Enter element to be deleted:\n";
			cin>>value;
			q=list;
			while(q->data!=value && q->next!=NULL)
			{
				r=q;
				q=q->next;
			}
    		if(q->data==value)
			{
				if(list->data==value)
				{
                    if(list->next==NULL)
                    {
                        cout << q->data << " is deleted.\n";
                        free(q);
                        list=NULL;
                    }
                    else
                    {
                        cout << q->data << " is deleted.\n";
                        list=q->next;
                        list->prev=NULL;
                        free(q);
                    }
				}
				else if(q->next==NULL)
				{
					r->next=NULL;
					cout<<q->data<<" is deleted.\n";
					free(q);
				}
				else
				{
					r->next=q->next;
					s=r->next;
					s->prev=r;
					cout<<q->data<<" is deleted.\n";
					free(q);
				}		
			}
            else
            {
                 cout<<"Data not found.\n";
            }
		}
	}
	void count()
	{
        q = list;
        if (list == NULL)
        {
            cout << "Linked list is empty.\n";
        }
        else
        {
            int counter = 0;
            while (q != NULL)
            {
                counter++;
                q = q->next;
            }
            cout << "Number of nodes in linked list: " << counter << "\n";
        }
    }
	void reverse()
	{
        q=list;
        r=q->next;
        if(list==NULL)
        {
            cout<<"Linked list is empty.\n";
        }
        else if(list->next==NULL)
        {
            cout<<"Single element can not be reversed.\n";
        }
        else
        {
            while (r != NULL)
            {
                p = r->prev;
                s = r->next;
                r->next = r->prev;
                r->prev = s;
                r = s;
            }
            list->prev = list->next;
            list->next = NULL;
            list = p->prev;
        }
	}
	void sort()
    {
	    int temp;
	    q=list;
        if(list==NULL)
        {
            cout<<"Linked list is empty.\n";
        }
        else
        {
            while (q != NULL)
            {
                r = q->next;
                while (r != NULL)
                {
                    if (q->data > r->data)
                    {
                        temp = q->data;
                        q->data = r->data;
                        r->data = temp;
                    }
                    r = r->next;
                }
                q = q->next;
            }
            cout << "Sorted ";
            show_data();
        }
    }
	void show_data()
	{
		q=list;
		if(list==NULL)
		{
			cout<<"Linked List is empty.\n";
		}
		else
		{
			cout<<"Linked list:\n";
			while(q!=NULL)
			{
				cout<<q->data<<"--->";
				q=q->next;
			}
			cout<<"\n";
		}
	}
};
int main()
{
	dllist obj1;
	obj1.get_data();
}
