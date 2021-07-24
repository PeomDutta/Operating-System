#include<bits/stdc++.h>
using namespace std;

int highest_size= 100;

int main()
{
    int index,process_num,end_time;

    float average_tat=0,
    average_wt=0,
    total_tat=0,
    total_wt=0;

    cout<<"Enter number of process: ";
    cin>>process_num;
    cout<<endl;

    int arrival_time[highest_size],
    cpu_time[highest_size],
    burst_time[highest_size],
    waiting_time[highest_size],
    turnaround_time[highest_size],
    completion_time[highest_size];


    cout<<"Enter the CPU times: ";
    for(int i=0;i<process_num;i++)
    {
        cin>>cpu_time[i];
    }
    cout<<endl;


    cout<<"Enter the arrival times: ";
    for(int i=0;i<process_num;i++)
    {
        cin>>arrival_time[i];
    }
    cout<<endl;



    ///--------logic implementation--------///

    for(int i=0; i<process_num; i++)
    {
        burst_time[i]=cpu_time[i];
    }

    cpu_time[highest_size-1]=INT_MAX;


    int time=0, count=0;
    while(count!=process_num)
    {
        index=highest_size-1;
        for(int i=0; i<process_num; i++)
        {
            if(arrival_time[i]<=time && cpu_time[i]<cpu_time[index] && cpu_time[i]>0 )
            {
                index=i;
            }
        }
        cpu_time[index]--;

        if(cpu_time[index]==0)
        {
            count++;
            end_time=time+1;
            completion_time[index] = end_time;
            turnaround_time[index] = completion_time[index] - arrival_time[index];
            waiting_time[index] = turnaround_time[index] - burst_time[index];
        }
        time++;
    }


    ///--------------Output Print------------///

    for(int i=0;i<process_num;i++)
    {
        cout<<"Process "<< i+1 << ": Waiting Time: "<<waiting_time[i] << " " <<"Turnaround Time: " <<turnaround_time[i]<<endl;
        total_wt+=waiting_time[i];
        total_tat+=turnaround_time[i];
    }
    cout<<endl;

    average_tat= total_tat/process_num;
    average_wt = total_wt/process_num;

    cout<<"Average Turnaround Time: "<<average_tat<<endl;
    cout<<"Average Waiting Time: "<<average_wt<<endl;

    return 0;
    
}
