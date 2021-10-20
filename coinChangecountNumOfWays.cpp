#include<bits/stdc++.h>
using namespace std;

int coinchange1(vector<int> coin,int sum,int n)
{
    int t[n+1][sum+1];

    for(int i=0;i<=n;i++)
        t[i][0]=1;

    for(int i=0;i<=sum;i++)
        t[0][i]=0;


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(coin[i-1]>j)
                t[i][j]=t[i-1][j];
            else
                t[i][j]=t[i-1][j] + t[i][j-coin[i-1]];
        }
    }

    return t[n][sum];
}
int main()
{
    vector<int>coin={1,2,3};
    int sum=5;
    int n=coin.size();

    cout<<coinchange1(coin,sum,n);
}
