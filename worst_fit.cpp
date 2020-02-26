#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void worstFit(int blocks[],int m,int processes[],int n){
	int allocation[n],blocks_alloc[m];
	memset(allocation,-1,sizeof(allocation));
	memset(blocks_alloc,-1,sizeof(blocks_alloc));
	for(int i=0;i<n;i++){
		int worst_index=-1;
		for(int j=0;j<m;j++){
			if(blocks[j]>=processes[i] && blocks_alloc[j]==-1){
				if(worst_index==-1)
					worst_index=j;
				if(blocks[worst_index]<blocks[j])
					worst_index=j;
			}
		}
		if(worst_index!=-1){
			allocation[i]=worst_index;
			blocks_alloc[worst_index]=i;
		}
	}
	 cout << "\nProcess No.\tProcess Size\tBlock no.\n";
   	 for (int i = 0; i < n; i++) {
       		 cout << " " << i+1 << "\t\t";
         	cout << processes[i] << "\t\t";
       		 if (allocation[i] != -1)
           		 cout << allocation[i] + 1;
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
	worstFit(blocks,m,processes,n);
	return 0;
}
