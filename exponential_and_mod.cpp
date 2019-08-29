#include<bits/stdc++.h>
using namespace std;

//a^b mod m
stack<bool> help; //stores the binary of b holding the msb in top :D

// array niyeo kora jabe kaj . sekhetre binary length pathabo and length-1 thk 0 prjnto traverse krbo.
void decimal_to_binary_converter(int n)
{
    if(n==0)
    {
        help.push(0);
    }
    while(n!=0)
    {
        help.push(n%2);
        n=n/2;
    }

}
int main()
{
    int a,b,m; //m emn hoite hbe jate m*m int ba unsigned ba long long cross na kore,
               //korle maybe result*result,result*result*a korar somoy WA ashbe
               // tokhon ki korte hbe i dont know.
    printf("A program for calculating a^b MOD m:\n");
    printf("Enter a,b,m: ");
    scanf("%d%d%d",&a,&b,&m);

    decimal_to_binary_converter(b);
    int result = 1;

    while(!help.empty())
    {
        if(help.top()==0){
            result = (result*result) % m;
        }
        else
        {
            result = ((result*result)*a) %m;
        }
        help.pop();
    }

    printf("a^b MOD m: %d\n",result);
    return 0;
}
