#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


int main(){
    long long int t;
     long long int arr[100005];
   
    cin>>t;
    while(t--){
    long long int i,n;
    cin>>n;
    for( i=0; i<n; i++)
        cin>>arr[i];
	
    for( i=0; i<n; i++)
    {
		int t=floor(arr[i]-i/n);
		arr[i]=i+t*n;
		// cout<<arr[i]<<" ok"<<endl;
	}
	ll *it=arr;
	cout<<min_element(arr,arr+n)-it;
	
	
   
    }
    return 0;
}