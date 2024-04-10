#include <iostream>
using namespace std;
void citire_matrice(int **matrix,int l, int c)
{
    for(int i=0; i<l; i++)
    {
        for(int j=0; j<c; j++)
        {
            cout<<"Matrix["<<i<<"]"<<"["<<j<<"]=";
            cin>>matrix[i][j];
        }
    }
}
void afisare_matrice(int **matrix, int l, int c)
{
    for(int i=0; i<l; i++)
    {
        for(int j=0; j<c; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int l = 0;
    int c = 0;
    cout << "Coloane:";
    cin >> c;
    cout << "Linii";
    cin >> l;
    int **p=new int*[l];
    for(int i=0; i<l; i++)
    {
        p[i]=new int [c];
    }
    citire_matrice(p,l,c);
    afisare_matrice(p,l,c);
    for(int i=0; i<l; i++)
    {
        delete [] p[i];
    }
    delete [] p;
    return 0;
}