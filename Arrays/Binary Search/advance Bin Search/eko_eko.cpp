
//Company Tags    : Amazon, Facebook, Google,Adobe
//Problem Link: https://www.spoj.com/problems/EKO/


#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>

#define int             long long int
#define pb              push_back
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mod             1000000007
#define w(x)            int x; cin>>x; while(x--)
using namespace std;
 
 int mid_wood(int arr[],int m,int mid,int n)
 {int wood=0;
 cout<<"Inside fn";
 	for(int i=0;i<n;i++)
 	{
 		if(arr[i]-mid>0)
 		{
 			wood=wood+arr[i]-mid;
 		}
 	}
 	return wood;
 }
 
int32_t main() {
 
    w(T)
    {
        int n,m,ans;
        cin>>n>>m;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        
        sort(arr,arr+n);
       int low=0,high=arr[n-1];
       while(low<=high)
       {cout<<"inside while";
       	int mid=(low+high)/2;6
       	if(m<=mid_wood(arr,m,mid,n))
       	{
       		ans=mid;low=mid+1;
       	}
       	else high=mid-1;
       }
		cout<<ans<<endl;
		        
    }
 
 
    return 0;
}
 
 
 
