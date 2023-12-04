#include <iostream.h>
#include <fstream>
struct muchie
{
    int x,y,c;
} v[20];

int a1,a2,m,n,i,j,cost,k,l,nr,t[20];
muchie aux;
void main()
{
    clrscr();
    cout<<"Num˘ar de vˆarfuri ";
    cin>>n;
    cout<<"Num˘ar de muchii ";
    cin>>m;
    for(i=1;i<=m;i++)
    {
        cout<<"Extremit˘at¸i muchie "<<i<<":";
        cin>>v[i].x>>v[i].y;
        cout<<"Cost muchie ";
        cin>>v[i].c;
    }
    cout<<"Arborele de cost minim este "<<endl;
    for(i=1;i<=m-1;i++)
        for(j=i+1;j<=m;j++)
            if(v[i].c>v[j].c)
            {
                aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }
    for(i=1;i<=n;i++)
        t[i]=i;
    cost=0;
    i=1;
    nr=0;
    while(nr<n-1)
    {
        if(t[v[i].x]!=t[v[i].y])
        {
            nr++;
            cost=cost+v[i].c;
            cout<<v[i].x<<" "<<v[i].y<<endl;
            k=t[v[i].x];
            l=t[v[i].y];
            for(j=1;j<=n;j++)
                if(t[j]==k) t[j]=l;
        } i++;
    }
    cout<<"Cost "<<cost;
    getch();
}
