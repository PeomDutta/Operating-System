#include<bits/stdc++.h>
using namespace std;

int main()
{
      int process_num, temp=0, min, index;

      float average_tat=0,
      average_wt=0,
      total_tat=0,
      total_wt=0;

      cout<<"Enter number of process: ";
      cin>>process_num;
      cout<<endl;

      int arrival_time[process_num],
      cpu_time[process_num],
      completion_time[process_num],
      turn_around_time[process_num],
      waiting_time[process_num];


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




      ///----------sort--------------///

      for(int i=0; i<process_num; i++)
      {
         for(int j=i+1; j<process_num; j++)
          {
                if(cpu_time[i]>cpu_time[j])
                {
                      sort(arrival_time+i, arrival_time+j);
                      sort(cpu_time+i, cpu_time+j);
                }
          }
      }



      ///--------logic implementation--------///

      min=arrival_time[0];
      for(int i=0; i<process_num; i++)
      {
            if(min>arrival_time[i])
            {
                  min=arrival_time[i];
                  index=i;
            }
      }
      temp=min;
      completion_time[index]=temp+cpu_time[index];
      temp=completion_time[index];

      for(int i=0;i<process_num;i++)
      {
            if(arrival_time[i]!=min)
            {
                  completion_time[i]=cpu_time[i]+temp;
                  temp=completion_time[i];
            }
      }
      for(int i=0;i<process_num;i++)
      {

            turn_around_time[i]=completion_time[i]-arrival_time[i];
            total_tat+=turn_around_time[i];
            waiting_time[i]=turn_around_time[i]-cpu_time[i];
            total_wt+=waiting_time[i];
      }

      average_tat=total_tat/process_num;
      average_wt=total_wt/process_num;



    ///--------------Output Print------------///

    for(int i=0;i<process_num;i++)
    {
    cout<<"Process "<< i+1 << ": Waiting Time: "<<waiting_time[i] << " " <<"Turnaround Time: " <<turn_around_time[i]<<endl;
    }
    cout<<endl;

    cout<<"Average Turnaround Time: "<<average_tat<<endl;
    cout<<"Average Waiting Time: "<<average_wt<<endl;


    return 0;
}

