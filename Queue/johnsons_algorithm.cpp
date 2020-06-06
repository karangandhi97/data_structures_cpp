#include<iostream>
using namespace std;
class json
{
public:
    int jobsize,lrear,rrear,job[50][50],q[50],temp;
    bool flag;
    int counter;
    json()
    {
        lrear=-1;
    }
    void get_data()
    {
        cout<<"Enter number of jobs:\t";
        cin>>jobsize;
        for(int i=0;i<jobsize;i++)
        {
            job[0][i]=i+1;
        }
        cout<<"Enter Machine 1 burst time for "<<jobsize<<" jobs:\t";
        for(int i=0;i<jobsize;i++)
        {
            cin>>job[1][i];
        }
        cout<<"Enter Machine 2 burst time for "<<jobsize<<" jobs:\t";
        for(int i=0;i<jobsize;i++)
        {
            cin>>job[2][i];
        }
        rrear=jobsize;
        for(int i=0;i<jobsize;i++)
        {
            smallest();// main logic
        }
    }

    void smallest()
    {
        temp = job[1][0];//first value to compare
        int loc1, loc2;
        for (int i = 1; i < 3; i++)// 2D matrix. i=0-> Job number,i=1-> machine A, i=2-> machine B
        {
            for (int j = 0; j<jobsize; j++)//Compare 8 jobs
            {
                if (job[i][j] < temp)
                {
                    temp = job[i][j];
                    loc1 = i;
                    loc2 = j;
                }
            }
        }
        job[1][loc2]=1000;
        job[2][loc2]=1000;
        if(loc1==1)//if jobs are for machine A, enqueue from left
        {
            lenqueue(loc2+1);
        }
        if(loc1==2)//if jobs are for machine b, enqueue from right
        {
            renqueue(loc2+1);
        }
    }

    void lenqueue(int temp)//left enqueue for doubly queue
    {
        lrear++;
        q[lrear]=temp;
    }
    void renqueue(int temp)// right enqueue for doubly queue
    {
        rrear--;
        q[rrear]=temp;
    }
    void show_data()
    {
        cout<<"Job execution order:\t";
        for(int i=0;i<jobsize;i++)
        {
            cout<<q[i]<<"\t";
        }
        cout<<endl;
    }
};
int main()
{
    json obj1;
    obj1.get_data();
	obj1.show_data();
}
