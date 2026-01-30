#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
//recursion
int solution(int i,int j,int m,int n){
    if(i==m-1&&j==n-1){
        return 1;
    }
    if(i>=m||j>=n){
        return 0;
    }
    return solution(i,j+1,m,n)+solution(i+1,j,m,n);
}
int solutiondp(int i,int j,int m, int n,vector<vector<int>>&dp){
if(i==m-1&&j==n-1){
        return 1;
    }
    if(i>=m||j>=n){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    return dp[i][j]=solutiondp(i,j+1,m,n,dp)+solutiondp(i+1,j,m,n,dp);
}
int solutionbytabulation(int m,int n,vector<vector<int>>&dp){
    for(int i=0;i<m;i++){
        dp[i][n-1]=1;
    }
    for(int j=0;j<n;j++){
        dp[m-1][j]=1;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            dp[i][j]=dp[i+1][j]+dp[i][j+1];
        }
    }
    return dp[0][0];
}
int main(){
    int n=0,m=0;
    cout<<"enter values of m and n"<<endl;
    cin>>m>>n;
 cout<<solution(0,0,m,n)<<endl;
 vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
 solutiondp(0,0,m,n,dp);
 cout<<dp[0][0]<<endl;
 cout<<solutionbytabulation(m,n,dp);
return 0;
}