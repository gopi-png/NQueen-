#include <bits/stdc++.h>
using namespace std;
int g;
class Solution{
public:
bool isSafe(int row,int col,int **board,int n)
{
    //check upper diagonal
    int duprow=row;
    int dupcol=col;

    while(row>=0 && col>=0)
    {
        if(board[row][col]==1)return false;
        row--;
        col--;
    }

    col=dupcol;
    row=duprow;
    while(col>=0)
    {
        if(board[row][col]==1)return false;
        col--;
    }

    row=duprow;
    col=dupcol;
    while(row<n && col>=0)
    {
        if(board[row][col]==1)return false;
        row++;
        col--;
    }
    return true;
}
public:
void solve(int col,int **board,int ***ans,int n)
{   
    if(col==n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans[g][i][j]=board[i][j];
            }
        }
       g++;
        return;
    }

    for(int row=0;row<n;row++)
    {
        if(isSafe(row,col,board,n))
        {
            board[row][col]=1;
            solve(col+1,board,ans,n);
            board[row][col]=0;
        }
    }
}


int ***solveNQueen(int n)
{
    int ***ans;
    int **board;
    board=new int*[n];
    ans=new int**[100];
    
for(int i=0;i<n;i++)
    {
           board[i]=new int[n];
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++){
       
            board[i][j]=0;
    }
    }

   for(int i=0;i<100;i++)
    {
            ans[i]=new int*[n];
            for(int j=0;j<n;j++)
    {
        ans[i][j] = new int[n];
        for(int k=0;k<n;k++){
            ans[i][j][k]=0;
    }
    }
    }   
    solve(0,board,ans,n);
    return ans;
}
};
int main()
{
    int n;
    int ***p;
    cout<<"Enter N Queen:";
    cin>>n;
    Solution *s=new Solution;
    p=s->solveNQueen(n);
    for(int i=0;i<g;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
        {
            cout<<p[i][j][k]<<" ";
        }
         cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}




