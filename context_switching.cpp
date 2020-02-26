#include <iostream>
#include <csignal>
#include<bits/stdc++.h>
using namespace std;
int pid[5];
int i=-1;
void start_process(int signum){
  int p;
  cout<<"Enter the process you want to start"<<endl;
  cin>>p;
  if(i!=4){
    pid[++i]=p;
  }
}
void switch_process(int signum){
  int q;
  if(i<0){
    cout<<"No process running"<<endl;
  }
  else{
  cout<<"Currently Running Process:"<<pid[i]<<endl;
  cout<<"Enter the process you want to go"<<endl;
  cin>>q;
  if(q<=4){
    cout<<"Switched Process is:"<<pid[q]<<endl;
    i=q;
  }
}
}
void stop( int signum){
  cout<<"Whole process stopped"<<endl;
  exit(signum);
}
int main(){
  signal(SIGINT,start_process);
  signal(SIGQUIT,switch_process);
  signal(SIGSTOP,stop);
  while(1){
      cout<<"Enter Ctrl + C to start a new process"<<endl;
      cout<<"Enter Ctrl + \\ to start a new process"<<endl;
      cout<<"Enter Ctrl + Z to start a new process"<<endl;
  }
}
