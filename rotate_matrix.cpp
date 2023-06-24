#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>rotateMatrixByelement(vector<vector<int>>&matrix){
    int n=matrix.size();
    int m=matrix[0].size();
    int left=0,top=0;
    int right=m-1;
    int down=n-1;
    int prev=matrix[top+1][left];
    int dir=0;
    while(left<=right && top<=down){
        if(dir==0){
        for(int i=left;i<=right;i++){
            int temp=matrix[top][i];
            matrix[top][i]=prev;
            prev=temp;
        }
        top++;
        }
       else if(dir==1){
        for(int i=top;i<=down;i++){
            int temp=matrix[i][right];
            matrix[i][right]=prev;
            prev=temp;
        }
        right--;
       }
       else if(dir==2){
        for(int i=right;i>=left;i--){
            int temp=matrix[down][i];
            matrix[down][i]=prev;
            prev=temp;
        }
        down--;
       }
       else{
        for(int i=down;i>=top;i--){
            int temp=matrix[i][left];
            matrix[i][left]=prev;
            prev=temp;
        }
        left++;
       }
       dir++;
       if(dir==4){
          dir==0;
       }
    }
    return matrix;
}
int main(){
    vector<vector<int>>mat={{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>>temp=rotateMatrixByelement(mat);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<temp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;

}