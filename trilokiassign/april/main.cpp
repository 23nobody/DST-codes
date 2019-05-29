#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        unsigned long int l,r,g,k;
        cin >> l >> r >> g;
        unsigned long int c=0;
        unsigned long int i=0;
        k=1;
        int flag=0;
        if(g<=r)
        {
        for(i=l;i<=r;i=i+k)
        {


            if(__gcd(i,g)==g)
            {
                k=g;
                c++;

            }


        }
        }
        cout << c << endl;

    }
    return 0;
}
