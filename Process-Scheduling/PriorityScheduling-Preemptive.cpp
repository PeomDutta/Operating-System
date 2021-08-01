#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, smallest;

    int at[10],
    ct[10],
    temp[10],
    priority[10],
    finish_time;

    double wait_time = 0,
    turnaround_time = 0,
    total_wait_time = 0,
    total_turnaround_time = 0;

    float average_waiting_time, average_turnaround_time;

    cout<<"Enter the number of process: ";
    cin>>n;
    cout<<endl;

    printf("Enter the CPU times: ");
    for (int i = 0; i < n; i++)
    {
        cin>>ct[i];
        temp[i]= ct[i];
    }
    cout<<endl;

    printf("Enter the arrival times: ");
    for (int i = 0; i < n; i++)
    {
        cin>>at[i];
    }
    cout<<endl;

    printf("enter the PRIORITY of the processes: ");
    for (int i = 0; i < n; i++)
    {
        cin>>priority[i];
    }
    cout<<endl;

    int time = 0, count=0, minimum = INT_MAX;
    while(count!=n)
    {

        for(int i = 0; i < n; i++)
        {
            if(at[i] <= time && priority[i] < minimum && ct[i] > 0)
            {
                minimum = priority[i];
                smallest = i;
            }
        }
        ct[smallest]--;
        minimum = ct[smallest];

        if (minimum == 0)
        {
            minimum = INT_MAX;
        }

        if(ct[smallest] == 0)
        {
            count++;
            finish_time = time + 1;
            wait_time =  finish_time - at[smallest] - temp[smallest];
            total_wait_time+= wait_time;
            turnaround_time =  finish_time - at[smallest];
            total_turnaround_time+=turnaround_time;
            printf("\nProcess %d: Waiting time: %d Turnaround time: %d\n", smallest+1,finish_time - at[smallest] - temp[smallest],finish_time - at[smallest]);


        }
        time++;

    }

    average_waiting_time = total_wait_time / n;
    average_turnaround_time = total_turnaround_time / n;

    cout<<endl;
    cout<<"Average Waiting Time: "<<average_waiting_time<<endl;
    cout<<"Average Turnaround Time: "<<average_turnaround_time<<endl;

    return 0;
}

