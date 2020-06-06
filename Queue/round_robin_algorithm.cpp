#include<iostream>
using namespace std;
class roundrobin
{
public:
    int time_table[10][50],p_size,time,rear,front,q[50],finc,process;
    float tataavg=0,wtavg=0;
    roundrobin()
    {
        rear=-1;
        front=-1;
        finc=0;
        tataavg=0;
        wtavg=0;
    }
    void get_data()
    {
        cout<<"Enter number of processes: ";
        cin>>p_size;
        cout<<"Enter arrival time for "<<p_size<<" processes:\n";
        for(int i=0;i<p_size;i++)
        {
            time_table[0][i]=i;
            cin>>time_table[1][i];
        }
        cout<<"Enter burst time for "<<p_size<<" processes:\n";
        for(int i=0;i<p_size;i++)
        {
            cin>>time_table[2][i];
        }
        cout<<"Enter time quantum: ";
        cin>>time;
        sort();
    }
    void sort()
    {
        for(int i=0;i<p_size;i++)
        {
            for (int j = i+1; j < p_size; j++)
            {
                if (time_table[1][i]>time_table[1][j])
                {
                    for(int k=0;k<3;k++)
                    {
                        int temp=time_table[k][i];
                        time_table[k][i]=time_table[k][j];
                        time_table[k][j]=temp;
                    }
                }
            }
        }
    }
    void waitingtime()
    {
        int at[p_size];
        for(int i=0;i<p_size;i++)
        {
            time_table[6][i]=time_table[2][i];
            at[i]=time_table[1][i];
        }
        int counter=0;
        while(1)
        {
            bool flag=true;
            for(int i=0;i<p_size;i++)
            {
                if(at[i]>counter)
                {
                    if(i==p_size-1)
                    {
                        i=0;
                        counter++;
                    }
                    else
                    {
                        continue;
                    }
                    cout<<"\nIDLE:"<<counter<<endl;
                }
                else if(at[i]<=counter)
                {
                    if(time_table[6][i]>0)
                    {
                        flag=false;
                        if(time_table[6][i]>time)
                        {
                            enqueue(time_table[0][i]);
                            processq(counter);
                            counter+=time;
                            time_table[6][i]-=time;
                            dequeue();
                        }
                        else
                        {
                            enqueue(time_table[0][i]);
                            processq(counter);
                            counter+=time_table[6][i];
                            time_table[4][i]=counter-time_table[2][i];
                            time_table[6][i]=0;
                            dequeue();
                        }
                        if(at[i+1]>counter)
                        {
                            i--;
                        }
                    }
                }
            }
            if(flag)
                break;
        }
    }
    void turnaroundtime()
    {
        for(int i=0;i<p_size;i++)
        {
            time_table[3][i]=time_table[2][i]+time_table[4][i];
            time_table[5][i]=time_table[3][i]-time_table[1][i];
            time_table[4][i]=time_table[5][i]-time_table[2][i];
        }
    }
    void average()
    {
        for(int i=0;i<p_size;i++)
        {
            tataavg+=time_table[5][i];
            wtavg+=time_table[4][i];
        }
        tataavg/=p_size;
        wtavg/=p_size;
    }
    void enqueue(int i)
    {
        i++;
        int pro=i;
        int rold=rear;
        rear=(rear+1)%p_size;
        if(finc==0) {
            front=0;
            finc++;
        }
        q[rear]=pro;
    }
    void dequeue()
    {
        if(front==rear)
        {
            front=-1;
            rear=-1;
            finc=0;
        }
        else
        {
            front=(front+1)%p_size;
        }
    }
    void show_data()
    {
        for(int i=0;i<p_size;i++)
        {
            for (int j = i+1; j < p_size; j++)
            {
                if (time_table[0][i]>time_table[0][j])
                {
                    for(int k=0;k<6;k++)
                    {
                        int temp=time_table[k][i];
                        time_table[k][i]=time_table[k][j];
                        time_table[k][j]=temp;
                    }
                }
            }
        }
        cout<<"\nProcess ID\tArrival Time\tBurst Time\tCompletion Time\t\tWaiting Time\tTurnaround Time\n";
        for(int i=0;i<p_size;i++)
        {
            cout<<"P"<<time_table[0][i]<<"\t\t"<<time_table[1][i]<<"\t\t"<<time_table[2][i]<<"\t\t"<<time_table[3][i]<<"\t\t\t"<<time_table[4][i]<<"\t\t"<<time_table[5][i]<<"\n";
        }
        cout<<"Average Waiting Time:\t\t"<<wtavg<<"\n";
        cout<<"Average Turnaround Time:\t"<<tataavg<<"\n";
    }
    void processq(int c)
    {
        cout<<"\nProcess: P"<<q[rear]-1<<" executed at:"<<c;
    }
};
int main()
{
    roundrobin obj1;
    obj1.get_data();
    obj1.waitingtime();
    obj1.turnaroundtime();
    obj1.average();
    obj1.show_data();
}
/*time_table
Process ID(0,i)
Arrival Time(1,i)
Burst Time(2,i)
completion Time(3,i)
Waiting Time(4,i)
 turnaround(5,i)
Remaining Burst Time(6,i)*/