 int f(int mid,int n,int m){
   long long  ans=1;
   for(int i=1;i<=n;i++){
      ans=ans*mid;
      if(ans>m) return 2;
   }
   if(ans==m) return 1;
   return 0;
 }
 int NthRoot(int n, int m) {
  // Write your code here.
  int low=1;
  int high=m;
  while(low<=high){
    int mid=(low+high)/2;
    if(f(mid,n,m)==1) return mid;
    if(f(mid,n,m)==2){
      high=mid-1;
    }
    else{
      low=mid+1;
    }
  }
  return -1;
}