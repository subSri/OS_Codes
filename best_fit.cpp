#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void bestFit(int blocks[],int m,int processes[],int n){
	int proc_allocation[n],blocks_alloc[m];
	memset(proc_allocation,-1,sizeof(proc_allocation));
	memset(blocks_alloc,-1,sizeof(blocks_alloc));
	for(int i=0;i<n;i++){
		int best_index=-1;
		for(int j=0;j<m;j++){
			if(blocks[j]>=processes[i] && blocks_alloc[j]==-1){
				if(best_index==-1)
					best_index=j;
				if(blocks[best_index]>blocks[j])
					best_index=j;
			}
		}
		if(best_index!=-1){
			proc_allocation[i]=best_index;
			blocks_alloc[best_index]=i;
		}
	}
	 cout << "\nProcess No.\tProcess Size\tBlock no.\n";
   	 for (int i = 0; i < n; i++) {
       		 cout << " " << i+1 << "\t\t";
         	cout << processes[i] << "\t\t";
       		 if (proc_allocation[i] != -1)
           		 cout << proc_allocation[i] + 1;
       		 else
           		 cout << "Not Allocated";
       		 cout << endl;
   		 }

}
int main(){
	int blocks[]={100,500,200,300,600};
	int processes[]={212,50,417,112,426};
	int m=sizeof(blocks)/sizeof(blocks[0]);
	int n=sizeof(processes)/sizeof(processes[0]);
	bestFit(blocks,m,processes,n);
	return 0;
}
