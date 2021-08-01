#include<bits/stdc++.h>
using namespace std;

struct priority
{
    int burst_time;
    int arrival_time;
    int priority;
    int pid;
    int tat;
    int wt;
    int fin;
    bool completed;
};

///-----------calculating the finish time of each process-----------------///

void finish_time(struct priority p[],int n)
{
    int finish_t=0;
    int flag = 0;
    int temp_pid, temp_arival, temp_priority, temp_burst;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (p[i].priority > p[j].priority)
            {
                temp_priority = p[i].priority;
                p[i].priority = p[j].priority;
                p[j].priority = temp_priority;

                temp_arival = p[i].arrival_time;
                p[i].arrival_time = p[j].arrival_time;
                p[j].arrival_time = temp_arival;

                temp_burst = p[i].burst_time;
                p[i].burst_time = p[j].burst_time;
                p[j].burst_time = temp_burst;

                temp_pid = p[i].pid;
                p[i].pid = p[j].pid;
                p[j].pid = temp_pid;
            }
        }
    }

    int smallest_arrival=p[0].arrival_time;

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (p[i].arrival_time > p[j].arrival_time)
            {
                smallest_arrival = p[j].arrival_time;
            }
        }
    }


    for (int i = 0; i < n; i++)
    {
        if ((p[i].arrival_time == smallest_arrival)&&(p[i].completed==false))
        {
            finish_t += p[i].burst_time;
            p[i].completed = true;
            p[i].fin = finish_t;
        }
    }

///----------------main execution-----------------///

    do
    {
        for (int i = 0; i < n; i++)
        {
            if ((p[i].arrival_time < finish_t)&&(p[i].completed!=true))
            {
                finish_t += p[i].burst_time;
                p[i].completed = true;
                p[i].fin = finish_t;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (p[i].completed == true)
            {
                flag = 1;
            }
            else
            {
                flag = 0;
            }
        }
    }
    while (flag != 1);

}


///--------------------print the table-----------------------///

void print_table(struct priority p[],int n,float avg_wt,float avg_tat)
{
    for (int j = 0; j < n; j++)
    {
        cout<<"Process "<<j+1<<":"<<"\t"<<"Waiting Time: "<<p[j].wt<<"  Turnaround Time: "<<p[j].tat<<endl;
    }

    cout<<endl;
    cout<<"Average Waiting Time: "<<avg_wt<<endl;
    cout<<"Average Turnaround Time: "<<avg_tat<<endl;

}

///---------calculating the average turnaround time and average waitong time----------///

void avg_t(struct priority p[],int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i].tat = p[i].fin - p[i].arrival_time;
    }

    for (int i = 0; i < n; i++)
    {
        p[i].wt = p[i].tat - p[i].burst_time;
    }


    float avg_tat = 0;
    for (int i = 0; i < n; i++)
    {
        avg_tat = p[i].tat + avg_tat;
    }
    avg_tat = avg_tat / n;


    float avg_wt = 0;
    for (int i = 0; i < n; i++)
    {
        avg_wt = p[i].wt + avg_wt;
    }
    avg_wt = avg_wt / n;


    print_table(p,n, avg_wt, avg_tat);
}


///-----------------------main function------------------///

int main()
{
    int n;
    struct priority p[100];
    cout<<"Enter the number of process: ";
    cin>>n;
    cout<<endl;

    printf("Enter the CPU times: ");
    for (int i = 0; i < n; i++)
    {
        p[i].pid = i;
        p[i].completed = false;
        cin>>p[i].burst_time;
    }
    cout<<endl;

    printf("Enter the arrival times: ");
    for (int i = 0; i < n; i++)
    {
        p[i].pid = i;
        p[i].completed = false;
        cin>>p[i].arrival_time;
    }
    cout<<endl;

    printf("enter the PRIORITY of the processes:");
    for (int i = 0; i < n; i++)
    {
        cin>>p[i].priority;
    }
    cout<<endl;

    finish_time(p,n);
    avg_t(p,n);
}

