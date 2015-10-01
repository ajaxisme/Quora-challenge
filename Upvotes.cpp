#include<iostream>

using namespace std;

#define calculate(n) n*(n-1)/2

int count_inc_dec(int data[], int n, int start, int end){
	int i=start+1;
	int inc=1, dec=1;
	int total_dec = 0, total_inc = 0;
	while(i<end){
		if(data[i] == 1){
			total_dec += calculate(dec);
			dec = 1;
			inc++;
		}
		else if(data[i] == -1){
			total_inc += calculate(inc);
			inc = 1;
			dec++;
		}
		else{
			inc++;
			dec++;
		}
		i++;
	}
	total_inc += calculate(inc);
	total_dec += calculate(dec);
	return (total_inc - total_dec);
}

int main(){
	int n, k;
	int upvotes[100000];
	int data[100000] = {0};
	cin>>n>>k;
	int i;
	for(i=0;i<n;i++)
		cin>>upvotes[i];
	for(i=1;i<n;i++){
		if(upvotes[i]>upvotes[i-1])
			data[i] = 1;
		else if(upvotes[i] == upvotes[i-1])
			data[i] = 0;
		else
			data[i] = -1;
	}

	for(i=0;i<n-k+1;i++)
		cout<<count_inc_dec(data, n, i, i+k)<<endl;

	return 0;
}
