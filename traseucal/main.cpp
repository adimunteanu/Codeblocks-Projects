#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("traseucal.in");
ofstream fout("traseucal.out");

int a[101][101], n, m, dl[8]={-2,-1,1,2,2,1,-1,-2}, dc[8]={1,2,2,1,-1,-2,-2,-1};
int ok = 0;


void afisare()
{
    if(ok == 0)
    {
        int i,j;
        for(i=1; i<=n; i++)
        {
            for(j = 1; j <= m; j++)
            {
                if(a[i][j] == -1)
                    fout<<0<<" ";
                else
                    fout<<a[i][j]<<" ";
            }
            fout<<"\n";
        }
    }

    ok = 1;
}



void backk(int x, int y, int pas)
{
    if(x == n && y == m)
        afisare();
    else
    {
        for(int i = 0; i < 8; i++)
        {
            if(!ok){
                int xx = x + dl[i];
                int yy = y + dc[i];
                if(xx <= n + 1 and xx >= 0 and yy <= m + 1 and yy >= 0)
                {
                    if(a[xx][yy] == 0)
                    {
                        a[xx][yy] = pas;
                        backk(xx, yy, pas+1);
                        a[xx][yy] = 0;
                    }
                }
            }
        }
    }
}
int main()
{
    fin>>n>>m;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            fin >> a[i][j];
            if(a[i][j] == 1)
                a[i][j] = -1;
        }

    int i, j;

    i = 0;

    for(int j = 0;j <= m + 1; j++)
        a[i][j] = -1;
    j = 0;

    for(int i = 0; i <= n + 1; i++)
        a[i][j]= -1;
    i = n + 1;

    for(int j=0;j<=m+1;j++)
        a[i][j]=-1;
    j = m + 1;

    for(int i = 0; i <= n + 1; i++)
        a[i][j] = -1;

    a[1][1] = 1;

    backk(1, 1, 2);

    if(!ok)
    {
        int i,j;
        for(i=1; i<=n; i++)
        {
            for(j = 1; j <= m; j++)
            {
                fout << 0 << " ";
            }
            fout<<"\n";
        }
    }
    return 0;
}
