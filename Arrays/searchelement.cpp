#include<iostream>
using namespace std;
int main()
{
  int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
{
  cin>>arr[i];
}

int target;
cin>>target;
for(int i=0;i<n;i++)
{
  if(target==arr[i])
  {
    cout<<"Eement found at index"<<i;
    return 0;
  }
}
cout<<"Elemnt not in the array";
}
