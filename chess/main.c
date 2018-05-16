#include <stdio.h>
#include <stdlib.h>

FILE *save;
int possiblemovesv[30]; //X
int possiblemovesh[30]; //Y
char b[10][10];

//x,y king moving to //w,q king moving from //a board
int checkMove(int x,int y,int w,int q,char a[10][10])
{
    int c;
    for(c=0; c<30; c++)
    {
        possiblemovesh[c]=0;
        possiblemovesv[c]=0;
    }

    int h=0,m,n,flag;
    if(a[x][y]=='n')
    {
        if(a[x+1][y+2]=='.'||a[x+1][y+2]=='-'||a[x+1][y+2]=='P'||a[x+1][y+2]=='R'||a[x+1][y+2]=='B'||a[x+1][y+2]=='N'||a[x+1][y+2]=='Q')
        {
            if(x+1>=1&&x+1<=8&&y+2>=1&&y+2<=8)
            {
                possiblemovesv[h]=x+1;
                possiblemovesh[h]=y+2;
                h++;
            }
        }
        if(a[x-1][y+2]=='.'||a[x-1][y+2]=='-'||a[x-1][y+2]=='P'||a[x-1][y+2]=='R'||a[x-1][y+2]=='B'||a[x-1][y+2]=='N'||a[x-1][y+2]=='Q')
        {
            if(x-1>=1&&x-1<=8&&y+2>=1&&y+2<=8)
            {
                possiblemovesv[h]=x-1;
                possiblemovesh[h]=y+2;
                h++;
            }
        }
        if(a[x+1][y-2]=='.'||a[x+1][y-2]=='-'||a[x+1][y-2]=='P'||a[x+1][y-2]=='R'||a[x+1][y-2]=='B'||a[x+1][y-2]=='N'||a[x+1][y-2]=='Q')
        {
            if(x+1>=1&&x+1<=8&&y-2>=1&&y-2<=8)
            {
                possiblemovesv[h]=x+1;
                possiblemovesh[h]=y-2;
                h++;
            }
        }
        if(a[x-1][y-2]=='.'||a[x-1][y-2]=='-'||a[x-1][y-2]=='P'||a[x-1][y-2]=='R'||a[x-1][y-2]=='B'||a[x-1][y-2]=='N'||a[x-1][y-2]=='Q')
        {
            if(x-1>=1&&x-1<=8&&y-2>=1&&y-2<=8)
            {
                possiblemovesv[h]=x-1;
                possiblemovesh[h]=y-2;
                h++;
            }
        }
        if(a[x+2][y+1]=='.'||a[x+2][y+1]=='-'||a[x+2][y+1]=='P'||a[x+2][y+1]=='R'||a[x+2][y+1]=='B'||a[x+2][y+1]=='N'||a[x+2][y+1]=='Q')
        {
            if(x+2>=1&&x+2<=8&&y+1>=1&&y+1<=8)
            {
                possiblemovesv[h]=x+2;
                possiblemovesh[h]=y+1;
                h++;
            }
        }
        if(a[x+2][y-1]=='.'||a[x+2][y-1]=='-'||a[x+2][y-1]=='P'||a[x+2][y-1]=='R'||a[x+2][y-1]=='B'||a[x+2][y-1]=='N'||a[x+2][y-1]=='Q')
        {
            if(x+2>=1&&x+2<=8&&y-1>=1&&y-1<=8)
            {
                possiblemovesv[h]=x+2;
                possiblemovesh[h]=y-1;
                h++;
            }
        }
        if(a[x-2][y+1]=='.'||a[x-2][y+1]=='-'||a[x-2][y+1]=='P'||a[x-2][y+1]=='R'||a[x-2][y+1]=='B'||a[x-2][y+1]=='N'||a[x-2][y+1]=='Q')
        {
            if(x-2>=1&&x-2<=8&&y+1>=1&&y+1<=8)
            {
                possiblemovesv[h]=x-2;
                possiblemovesh[h]=y+1;
                h++;
            }
        }
        if(a[x-2][y-1]=='.'||a[x-2][y-1]=='-'||a[x-2][y-1]=='P'||a[x-2][y-1]=='R'||a[x-2][y-1]=='B'||a[x-2][y-1]=='N'||a[x-2][y-1]=='Q')
        {
            if(x-2>=1&&x-2<=8&&y-1>=1&&y-1<=8)
            {
                possiblemovesv[h]=x-2;
                possiblemovesh[h]=y-1;
                h++;
            }
        }

    }
    if(a[x][y]=='N')
    {
        if(a[x+1][y+2]=='.'||a[x+1][y+2]=='-'||a[x+1][y+2]=='p'||a[x+1][y+2]=='r'||a[x+1][y+2]=='b'||a[x+1][y+2]=='n'||a[x+1][y+2]=='q')
        {
            if(x+1>=1&&x+1<=8&&y+2>=1&&y+2<=8)
            {
                possiblemovesv[h]=x+1;
                possiblemovesh[h]=y+2;
                h++;
            }
        }
        if(a[x-1][y+2]=='.'||a[x-1][y+2]=='-'||a[x-1][y+2]=='p'||a[x-1][y+2]=='r'||a[x-1][y+2]=='b'||a[x-1][y+2]=='n'||a[x-1][y+2]=='q')
        {
            if(x-1>=1&&x-1<=8&&y+2>=1&&y+2<=8)
            {
                possiblemovesv[h]=x-1;
                possiblemovesh[h]=y+2;
                h++;
            }
        }
        if(a[x+1][y-2]=='.'||a[x+1][y-2]=='-'||a[x+1][y-2]=='p'||a[x+1][y-2]=='r'||a[x+1][y-2]=='b'||a[x+1][y-2]=='n'||a[x+1][y-2]=='q')
        {
            if(x+1>=1&&x+1<=8&&y-2>=1&&y-2<=8)
            {
                possiblemovesv[h]=x+1;
                possiblemovesh[h]=y-2;
                h++;
            }
        }
        if(a[x-1][y-2]=='.'||a[x-1][y-2]=='-'||a[x-1][y-2]=='p'||a[x-1][y-2]=='r'||a[x-1][y-2]=='b'||a[x-1][y-2]=='n'||a[x-1][y-2]=='q')
        {
            if(x-1>=1&&x-1<=8&&y-2>=1&&y-2<=8)
            {
                possiblemovesv[h]=x-1;
                possiblemovesh[h]=y-2;
                h++;
            }
        }
        if(a[x+2][y+1]=='.'||a[x+2][y+1]=='-'||a[x+2][y+1]=='p'||a[x+2][y+1]=='r'||a[x+2][y+1]=='b'||a[x+2][y+1]=='n'||a[x+2][y+1]=='q')
        {
            if(x+2>=1&&x+2<=8&&y+1>=1&&y+1<=8)
            {
                possiblemovesv[h]=x+2;
                possiblemovesh[h]=y+1;
                h++;
            }
        }
        if(a[x+2][y-1]=='.'||a[x+2][y-1]=='-'||a[x+2][y-1]=='p'||a[x+2][y-1]=='r'||a[x+2][y-1]=='b'||a[x+2][y-1]=='n'||a[x+2][y-1]=='q')
        {
            if(x+2>=1&&x+2<=8&&y-1>=1&&y-1<=8)
            {
                possiblemovesv[h]=x+2;
                possiblemovesh[h]=y-1;
                h++;
            }
        }
        if(a[x-2][y+1]=='.'||a[x-2][y+1]=='-'||a[x-2][y+1]=='p'||a[x-2][y+1]=='r'||a[x-2][y+1]=='b'||a[x-2][y+1]=='n'||a[x-2][y+1]=='q')
        {
            if(x-2>=1&&x-2<=8&&y+1>=1&&y+1<=8)
            {
                possiblemovesv[h]=x-2;
                possiblemovesh[h]=y+1;
                h++;
            }
        }
        if(a[x-2][y-1]=='.'||a[x-2][y-1]=='-'||a[x-2][y-1]=='p'||a[x-2][y-1]=='r'||a[x-2][y-1]=='b'||a[x-2][y-1]=='n'||a[x-2][y-1]=='q')
        {
            if(x-2>=1&&x-2<=8&&y-1>=1&&y-1<=8)
            {
                possiblemovesv[h]=x-2;
                possiblemovesh[h]=y-1;
                h++;
            }
        }
    }
    if(a[x][y]=='q')
    {
        m=x;
        n=y;
        flag =0;
        for(m=x; flag==0; m++)
        {

            if(a[m+1][n+1]=='.'||a[m+1][n+1]=='-')
            {
                if(m+1>=1&&m+1<=8&&n+1>=1&&n+1<=8)
                {
                    possiblemovesv[h]=m+1;
                    possiblemovesh[h]=n+1;
                    flag=0;
                    h++;
                    n++;
                }
            }
            else if(a[m+1][n+1]=='P'||a[m+1][n+1]=='R'||a[m+1][n+1]=='N'||a[m+1][n+1]=='B'||a[m+1][n+1]=='Q')
            {
                if(m+1>=1&&m+1<=8&&n+1>=1&&n+1<=8)
                {
                    possiblemovesv[h]=m+1;
                    possiblemovesh[h]=n+1;
                    flag=1;
                    h++;
                }
            }
            else
                flag=1;
        }
        flag=0;
        n=y;
        for(m=x; flag==0; m--)
        {
            if(a[m-1][n+1]=='.'||a[m-1][n+1]=='-')
            {
                if(m-1>=1&&m-1<=8&&n+1>=1&&n+1<=8)
                {
                    possiblemovesv[h]=m-1;
                    possiblemovesh[h]=n+1;
                    flag=0;
                    h++;
                    n++;
                }
            }
            else if(a[m-1][n+1]=='P'||a[m-1][n+1]=='R'||a[m-1][n+1]=='N'||a[m-1][n+1]=='B'||a[m-1][n+1]=='Q')
            {
                if(m-1>=1&&m-1<=8&&n+1>=1&&n+1<=8)
                {
                    possiblemovesv[h]=m-1;
                    possiblemovesh[h]=n+1;
                    flag=1;
                    h++;
                }
            }
            else
                flag=1;
        }
        flag=0;
        m=x;
        for(n=y; flag==0; n--)
        {
            if(a[m-1][n-1]=='.'||a[m-1][n-1]=='-')
            {
                if(m-1>=1&&m-1<=8&&n-1>=1&&n-1<=8)
                {
                    possiblemovesv[h]=m-1;
                    possiblemovesh[h]=n-1;
                    flag=0;
                    h++;
                    m--;
                }
            }
            else if(a[m-1][n-1]=='P'||a[m-1][n-1]=='R'||a[m-1][n-1]=='N'||a[m-1][n-1]=='B'||a[m-1][n-1]=='Q')
            {
                if(m-1>=1&&m-1<=8&&n-1>=1&&n-1<=8)
                {
                    possiblemovesv[h]=m-1;
                    possiblemovesh[h]=n-1;
                    flag=1;
                    h++;
                }
            }
            else
                flag=1;
        }
        flag=0;
        m=x;
        for(n=y; flag==0; n--)
        {

            if(a[m+1][n-1]=='.'||a[m+1][n-1]=='-')
            {
                if(m+1>=1&&m+1<=8&&n-1>=1&&n-1<=8)
                {
                    possiblemovesv[h]=m+1;
                    possiblemovesh[h]=n-1;
                    flag=0;
                    h++;
                    m++;
                }
            }
            else if(a[m+1][n-1]=='P'||a[m+1][n-1]=='R'||a[m+1][n-1]=='N'||a[m+1][n-1]=='B'||a[m+1][n-1]=='Q')
            {
                if(m+1>=1&&m+1<=8&&n-1>=1&&n-1<=8)
                {
                    possiblemovesv[h]=m+1;
                    possiblemovesh[h]=n-1;
                    flag=1;
                    h++;
                }
            }
            else
                flag=1;
        }
        m=x;
        n=y;
        flag=0;
        for(m=x; flag==0; m++)
        {
            n=y;
            if(a[m+1][n]=='.'||a[m+1][n]=='-')
            {
                if(m+1>=1&&m+1<=8)
                {
                    possiblemovesv[h]=m+1;
                    possiblemovesh[h]=n;
                    flag=0;
                    h++;
                }
            }
            else if(a[m+1][n]=='P'||a[m+1][n]=='R'||a[m+1][n]=='N'||a[m+1][n]=='B'||a[m+1][n]=='Q')
            {
                if(m+1>=1&&m+1<=8)
                {
                    possiblemovesv[h]=m+1;
                    possiblemovesh[h]=n;
                    flag=1;
                    h++;
                }
            }
            else
                flag=1;
        }
        flag=0;
        for(m=x; flag==0; m--)
        {
            n=y;
            if(a[m-1][n]=='.'||a[m-1][n]=='-')
            {
                if(m-1>=1&&m-1<=8)
                {
                    possiblemovesv[h]=m-1;
                    possiblemovesh[h]=n;
                    flag=0;
                    h++;
                }
            }
            else if(a[m-1][n]=='P'||a[m-1][n]=='R'||a[m-1][n]=='N'||a[m-1][n]=='B'||a[m-1][n]=='Q')
            {
                if(m-1>=1&&m-1<=8)
                {
                    possiblemovesv[h]=m-1;
                    possiblemovesh[h]=n;
                    flag=1;
                    h++;
                }
            }
            else
                flag=1;
        }
        flag=0;
        for(n=y; flag==0; n++)
        {
            m=x;
            if(a[m][n+1]=='.'||a[m][n+1]=='-')
            {
                if(n+1>=1&&n+1<=8)
                {
                    possiblemovesv[h]=m;
                    possiblemovesh[h]=n+1;
                    flag=0;
                    h++;
                }
            }
            else if(a[m][n+1]=='P'||a[m][n+1]=='R'||a[m][n+1]=='N'||a[m][n+1]=='B'||a[m][n+1]=='Q')
            {
                if(n+1>=1&&n+1<=8)
                {
                    possiblemovesv[h]=m;
                    possiblemovesh[h]=n+1;
                    flag=1;
                    h++;
                }
            }
            else
                flag=1;
        }
        flag=0;
        for(n=y; flag==0; n--)
        {
            m=x;
            if(a[m][n-1]=='.'||a[m][n-1]=='-')
            {
                if(n-1>=1&&n-1<=8)
                {
                    possiblemovesv[h]=m;
                    possiblemovesh[h]=n-1;
                    flag=0;
                    h++;
                }
            }
            else if(a[m][n-1]=='P'||a[m][n-1]=='R'||a[m][n-1]=='N'||a[m][n-1]=='B'||a[m][n-1]=='Q')
            {
                if(n-1>=1&&n-1<=8)
                {
                    possiblemovesv[h]=m;
                    possiblemovesh[h]=n-1;
                    flag=1;
                    h++;
                }
            }
            else
                flag=1;
        }

    }
    if(a[x][y]=='Q')
    {
        int m,n;
        m=x;
        n=y;
        int flag=0;
        for(m=x; flag==0; m++)
        {

            if(a[m+1][n+1]=='.'||a[m+1][n+1]=='-')
            {
                if(m+1>=1&&m+1<=8&&n+1>=1&&n+1<=8)
                {
                    possiblemovesv[h]=m+1;
                    possiblemovesh[h]=n+1;
                    flag=0;
                    h++;
                    n++;
                }
            }
            else if(a[m+1][n+1]=='p'||a[m+1][n+1]=='r'||a[m+1][n+1]=='n'||a[m+1][n+1]=='b'||a[m+1][n+1]=='q')
            {
                if(m+1>=1&&m+1<=8&&n+1>=1&&n+1<=8)
                {
                    possiblemovesv[h]=m+1;
                    possiblemovesh[h]=n+1;
                    flag=1;
                    h++;
                }
            }
            else
                flag=1;
        }
        flag=0;
        n=y;
        for(m=x; flag==0; m--)
        {
            if(a[m-1][n+1]=='.'||a[m-1][n+1]=='-')
            {
                if(m-1>=1&&m-1<=8&&n+1>=1&&n+1<=8)
                {
                    possiblemovesv[h]=m-1;
                    possiblemovesh[h]=n+1;
                    flag=0;
                    h++;
                    n++;
                }
            }
            else if(a[m-1][n+1]=='p'||a[m-1][n+1]=='r'||a[m-1][n+1]=='n'||a[m-1][n+1]=='b'||a[m-1][n+1]=='q')
            {
                if(m-1>=1&&m-1<=8&&n+1>=1&&n+1<=8)
                {
                    possiblemovesv[h]=m-1;
                    possiblemovesh[h]=n+1;
                    flag=1;
                    h++;
                }
            }
            else
                flag=1;
        }
        flag=0;
        m=x;
        for(n=y; flag==0; n--)
        {
            if(a[m-1][n-1]=='.'||a[m-1][n-1]=='-')
            {
                if(m-1>=1&&m-1<=8&&n-1>=1&&n-1<=8)
                {
                    possiblemovesv[h]=m-1;
                    possiblemovesh[h]=n-1;
                    flag=0;
                    h++;
                    m--;
                }
            }
            else if(a[m-1][n-1]=='p'||a[m-1][n-1]=='r'||a[m-1][n-1]=='n'||a[m-1][n-1]=='b'||a[m-1][n-1]=='q')
            {
                if(m-1>=1&&m-1<=8&&n-1>=1&&n-1<=8)
                {
                    possiblemovesv[h]=m-1;
                    possiblemovesh[h]=n-1;
                    flag=1;
                    h++;
                }
            }
            else
                flag=1;
        }
        flag=0;
        m=x;
        for(n=y; flag==0; n--)
        {

            if(a[m+1][n-1]=='.'||a[m+1][n-1]=='-')
            {
                if(m+1>=1&&m+1<=8&&n-1>=1&&n-1<=8)
                {
                    possiblemovesv[h]=m+1;
                    possiblemovesh[h]=n-1;
                    flag=0;
                    h++;
                    m++;
                }
            }
            else if(a[m+1][n-1]=='p'||a[m+1][n-1]=='r'||a[m+1][n-1]=='n'||a[m+1][n-1]=='b'||a[m+1][n-1]=='k'||a[m+1][n-1]=='q')
            {
                if(m+1>=1&&m+1<=8&&n-1>=1&&n-1<=8)
                {
                    possiblemovesv[h]=m+1;
                    possiblemovesh[h]=n-1;
                    flag=1;
                    h++;
                }
            }
            else
                flag=1;
        }
        m=x;
        n=y;
        flag=0;
        for(m=x; flag==0; m++)
        {
            n=y;
            if(a[m+1][n]=='.'||a[m+1][n]=='-')
            {
                if(m+1>=1&&m+1<=8)
                {
                    possiblemovesv[h]=m+1;
                    possiblemovesh[h]=n;
                    flag=0;
                }
            }
            else if(a[m+1][n]=='p'||a[m+1][n]=='r'||a[m+1][n]=='n'||a[m+1][n]=='b'||a[m+1][n]=='q')
            {
                if(m+1>=1&&m+1<=8)
                {
                    possiblemovesv[h]=m+1;
                    possiblemovesh[h]=n;
                    flag=1;
                    h++;
                }
            }
            else
                flag=1;
        }
        flag=0;
        for(m=x; flag==0; m--)
        {
            n=y;
            if(a[m-1][n]=='.'||a[m-1][n]=='-')
            {
                if(m-1>=1&&m-1<=8)
                {
                    possiblemovesv[h]=m-1;
                    possiblemovesh[h]=n;
                    flag=0;
                    h++;
                }
            }
            else if(a[m-1][n]=='p'||a[m-1][n]=='r'||a[m-1][n]=='n'||a[m-1][n]=='b'||a[m-1][n]=='q')
            {
                if(m-1>=1&&m-1<=8)
                {
                    possiblemovesv[h]=m-1;
                    possiblemovesh[h]=n;
                    flag=1;
                    h++;
                }
            }
            else
                flag=1;
        }
        flag=0;
        for(n=y; flag==0; n++)
        {
            m=x;
            if(a[m][n+1]=='.'||a[m][n+1]=='-')
            {
                if(n+1>=1&&n+1<=8)
                {
                    possiblemovesv[h]=m;
                    possiblemovesh[h]=n+1;
                    flag=0;
                    h++;
                }
            }
            else if(a[m][n+1]=='p'||a[m][n+1]=='r'||a[m][n+1]=='n'||a[m][n+1]=='b'||a[m][n+1]=='q')
            {
                if(n+1>=1&&n+1<=8)
                {
                    possiblemovesv[h]=m;
                    possiblemovesh[h]=n+1;
                    flag=1;
                    h++;
                }
            }
            else
                flag=1;
        }
        flag=0;
        for(n=y; flag==0; n--)
        {
            m=x;
            if(a[m][n-1]=='.'||a[m][n-1]=='-')
            {
                if(n-1>=1&&n-1<=8)
                {
                    possiblemovesv[h]=m;
                    possiblemovesh[h]=n-1;
                    flag=0;
                    h++;
                }
            }
            else if(a[m][n-1]=='p'||a[m][n-1]=='r'||a[m][n-1]=='n'||a[m][n-1]=='b'||a[m][n-1]=='q')
            {
                if(n-1>=1&&n-1<=8)
                {
                    possiblemovesv[h]=m;
                    possiblemovesh[h]=n-1;
                    flag=1;
                    h++;
                }
            }
            else
                flag=1;
        }


    }
    if(a[x][y]=='k')
    {
        if(a[x+1][y]=='.'||a[x+1][y]=='-'||a[x+1][y]=='P'||a[x+1][y]=='R'||a[x+1][y]=='B'||a[x+1][y]=='N'||a[x+1][y]=='Q')
        {
            if(x+1>=1&&x+1<=8)
            {
                possiblemovesv[h]=x+1;
                possiblemovesh[h]=y;
                h++;
            }
        }
        if(a[x-1][y]=='.'||a[x-1][y]=='-'||a[x-1][y]=='P'||a[x-1][y]=='R'||a[x-1][y]=='B'||a[x-1][y]=='N'||a[x-1][y]=='Q')
        {
            if(x-1>=1&&x-1<=8)
            {
                possiblemovesv[h]=x-1;
                possiblemovesh[h]=y;
                h++;
            }
        }
        if(a[x][y+1]=='.'||a[x][y+1]=='-'||a[x][y+1]=='P'||a[x][y+1]=='R'||a[x][y+1]=='B'||a[x][y+1]=='N'||a[x][y+1]=='Q')
        {
            if(y+1>=1&&y+1<=8)
            {
                possiblemovesv[h]=x;
                possiblemovesh[h]=y+1;
                h++;
            }
        }
        if(a[x][y-1]=='.'||a[x][y-1]=='-'||a[x][y-1]=='P'||a[x][y-1]=='R'||a[x][y-1]=='B'||a[x][y-1]=='N'||a[x][y-1]=='Q')
        {
            if(y-1>=1&&y-1<=8)
            {
                possiblemovesv[h]=x;
                possiblemovesh[h]=y-1;
                h++;
            }
        }
        if(a[x+1][y+1]=='.'||a[x+1][y+1]=='-'||a[x+1][y+1]=='P'||a[x+1][y+1]=='R'||a[x+1][y+1]=='B'||a[x+1][y+1]=='N'||a[x+1][y+1]=='Q')
        {
            if(x+1>=1&&x+1<=8&&y+1>=1&&y+1<=8)
            {
                possiblemovesv[h]=x+1;
                possiblemovesh[h]=y+1;
                h++;
            }
        }
        if(a[x-1][y-1]=='.'||a[x-1][y-1]=='-'||a[x-1][y-1]=='P'||a[x-1][y-1]=='R'||a[x-1][y-1]=='B'||a[x-1][y-1]=='N'||a[x-1][y-1]=='Q')
        {
            if(x-1>=1&&x-1<=8&&y-1>=1&&y-1<=8)
            {
                possiblemovesv[h]=x-1;
                possiblemovesh[h]=y-1;
                h++;
            }
        }
        if(a[x+1][y-1]=='.'||a[x+1][y-1]=='-'||a[x+1][y-1]=='P'||a[x+1][y-1]=='R'||a[x+1][y-1]=='B'||a[x+1][y-1]=='N'||a[x+1][y-1]=='Q')
        {
            if(x+1>=1&&x+1<=8)
            {
                possiblemovesv[h]=x+1;
                possiblemovesh[h]=y-1;
                h++;
            }
        }
        if(a[x-1][y+1]=='.'||a[x-1][y+1]=='-'||a[x-1][y+1]=='P'||a[x-1][y+1]=='R'||a[x-1][y+1]=='B'||a[x-1][y+1]=='N'||a[x-1][y+1]=='Q')
        {
            if(x+1>=1&&x+1<=8)
            {
                possiblemovesv[h]=x-1;
                possiblemovesh[h]=y+1;
                h++;
            }
        }
    }
    if(a[x][y]=='K')
    {
        if(a[x+1][y]=='.'||a[x+1][y]=='-'||a[x+1][y]=='p'||a[x+1][y]=='r'||a[x+1][y]=='b'||a[x+1][y]=='n'||a[x+1][y]=='q')
        {
            if(x+1>=1&&x+1<=8)
            {
                possiblemovesv[h]=x+1;
                possiblemovesh[h]=y;
                h++;
            }
        }
        if(a[x-1][y]=='.'||a[x-1][y]=='-'||a[x-1][y]=='p'||a[x-1][y]=='r'||a[x-1][y]=='b'||a[x-1][y]=='n'||a[x-1][y]=='q')
        {
            if(x-1>=1&&x-1<=8)
            {
                possiblemovesv[h]=x-1;
                possiblemovesh[h]=y;
                h++;
            }
        }
        if(a[x][y+1]=='.'||a[x][y+1]=='-'||a[x][y+1]=='p'||a[x][y+1]=='r'||a[x][y+1]=='b'||a[x][y+1]=='n'||a[x][y+1]=='q')
        {
            if(y+1>=1&&y+1<=8)
            {
                possiblemovesv[h]=x;
                possiblemovesh[h]=y+1;
                h++;
            }
        }
        if(a[x][y-1]=='.'||a[x][y-1]=='-'||a[x][y-1]=='p'||a[x][y-1]=='r'||a[x][y-1]=='b'||a[x][y-1]=='n'||a[x][y-1]=='q')
        {
            if(y-1>=1&&y-1<=8)
            {
                possiblemovesv[h]=x;
                possiblemovesh[h]=y-1;
                h++;
            }
        }
        if(a[x+1][y+1]=='.'||a[x+1][y+1]=='-'||a[x+1][y+1]=='p'||a[x+1][y+1]=='r'||a[x+1][y+1]=='b'||a[x+1][y+1]=='n'||a[x+1][y+1]=='q')
        {
            if(x+1>=1&&x+1<=8&&y+1>=1&&y+1<=8)
            {
                possiblemovesv[h]=x+1;
                possiblemovesh[h]=y+1;
                h++;
            }
        }
        if(a[x-1][y-1]=='.'||a[x-1][y-1]=='-'||a[x-1][y-1]=='p'||a[x-1][y-1]=='r'||a[x-1][y-1]=='b'||a[x-1][y-1]=='n'||a[x-1][y-1]=='q')
        {
            if(x-1>=1&&x-1<=8&&y-1>=1&&y-1<=8)
            {
                possiblemovesv[h]=x-1;
                possiblemovesh[h]=y-1;
                h++;
            }
        }
        if(a[x+1][y-1]=='.'||a[x+1][y-1]=='-'||a[x+1][y-1]=='p'||a[x+1][y-1]=='r'||a[x+1][y-1]=='b'||a[x+1][y-1]=='n'||a[x+1][y-1]=='q')
        {
            if(x+1>=1&&x+1<=8)
            {
                possiblemovesv[h]=x+1;
                possiblemovesh[h]=y-1;
                h++;
            }
        }
        if(a[x-1][y+1]=='.'||a[x-1][y+1]=='-'||a[x-1][y+1]=='p'||a[x-1][y+1]=='r'||a[x-1][y+1]=='b'||a[x-1][y+1]=='n'||a[x-1][y+1]=='q')
        {
            if(x+1>=1&&x+1<=8)
            {
                possiblemovesv[h]=x-1;
                possiblemovesh[h]=y+1;
                h++;
            }
        }

    }
    if(a[x][y]=='p')
    {
        if(x==2)
        {
            if(a[3][y]=='.'||a[3][y]=='-')
            {
                possiblemovesv[h]=3;
                possiblemovesh[h]=y;
                h++;
                if(a[4][y]=='.'||a[4][y]=='-')
                {
                    possiblemovesv[h]=4;
                    possiblemovesh[h]=y;
                    h++;
                }
            }

        }
        if(x!=2 && (a[x+1][y]=='.'||a[x+1][y]=='-'))
        {
            possiblemovesv[h]=x+1;
            possiblemovesh[h]=y;
            h++;
        }
        if(a[x+1][y+1]=='P'||a[x+1][y+1]=='R'||a[x+1][y+1]=='N'||a[x+1][y+1]=='B'||a[x+1][y+1]=='Q')
        {
            possiblemovesv[h]=x+1;
            possiblemovesh[h]=y+1;
            h++;
        }
        if(a[x+1][y-1]=='P'||a[x+1][y-1]=='R'||a[x+1][y-1]=='N'||a[x+1][y-1]=='B'||a[x+1][y-1]=='Q')
        {
            possiblemovesv[h]=x+1;
            possiblemovesh[h]=y-1;
            h++;
        }

    }
    if(a[x][y]=='P')
    {
        if(x==7)
        {
            if(a[6][y]=='.'||a[6][y]=='-')
            {
                possiblemovesv[h]=6;
                possiblemovesh[h]=y;
                h++;
                if(a[5][y]=='.'||a[5][y]=='-')
                {
                    possiblemovesv[h]=5;
                    possiblemovesh[h]=y;
                    h++;
                }
            }

        }
        if(x!=7&& (a[x-1][y]=='.'||a[x-1][y]=='-'))
        {
            possiblemovesv[h]=x-1;
            possiblemovesh[h]=y;
            h++;
        }
        if(a[x-1][y-1]=='p'||a[x-1][y-1]=='r'||a[x-1][y-1]=='n'||a[x-1][y-1]=='b'||a[x-1][y-1]=='q')
        {
            possiblemovesv[h]=x-1;
            possiblemovesh[h]=y-1;
            h++;
        }
        if(a[x-1][y+1]=='p'||a[x-1][y+1]=='r'||a[x-1][y+1]=='n'||a[x-1][y+1]=='b'||a[x-1][y+1]=='q')
        {
            possiblemovesv[h]=x-1;
            possiblemovesh[h]=y+1;
            h++;
        }
    }
    if(a[x][y]=='r')
    {
        int m,n;
        m=x;
        n=y;
        int flag=0;
        for(m=x; flag==0; m++)
        {
            n=y;
            if(a[m+1][n]=='.'||a[m+1][n]=='-')
            {
                if(m+1>=1&&m+1<=8)
                {
                    possiblemovesv[h]=m+1;
                    possiblemovesh[h]=n;
                    flag=0;
                    h++;
                }
            }
            else if(a[m+1][n]=='P'||a[m+1][n]=='R'||a[m+1][n]=='N'||a[m+1][n]=='B'||a[m+1][n]=='Q')
            {
                if(m+1>=1&&m+1<=8)
                {
                    possiblemovesv[h]=m+1;
                    possiblemovesh[h]=n;
                    flag=1;
                    h++;
                }
            }
            else
                flag=1;
        }
        flag=0;
        for(m=x; flag==0; m--)
        {
            n=y;
            if(a[m-1][n]=='.'||a[m-1][n]=='-')
            {
                if(m-1>=1&&m-1<=8)
                {
                    possiblemovesv[h]=m-1;
                    possiblemovesh[h]=n;
                    flag=0;
                    h++;
                }
            }
            else if(a[m-1][n]=='P'||a[m-1][n]=='R'||a[m-1][n]=='N'||a[m-1][n]=='B'||a[m-1][n]=='Q')
            {
                if(m-1>=1&&m-1<=8)
                {
                    possiblemovesv[h]=m-1;
                    possiblemovesh[h]=n;
                    flag=1;
                    h++;
                }
            }
            else
                flag=1;
        }
        flag=0;
        for(n=y; flag==0; n++)
        {
            m=x;
            if(a[m][n+1]=='.'||a[m][n+1]=='-')
            {
                if(n+1>=1&&n+1<=8)
                {
                    possiblemovesv[h]=m;
                    possiblemovesh[h]=n+1;
                    flag=0;
                    h++;
                }
            }
            else if(a[m][n+1]=='P'||a[m][n+1]=='R'||a[m][n+1]=='N'||a[m][n+1]=='B'||a[m][n+1]=='Q')
            {
                if(n+1>=1&&n+1<=8)
                {
                    possiblemovesv[h]=m;
                    possiblemovesh[h]=n+1;
                    flag=1;
                    h++;
                }
            }
            else
                flag=1;
        }
        flag=0;
        for(n=y; flag==0; n--)
        {
            m=x;
            if(a[m][n-1]=='.'||a[m][n-1]=='-')
            {
                if(n-1>=1&&n-1<=8)
                {
                    possiblemovesv[h]=m;
                    possiblemovesh[h]=n-1;
                    flag=0;
                    h++;
                }
            }
            else if(a[m][n-1]=='P'||a[m][n-1]=='R'||a[m][n-1]=='N'||a[m][n-1]=='B'||a[m][n-1]=='Q')
            {
                if(n-1>=1&&n-1<=8)
                {
                    possiblemovesv[h]=m;
                    possiblemovesh[h]=n-1;
                    flag=1;
                    h++;
                }
            }
            else
                flag=1;
        }
    }
    if(a[x][y]=='R')
    {
        int m,n;
        m=x;
        n=y;
        int flag=0;
        for(m=x; flag==0; m++)
        {
            n=y;
            if(a[m+1][n]=='.'||a[m+1][n]=='-')
            {
                if(m+1>=1&&m+1<=8)
                {
                    possiblemovesv[h]=m+1;
                    possiblemovesh[h]=n;
                    flag=0;
                }
            }
            else if(a[m+1][n]=='p'||a[m+1][n]=='r'||a[m+1][n]=='n'||a[m+1][n]=='b'||a[m+1][n]=='q')
            {
                if(m+1>=1&&m+1<=8)
                {
                    possiblemovesv[h]=m+1;
                    possiblemovesh[h]=n;
                    flag=1;
                    h++;
                }
            }
            else
                flag=1;
        }
        flag=0;
        for(m=x; flag==0; m--)
        {
            n=y;
            if(a[m-1][n]=='.'||a[m-1][n]=='-')
            {
                if(m-1>=1&&m-1<=8)
                {
                    possiblemovesv[h]=m-1;
                    possiblemovesh[h]=n;
                    flag=0;
                    h++;
                }
            }
            else if(a[m-1][n]=='p'||a[m-1][n]=='r'||a[m-1][n]=='n'||a[m-1][n]=='b'||a[m-1][n]=='q')
            {
                if(m-1>=1&&m-1<=8)
                {
                    possiblemovesv[h]=m-1;
                    possiblemovesh[h]=n;
                    flag=1;
                    h++;
                }
            }
            else
                flag=1;
        }
        flag=0;
        for(n=y; flag==0; n++)
        {
            m=x;
            if(a[m][n+1]=='.'||a[m][n+1]=='-')
            {
                if(n+1>=1&&n+1<=8)
                {
                    possiblemovesv[h]=m;
                    possiblemovesh[h]=n+1;
                    flag=0;
                    h++;
                }
            }
            else if(a[m][n+1]=='p'||a[m][n+1]=='r'||a[m][n+1]=='n'||a[m][n+1]=='b'||a[m][n+1]=='q')
            {
                if(n+1>=1&&n+1<=8)
                {
                    possiblemovesv[h]=m;
                    possiblemovesh[h]=n+1;
                    flag=1;
                    h++;
                }
            }
            else
                flag=1;
        }
        flag=0;
        for(n=y; flag==0; n--)
        {
            m=x;
            if(a[m][n-1]=='.'||a[m][n-1]=='-')
            {
                if(n-1>=1&&n-1<=8)
                {
                    possiblemovesv[h]=m;
                    possiblemovesh[h]=n-1;
                    flag=0;
                    h++;
                }
            }
            else if(a[m][n-1]=='p'||a[m][n-1]=='r'||a[m][n-1]=='n'||a[m][n-1]=='b'||a[m][n-1]=='q')
            {
                if(n-1>=1&&n-1<=8)
                {
                    possiblemovesv[h]=m;
                    possiblemovesh[h]=n-1;
                    flag=1;
                    h++;
                }
            }
            else
                flag=1;
        }
    }
    if(a[x][y]=='b')
    {
        int m,n;
        m=x;
        n=y;
        int flag=0;
        for(m=x; flag==0; m++)
        {

            if(a[m+1][n+1]=='.'||a[m+1][n+1]=='-')
            {
                if(m+1>=1&&m+1<=8&&n+1>=1&&n+1<=8)
                {
                    possiblemovesv[h]=m+1;
                    possiblemovesh[h]=n+1;
                    flag=0;
                    h++;
                    n++;
                }
            }
            else if(a[m+1][n+1]=='P'||a[m+1][n+1]=='R'||a[m+1][n+1]=='N'||a[m+1][n+1]=='B'||a[m+1][n+1]=='Q')
            {
                if(m+1>=1&&m+1<=8&&n+1>=1&&n+1<=8)
                {
                    possiblemovesv[h]=m+1;
                    possiblemovesh[h]=n+1;
                    flag=1;
                    h++;
                }
            }
            else
                flag=1;
        }
        flag=0;
        n=y;
        for(m=x; flag==0; m--)
        {
            if(a[m-1][n+1]=='.'||a[m-1][n+1]=='-')
            {
                if(m-1>=1&&m-1<=8&&n+1>=1&&n+1<=8)
                {
                    possiblemovesv[h]=m-1;
                    possiblemovesh[h]=n+1;
                    flag=0;
                    h++;
                    n++;
                }
            }
            else if(a[m-1][n+1]=='P'||a[m-1][n+1]=='R'||a[m-1][n+1]=='N'||a[m-1][n+1]=='B'||a[m-1][n+1]=='Q')
            {
                if(m-1>=1&&m-1<=8&&n+1>=1&&n+1<=8)
                {
                    possiblemovesv[h]=m-1;
                    possiblemovesh[h]=n+1;
                    flag=1;
                    h++;
                }
            }
            else
                flag=1;
        }
        flag=0;
        m=x;
        for(n=y; flag==0; n--)
        {
            if(a[m-1][n-1]=='.'||a[m-1][n-1]=='-')
            {
                if(m-1>=1&&m-1<=8&&n-1>=1&&n-1<=8)
                {
                    possiblemovesv[h]=m-1;
                    possiblemovesh[h]=n-1;
                    flag=0;
                    h++;
                    m--;
                }
            }
            else if(a[m-1][n-1]=='P'||a[m-1][n-1]=='R'||a[m-1][n-1]=='N'||a[m-1][n-1]=='B'||a[m-1][n-1]=='Q')
            {
                if(m-1>=1&&m-1<=8&&n-1>=1&&n-1<=8)
                {
                    possiblemovesv[h]=m-1;
                    possiblemovesh[h]=n-1;
                    flag=1;
                    h++;
                }
            }
            else
                flag=1;
        }
        flag=0;
        m=x;
        for(n=y; flag==0; n--)
        {

            if(a[m+1][n-1]=='.'||a[m+1][n-1]=='-')
            {
                if(m+1>=1&&m+1<=8&&n-1>=1&&n-1<=8)
                {
                    possiblemovesv[h]=m+1;
                    possiblemovesh[h]=n-1;
                    flag=0;
                    h++;
                    m++;
                }
            }
            else if(a[m+1][n-1]=='P'||a[m+1][n-1]=='R'||a[m+1][n-1]=='N'||a[m+1][n-1]=='B'||a[m+1][n-1]=='Q')
            {
                if(m+1>=1&&m+1<=8&&n-1>=1&&n-1<=8)
                {
                    possiblemovesv[h]=m+1;
                    possiblemovesh[h]=n-1;
                    flag=1;
                    h++;
                }
            }
            else
                flag=1;
        }
    }
    if(a[x][y]=='B')
    {
        int m,n;
        m=x;
        n=y;
        int flag=0;
        for(m=x; flag==0; m++)
        {

            if(a[m+1][n+1]=='.'||a[m+1][n+1]=='-')
            {
                if(m+1>=1&&m+1<=8&&n+1>=1&&n+1<=8)
                {
                    possiblemovesv[h]=m+1;
                    possiblemovesh[h]=n+1;
                    flag=0;
                    h++;
                    n++;
                }
            }
            else if(a[m+1][n+1]=='p'||a[m+1][n+1]=='r'||a[m+1][n+1]=='n'||a[m+1][n+1]=='b'||a[m+1][n+1]=='q')
            {
                if(m+1>=1&&m+1<=8&&n+1>=1&&n+1<=8)
                {
                    possiblemovesv[h]=m+1;
                    possiblemovesh[h]=n+1;
                    flag=1;
                    h++;
                }
            }
            else
                flag=1;
        }
        flag=0;
        n=y;
        for(m=x; flag==0; m--)
        {
            if(a[m-1][n+1]=='.'||a[m-1][n+1]=='-')
            {
                if(m-1>=1&&m-1<=8&&n+1>=1&&n+1<=8)
                {
                    possiblemovesv[h]=m-1;
                    possiblemovesh[h]=n+1;
                    flag=0;
                    h++;
                    n++;
                }
            }
            else if(a[m-1][n+1]=='p'||a[m-1][n+1]=='r'||a[m-1][n+1]=='n'||a[m-1][n+1]=='b'||a[m-1][n+1]=='q')
            {
                if(m-1>=1&&m-1<=8&&n+1>=1&&n+1<=8)
                {
                    possiblemovesv[h]=m-1;
                    possiblemovesh[h]=n+1;
                    flag=1;
                    h++;
                }
            }
            else
                flag=1;
        }
        flag=0;
        m=x;
        for(n=y; flag==0; n--)
        {
            if(a[m-1][n-1]=='.'||a[m-1][n-1]=='-')
            {
                if(m-1>=1&&m-1<=8&&n-1>=1&&n-1<=8)
                {
                    possiblemovesv[h]=m-1;
                    possiblemovesh[h]=n-1;
                    flag=0;
                    h++;
                    m--;
                }
            }
            else if(a[m-1][n-1]=='p'||a[m-1][n-1]=='r'||a[m-1][n-1]=='n'||a[m-1][n-1]=='b'||a[m-1][n-1]=='q')
            {
                if(m-1>=1&&m-1<=8&&n-1>=1&&n-1<=8)
                {
                    possiblemovesv[h]=m-1;
                    possiblemovesh[h]=n-1;
                    flag=1;
                    h++;
                }
            }
            else
                flag=1;
        }
        flag=0;
        m=x;
        for(n=y; flag==0; n--)
        {

            if(a[m+1][n-1]=='.'||a[m+1][n-1]=='-')
            {
                if(m+1>=1&&m+1<=8&&n-1>=1&&n-1<=8)
                {
                    possiblemovesv[h]=m+1;
                    possiblemovesh[h]=n-1;
                    flag=0;
                    h++;
                    m++;
                }
            }
            else if(a[m+1][n-1]=='p'||a[m+1][n-1]=='r'||a[m+1][n-1]=='n'||a[m+1][n-1]=='b'||a[m+1][n-1]=='q')
            {
                if(m+1>=1&&m+1<=8&&n-1>=1&&n-1<=8)
                {
                    possiblemovesv[h]=m+1;
                    possiblemovesh[h]=n-1;
                    flag=1;
                    h++;
                }
            }
            else
                flag=1;
        }
    }

    int i;
    int k=0;
    for(i=0; i<h; i++)
    {
        if(possiblemovesv[i]==w && possiblemovesh[i]==q)
        {
            k=1;
        }
    }
    return k;
}
//x,y king place //arr board
int checked_white(int x,int y,char arr[10][10])
{
    int n=0;
    int i,c;
    int f,d;

    if(arr[x+1][y+1]=='P'||arr[x+1][y-1]=='P')
    {
        n=1;
    }

    //ROCK & queen
    if(n==0)
    {
        for(i=y+1; i<=8; i++)
        {
            if(arr[x][i]=='R'||arr[x][i]=='Q')
            {
                if(i==y+1)
                {
                    n=1;
                    break;
                }
                else
                    for(c=i-1; c>y; c--)
                    {
                        if(arr[x][c]=='.'||arr[x][c]=='-')
                            n=1;
                        else
                        {
                            n=0;
                            break;
                        }
                    }
            }
        }
    }

    if(n==0)
    {
        for(i=y-1; i>0; i--)
        {
            if(arr[x][i]=='R'||arr[x][i]=='Q')
            {
                if(i==y-1)
                {
                    n=1;
                    break;
                }
                else
                    for(c=i+1; c<y; c++)
                    {
                        if(arr[x][c]=='.'||arr[x][c]=='-')
                            n=1;
                        else
                        {
                            n=0;
                            break;
                        }
                    }
            }
        }

    }

    if(n==0)
    {
        for(i=x-1; i>0; i--)
        {
            if(arr[i][y]=='R'||arr[i][y]=='Q')
            {
                if(i==x-1)
                {
                    n=1;
                    break;
                }
                else
                {
                    for(c=i+1; c<x; c++)
                    {
                        if(arr[c][y]=='.'||arr[c][y]=='-')
                            n=1;
                        else
                        {
                            n=0;
                            break;
                        }
                    }
                }
            }
        }

    }

    if(n==0)
    {
        for(i=x+1; i<=8; i++)
        {
            if(arr[i][y]=='R'||arr[i][y]=='Q')
            {
                if(i==x+1)
                {
                    n=1;
                    break;
                }
                else
                    for(c=i-1; c>x; c--)
                    {
                        if(arr[c][y]=='.'||arr[c][y]=='-')
                            n=1;
                        else
                        {
                            n=0;
                            break;
                        }

                    }
            }
        }
    }
    //BISHOP & QUEEN
    if(n==0)
    {
        for(d=x+1,i=y+1; i<=8,d<=8; d++,i++)
        {
            if(arr[d][i]=='B'||arr[d][i]=='Q')
            {
                if(i==y+1)
                {
                    n=1;
                    break;
                }
                else
                    for(f=d-1,c=i-1; c>y,f>x; f--,c--)
                    {
                        if(arr[f][c]=='.'||arr[f][c]=='-')
                            n=1;
                        else
                        {
                            n=0;
                            break;
                        }
                    }
            }
        }
    }

    if(n==0)
    {
        for(d=x+1,i=y-1; i>0,d<=8; d++,i--)
        {
            if(arr[d][i]=='B'||arr[d][i]=='Q')
            {
                if(i==y-1)
                {
                    n=1;
                    break;
                }
                else
                    for(f=d-1,c=i+1; c<y,f>x; f--,c++)
                    {
                        if(arr[f][c]=='.'||arr[f][c]=='-')
                            n=1;
                        else
                        {
                            n=0;
                            break;
                        }
                    }
            }
        }
    }

    if(n==0)
    {
        for(d=x-1,i=y+1; i<=8,d>0; d--,i++)
        {
            if(arr[d][i]=='B'||arr[d][i]=='Q')
            {
                if(i==y+1)
                {
                    n=1;
                    break;
                }
                else
                    for(f=d+1,c=i-1; c>y,f<x; f++,c--)
                    {
                        if(arr[f][c]=='.'||arr[f][c]=='-')
                            n=1;
                        else
                        {
                            n=0;
                            break;
                        }
                    }
            }
        }
    }

    if(n==0)
    {
        for(d=x-1,i=y-1; i>0,d>0; d--,i--)
        {
            if(arr[d][i]=='B'||arr[d][i]=='Q')
            {
                if(i==y-1)
                {
                    n=1;
                    break;
                }
                else
                    for(f=d+1,c=i+1; c<y,f<x; f++,c++)
                    {
                        if(arr[f][c]=='.'||arr[f][c]=='-')
                            n=1;
                        else
                        {
                            n=0;
                            break;
                        }
                    }
            }
        }
    }

    //KNIGHT
    if(n==0)
    {
        if(arr[x+1][y+2]=='N'||arr[x+1][y-2]=='N'||arr[x-1][y-2]=='N'||arr[x-1][y+2]=='N'||arr[x+2][y-1]=='N'||arr[x+2][y+1]=='N'||arr[x-2][y-1]=='N'||arr[x-2][y+1]=='N')
            n=1;
    }

    return n;
}
//x,y king place //arr board
int checked_black(int x,int y,char arr[10][10])
{
    int n=0;
    int i,c;
    int f,d;

    if(arr[x-1][y+1]=='p'||arr[x-1][y-1]=='p')
    {
        n=1;
    }

    //ROCK & queen
    if(n==0)
    {
        for(i=y+1; i<=8; i++)
        {
            if(arr[x][i]=='r'||arr[x][i]=='q')
            {
                if(i==y+1)
                {
                    n=1;
                    break;
                }
                else
                    for(c=i-1; c>y; c--)
                    {
                        if(arr[x][c]=='.'||arr[x][c]=='-')
                            n=1;
                        else
                        {
                            n=0;
                            break;
                        }
                    }
            }
        }
    }

    if(n==0)
    {
        for(i=y-1; i>0; i--)
        {
            if(arr[x][i]=='r'||arr[x][i]=='q')
            {
                if(i==y-1)
                {
                    n=1;
                    break;
                }
                else
                    for(c=i+1; c<y; c++)
                    {
                        if(arr[x][c]=='.'||arr[x][c]=='-')
                            n=1;
                        else
                        {
                            n=0;
                            break;
                        }
                    }
            }
        }

    }

    if(n==0)
    {
        for(i=x-1; i>0; i--)
        {
            if(arr[i][y]=='r'||arr[i][y]=='q')
            {
                if(i==x-1)
                {
                    n=1;
                    break;
                }
                else
                    for(c=i+1; c<x; c++)
                    {
                        if(arr[c][y]=='.'||arr[c][y]=='-')
                            n=1;
                        else
                        {
                            n=0;
                            break;
                        }
                    }
            }
        }

    }

    if(n==0)
    {
        for(i=x+1; i<=8; i++)
        {
            if(arr[i][y]=='r'||arr[i][y]=='q')
            {
                if(i==x+1)
                {
                    n=1;
                    break;
                }
                else
                    for(c=i-1; c>x; c--)
                    {
                        if(arr[c][y]=='.'||arr[c][y]=='-')
                            n=1;
                        else
                        {
                            n=0;
                            break;
                        }
                    }
            }
        }
    }

    //BISHOP & QUEEN
    if(n==0)
    {
        for(d=x+1,i=y+1; i<=8,d<=8; d++,i++)
        {
            if(arr[d][i]=='b'||arr[d][i]=='q')
            {
                if(i==y+1)
                {
                    n=1;
                    break;
                }
                else
                    for(f=d-1,c=i-1; c>y,f>x; f--,c--)
                    {
                        if(arr[f][c]=='.'||arr[f][c]=='-')
                            n=1;
                        else
                        {
                            n=0;
                            break;
                        }
                    }
            }
        }
    }

    if(n==0)
    {
        for(d=x+1,i=y-1; i>0,d<=8; d++,i--)
        {
            if(arr[d][i]=='b'||arr[d][i]=='q')
            {
                if(i==y-1)
                {
                    n=1;
                    break;
                }
                else
                    for(f=d-1,c=i+1; c<y,f>x; f--,c++)
                    {
                        if(arr[f][c]=='.'||arr[f][c]=='-')
                            n=1;
                        else
                        {
                            n=0;
                            break;
                        }
                    }
            }
        }
    }

    if(n==0)
    {
        for(d=x-1,i=y+1; i<=8,d>0; d--,i++)
        {
            if(arr[d][i]=='b'||arr[d][i]=='q')
            {
                if(i==y+1)
                {
                    n=1;
                    break;
                }
                else
                    for(f=d+1,c=i-1; c>y,f<x; f++,c--)
                    {
                        if(arr[f][c]=='.'||arr[f][c]=='-')
                            n=1;
                        else
                        {
                            n=0;
                            break;
                        }
                    }
            }
        }
    }

    if(n==0)
    {
        for(d=x-1,i=y-1; i>0,d>0; d--,i--)
        {
            if(arr[d][i]=='b'||arr[d][i]=='q')
            {
                if(i==y-1)
                {
                    n=1;
                    break;
                }
                else
                    for(f=d+1,c=i+1; c<y,f<x; f++,c++)
                    {
                        if(arr[f][c]=='.'||arr[f][c]=='-')
                            n=1;
                        else
                        {
                            n=0;
                            break;
                        }
                    }
            }
        }
    }

    //KNIGHT
    if(n==0)
    {
        if(arr[x+1][y+2]=='n'||arr[x+1][y-2]=='n'||arr[x-1][y-2]=='n'||arr[x-1][y+2]=='n'||arr[x+2][y-1]=='n'||arr[x+2][y+1]=='n'||arr[x-2][y-1]=='n'||arr[x-2][y+1]=='n')
            n=1;
    }

    return n;
}

int promotion(int x,int y,int u,int v,char a[10][10],char moves[5])
{
    int n=0;
    if(u==7&&a[u][v]=='p')
    {
        if(y==v&&(a[x][y]=='.'||a[x][y]=='-'))
        {
            if(moves[4]=='r'||moves[4]=='q'||moves[4]=='n'||moves[4]=='b')
                n=1;
            else if(moves[4]=='\0')
                printf("Enter your promotion piece.");
            else if(moves[4]=='k')
                printf("you can't promote to king.\n");
        }
        else if(y==(v+1)||y==(v-1))
        {
            if(moves[4]=='r'||moves[4]=='q'||moves[4]=='n'||moves[4]=='b')
                n=1;
            else if(moves[4]=='\0')
                printf("Enter your promotion piece.");
            else if(moves[4]=='k')
                printf("you can't promote to king.\n");
        }
    }
    else if(u==2&&a[u][v]=='P')
    {
        if(y==v&&(a[x][y]=='.'||a[x][y]=='-'))
        {
            if(moves[4]=='R'||moves[4]=='Q'||moves[4]=='N'||moves[4]=='B')
                n=1;
            else if(moves[4]=='\0')
                printf("Enter your promotion piece.");
            else if(moves[4]=='k')
                printf("you can't promote to king.\n");
        }
        else if((y==v+1||y==v-1)&&a[x][y]!='.'&&a[x][y]!='-'&&moves[4]!='\0')
        {
            if(moves[4]=='R'||moves[4]=='Q'||moves[4]=='N'||moves[4]=='B')
                n=1;
            else if(moves[4]=='\0')
                printf("Enter your promotion piece.");
            else if(moves[4]=='k')
                printf("you can't promote to king.\n");
        }
    }
    return n;

}
//x,y king place //arr board //place_white  white pieces place
int checkmate_white(int x,int y,char arr[10][10],int place_white[16][2])
{
    int g=0;
    int i;
    char piece;

    if(checked_white(x,y,arr)==1)
    {
        arr[x][y]='.';
        g=1;
        if(checked_white(x-1,y-1,arr)!=1)
        {
            arr[x][y]='k';
            if(checkMove(x,y,x-1,y-1,arr)==1)
            {
                g=0;
            }
            arr[x][y]='.';
        }
        if(checked_white(x,y-1,arr)!=1)
        {
            arr[x][y]='k';
            if(checkMove(x,y,x,y-1,arr)==1)
            {
                g=0;
            }
            arr[x][y]='.';
        }
        if(checked_white(x+1,y-1,arr)!=1)
        {
            arr[x][y]='k';
            if(checkMove(x,y,x+1,y-1,arr)==1)
            {
                g=0;
            }
            arr[x][y]='.';
        }
        if(checked_white(x,y+1,arr)!=1)
        {
            arr[x][y]='k';
            if(checkMove(x,y,x,y+1,arr)==1)
            {
                g=0;
            }
            arr[x][y]='.';
        }
        if(checked_white(x+1,y,arr)!=1)
        {
            arr[x][y]='k';
            if(checkMove(x,y,x+1,y,arr)==1)
            {
                g=0;
            }
            arr[x][y]='.';
        }
        if(checked_white(x-1,y,arr)!=1)
        {
            arr[x][y]='k';
            if(checkMove(x,y,x-1,y,arr)==1)
            {
                g=0;
            }
            arr[x][y]='.';
        }
        if(checked_white(x-1,y+1,arr)!=1)
        {
            arr[x][y]='k';
            if(checkMove(x,y,x-1,y+1,arr)==1)
            {
                g=0;
            }
            arr[x][y]='.';
        }
        if(checked_white(x+1,y+1,arr)!=1)
        {
            arr[x][y]='k';
            if(checkMove(x,y,x+1,y+1,arr)==1)
            {
                g=0;
            }
            arr[x][y]='.';
        }
        arr[x][y]='K';

        //bishop
        if(arr[place_white[2][0]][place_white[2][1]]=='b')
        {
            checkMove(place_white[2][0],place_white[2][1],x,y,arr);
            for(i=0; possiblemovesh[i]!=0; i++)
            {
                piece=arr[possiblemovesv[i]][possiblemovesh[i]];
                arr[place_white[2][0]][place_white[2][1]]=b[place_white[2][0]][place_white[2][1]];
                arr[possiblemovesv[i]][possiblemovesh[i]]='b';
                if(checked_white(x,y,arr)!=1)
                {
                    g=0;
                    arr[possiblemovesv[i]][possiblemovesh[i]]= piece;
                    arr[place_white[2][0]][place_white[2][1]]='b';
                    break;
                }
                arr[possiblemovesv[i]][possiblemovesh[i]]= piece;
                arr[place_white[2][0]][place_white[2][1]]='b';

            }
        }

        if(arr[place_white[5][0]][place_white[5][1]]=='b')
        {
            checkMove(place_white[5][0],place_white[5][1],x,y,arr);
            for(i=0; possiblemovesh[i]!=0; i++)
            {
                piece=arr[possiblemovesv[i]][possiblemovesh[i]];
                arr[place_white[5][0]][place_white[5][1]]=b[place_white[5][0]][place_white[5][1]];
                arr[possiblemovesv[i]][possiblemovesh[i]]='b';
                if(checked_white(x,y,arr)!=1)
                {
                    g=0;
                    arr[possiblemovesv[i]][possiblemovesh[i]]= piece;
                    arr[place_white[5][0]][place_white[5][1]]='b';
                    break;
                }
                arr[possiblemovesv[i]][possiblemovesh[i]]= piece;
                arr[place_white[5][0]][place_white[5][1]]='b';

            }
        }

        //ROCK
        if(arr[place_white[0][0]][place_white[0][1]]=='r')
        {
            checkMove(place_white[0][0],place_white[0][1],x,y,arr);
            for(i=0; possiblemovesh[i]!=0; i++)
            {
                piece=arr[possiblemovesv[i]][possiblemovesh[i]];
                arr[place_white[0][0]][place_white[0][1]]=b[place_white[0][0]][place_white[0][1]];
                arr[possiblemovesv[i]][possiblemovesh[i]]='r';
                if(checked_white(x,y,arr)!=1)
                {
                    g=0;
                    arr[possiblemovesv[i]][possiblemovesh[i]]= piece;
                    arr[place_white[0][0]][place_white[0][1]]='r';
                    break;
                }
                arr[possiblemovesv[i]][possiblemovesh[i]]= piece;
                arr[place_white[0][0]][place_white[0][1]]='r';

            }
        }

        if(arr[place_white[7][0]][place_white[5][1]]=='r')
        {
            checkMove(place_white[7][0],place_white[7][1],x,y,arr);
            for(i=0; possiblemovesh[i]!=0; i++)
            {
                piece=arr[possiblemovesv[i]][possiblemovesh[i]];
                arr[place_white[7][0]][place_white[7][1]]=b[place_white[7][0]][place_white[7][1]];
                arr[possiblemovesv[i]][possiblemovesh[i]]='r';
                if(checked_white(x,y,arr)!=1)
                {
                    g=0;
                    arr[possiblemovesv[i]][possiblemovesh[i]]= piece;
                    arr[place_white[7][0]][place_white[7][1]]='r';
                    break;
                }
                arr[possiblemovesv[i]][possiblemovesh[i]]= piece;
                arr[place_white[7][0]][place_white[7][1]]='r';

            }
        }

        //knight
        if(arr[place_white[1][0]][place_white[1][1]]=='n')
        {
            checkMove(place_white[1][0],place_white[1][1],x,y,arr);
            for(i=0; possiblemovesh[i]!=0; i++)
            {
                piece=arr[possiblemovesv[i]][possiblemovesh[i]];
                arr[place_white[1][0]][place_white[1][1]]=b[place_white[1][0]][place_white[1][1]];
                arr[possiblemovesv[i]][possiblemovesh[i]]='n';
                if(checked_white(x,y,arr)!=1)
                {
                    g=0;
                    arr[possiblemovesv[i]][possiblemovesh[i]]= piece;
                    arr[place_white[1][0]][place_white[1][1]]='n';
                    break;
                }
                arr[possiblemovesv[i]][possiblemovesh[i]]= piece;
                arr[place_white[1][0]][place_white[1][1]]='n';

            }
        }

        if(arr[place_white[6][0]][place_white[6][1]]=='n')
        {
            checkMove(place_white[6][0],place_white[6][1],x,y,arr);
            for(i=0; possiblemovesh[i]!=0; i++)
            {
                piece=arr[possiblemovesv[i]][possiblemovesh[i]];
                arr[place_white[6][0]][place_white[6][1]]=b[place_white[6][0]][place_white[6][1]];
                arr[possiblemovesv[i]][possiblemovesh[i]]='n';
                if(checked_white(x,y,arr)!=1)
                {
                    g=0;
                    arr[possiblemovesv[i]][possiblemovesh[i]]= piece;
                    arr[place_white[6][0]][place_white[6][1]]='n';
                    break;
                }
                arr[possiblemovesv[i]][possiblemovesh[i]]= piece;
                arr[place_white[6][0]][place_white[7][1]]='n';

            }
        }

        //queen
        if(arr[place_white[4][0]][place_white[4][1]]=='q')
        {
            checkMove(place_white[4][0],place_white[4][1],x,y,arr);
            for(i=0; possiblemovesh[i]!=0; i++)
            {
                piece=arr[possiblemovesv[i]][possiblemovesh[i]];
                arr[place_white[4][0]][place_white[4][1]]=b[place_white[4][0]][place_white[4][1]];
                arr[possiblemovesv[i]][possiblemovesh[i]]='q';
                if(checked_white(x,y,arr)!=1)
                {
                    g=0;
                    arr[possiblemovesv[i]][possiblemovesh[i]]= piece;
                    arr[place_white[4][0]][place_white[4][1]]='q';
                    break;
                }
                arr[possiblemovesv[i]][possiblemovesh[i]]= piece;
                arr[place_white[4][0]][place_white[4][1]]='q';

            }
        }

        //pawn
        int c;
        for(c=1; c<=8; c++)
        {
            if(arr[place_white[7+c][0]][place_white[7+c][1]]=='p'||arr[place_white[7+c][0]][place_white[7+c][1]]=='q'||arr[place_white[7+c][0]][place_white[7+c][1]]=='r'||arr[place_white[7+c][0]][place_white[7+c][1]]=='b'||arr[place_white[7+c][0]][place_white[7+c][1]]=='n')
            {
                checkMove(place_white[7+c][0],place_white[7+c][1],x,y,arr);
                for(i=0; possiblemovesh[i]!=0; i++)
                {
                    piece=arr[possiblemovesv[i]][possiblemovesh[i]];
                    arr[place_white[7+c][0]][place_white[7+c][1]]=b[place_white[7+c][0]][place_white[7+c][1]];
                    arr[possiblemovesv[i]][possiblemovesh[i]]='p';
                    if(checked_white(x,y,arr)!=1)
                    {
                        g=0;
                        arr[possiblemovesv[i]][possiblemovesh[i]]= piece;
                        arr[place_white[7+c][0]][place_white[7+c][1]]='p';
                        break;
                    }
                    arr[possiblemovesv[i]][possiblemovesh[i]]= piece;
                    arr[place_white[7+c][0]][place_white[7+c][1]]='p';
                }
            }
        }
    }


    arr[x][y]='k';
    return g;
}
//x,y king place //arr board //place_white  white pieces place
int draw_white(int x,int y,char arr[10][10],int place_white[16][2])
{
    int g=0;
    int i;
    char piece;
    if(checked_white(x,y,arr)!=1)
    {
        arr[x][y]='.';
        g=1;
        if(checked_white(x-1,y-1,arr)!=1)
        {
            arr[x][y]='k';
            if(checkMove(x,y,x-1,y-1,arr)==1)
            {
                g=0;
            }
            arr[x][y]='.';
        }
        if(checked_white(x,y-1,arr)!=1)
        {
            arr[x][y]='k';
            if(checkMove(x,y,x,y-1,arr)==1)
            {
                g=0;
            }
            arr[x][y]='.';
        }
        if(checked_white(x+1,y-1,arr)!=1)
        {
            arr[x][y]='k';
            if(checkMove(x,y,x+1,y-1,arr)==1)
            {
                g=0;
            }
            arr[x][y]='.';
        }
        if(checked_white(x,y+1,arr)!=1)
        {
            arr[x][y]='k';
            if(checkMove(x,y,x,y+1,arr)==1)
            {
                g=0;
            }
            arr[x][y]='.';
        }
        if(checked_white(x+1,y,arr)!=1)
        {
            arr[x][y]='k';
            if(checkMove(x,y,x+1,y,arr)==1)
            {
                g=0;
            }
            arr[x][y]='.';
        }
        if(checked_white(x-1,y,arr)!=1)
        {
            arr[x][y]='k';
            if(checkMove(x,y,x-1,y,arr)==1)
            {
                g=0;
            }
            arr[x][y]='.';
        }
        if(checked_white(x-1,y+1,arr)!=1)
        {
            arr[x][y]='k';
            if(checkMove(x,y,x-1,y+1,arr)==1)
            {
                g=0;
            }
            arr[x][y]='.';
        }
        if(checked_white(x+1,y+1,arr)!=1)
        {
            arr[x][y]='k';
            if(checkMove(x,y,x+1,y+1,arr)==1)
            {
                g=0;
            }
            arr[x][y]='.';
        }
        arr[x][y]='k';

        //bishop
        if(arr[place_white[2][0]][place_white[2][1]]=='b')
        {
            checkMove(place_white[2][0],place_white[2][1],x,y,arr);
            {
                if(possiblemovesh[0]!=0)
                {
                    g=0;
                }
            }
        }

        if(arr[place_white[5][0]][place_white[5][1]]=='b')
        {
            checkMove(place_white[5][0],place_white[5][1],x,y,arr);
            {
                if(possiblemovesh[0]!=0)
                {
                    g=0;
                }
            }
        }

        //ROCK
        if(arr[place_white[0][0]][place_white[0][1]]=='r')
        {
            checkMove(place_white[0][0],place_white[0][1],x,y,arr);
            {
                if(possiblemovesh[0]!=0)
                {
                    g=0;
                }
            }
        }

        if(arr[place_white[7][0]][place_white[5][1]]=='r')
        {
            checkMove(place_white[7][0],place_white[7][1],x,y,arr);
            {
                if(possiblemovesh[0]!=0)
                {
                    g=0;
                }

            }
        }

        //knight
        if(arr[place_white[1][0]][place_white[1][1]]=='n')
        {
            checkMove(place_white[1][0],place_white[1][1],x,y,arr);
            {
                if(possiblemovesh[0]!=0)
                {
                    g=0;
                }

            }
        }

        if(arr[place_white[6][0]][place_white[6][1]]=='n')
        {
            checkMove(place_white[6][0],place_white[6][1],x,y,arr);
            {
                if(possiblemovesh[0]!=0)
                {
                    g=0;
                }
            }
        }

        //queen
        if(arr[place_white[4][0]][place_white[4][1]]=='q')
        {
            checkMove(place_white[4][0],place_white[4][1],x,y,arr);
            {
                if(possiblemovesh[0]!=0)
                {
                    g=0;
                }
            }
        }

        //pawn
        int c;
        for(c=1; c<=8; c++)
        {
            if(arr[place_white[7+c][0]][place_white[7+c][1]]=='p'||arr[place_white[7+c][0]][place_white[7+c][1]]=='q'||arr[place_white[7+c][0]][place_white[7+c][1]]=='r'||arr[place_white[7+c][0]][place_white[7+c][1]]=='b'||arr[place_white[7+c][0]][place_white[7+c][1]]=='n')
            {
                checkMove(place_white[7+c][0],place_white[7+c][1],x,y,arr);
                {
                    if(possiblemovesh[0]!=0)
                    {
                        g=0;
                    }
                }
            }
        }



        arr[x][y]='k';
    }

    return g;
}
//x,y king place //arr board //place_black  black pieces place
int checkmate_black(int x,int y,char arr[10][10],int place_black[16][2])
{
    int g=0;
    int i;
    char piece;

    if(checked_black(x,y,arr)==1)
    {
        arr[x][y]='.';
        g=1;
        if(checked_black(x-1,y-1,arr)!=1)
        {
            arr[x][y]='K';
            if(checkMove(x,y,x-1,y-1,arr)==1)
            {
                g=0;
            }
            arr[x][y]='.';
        }
        if(checked_black(x,y-1,arr)!=1)
        {
            arr[x][y]='K';
            if(checkMove(x,y,x,y-1,arr)==1)
            {
                g=0;
            }
            arr[x][y]='.';
        }
        if(checked_black(x+1,y-1,arr)!=1)
        {
            arr[x][y]='K';
            if(checkMove(x,y,x+1,y-1,arr)==1)
            {
                g=0;
            }
            arr[x][y]='.';
        }
        if(checked_black(x,y+1,arr)!=1)
        {
            arr[x][y]='K';
            if(checkMove(x,y,x,y+1,arr)==1)
            {
                g=0;
            }
            arr[x][y]='.';
        }
        if(checked_black(x+1,y,arr)!=1)
        {
            arr[x][y]='K';
            if(checkMove(x,y,x+1,y,arr)==1)
            {
                g=0;
            }
            arr[x][y]='.';
        }
        if(checked_black(x-1,y,arr)!=1)
        {
            arr[x][y]='K';
            if(checkMove(x,y,x-1,y,arr)==1)
            {
                g=0;
            }
            arr[x][y]='.';
        }
        if(checked_black(x-1,y+1,arr)!=1)
        {
            arr[x][y]='K';
            if(checkMove(x,y,x-1,y+1,arr)==1)
            {
                g=0;
            }
            arr[x][y]='.';
        }
        if(checked_black(x+1,y+1,arr)!=1)
        {
            arr[x][y]='K';
            if(checkMove(x,y,x+1,y+1,arr)==1)
            {
                g=0;
            }
            arr[x][y]='.';
        }
        arr[x][y]='K';


        //bishop
        if(arr[place_black[2][0]][place_black[2][1]]=='B')
        {
            checkMove(place_black[2][0],place_black[2][1],x,y,arr);
            for(i=0; possiblemovesh[i]!=0; i++)
            {
                piece=arr[possiblemovesv[i]][possiblemovesh[i]];
                arr[place_black[2][0]][place_black[2][1]]=b[place_black[2][0]][place_black[2][1]];
                arr[possiblemovesv[i]][possiblemovesh[i]]='B';
                if(checked_black(x,y,arr)!=1)
                {
                    g=0;
                    arr[possiblemovesv[i]][possiblemovesh[i]]= piece;
                    arr[place_black[2][0]][place_black[2][1]]='B';
                    break;
                }
                arr[possiblemovesv[i]][possiblemovesh[i]]= piece;
                arr[place_black[2][0]][place_black[2][1]]='B';

            }
        }

        if(arr[place_black[5][0]][place_black[5][1]]=='B')
        {
            checkMove(place_black[5][0],place_black[5][1],x,y,arr);
            for(i=0; possiblemovesh[i]!=0; i++)
            {
                piece=arr[possiblemovesv[i]][possiblemovesh[i]];
                arr[place_black[5][0]][place_black[5][1]]=b[place_black[5][0]][place_black[5][1]];
                arr[possiblemovesv[i]][possiblemovesh[i]]='B';
                if(checked_black(x,y,arr)!=1)
                {
                    g=0;
                    arr[possiblemovesv[i]][possiblemovesh[i]]= piece;
                    arr[place_black[5][0]][place_black[5][1]]='B';
                    break;
                }
                arr[possiblemovesv[i]][possiblemovesh[i]]= piece;
                arr[place_black[5][0]][place_black[5][1]]='B';

            }
        }

        //ROCK
        if(arr[place_black[0][0]][place_black[0][1]]=='R')
        {
            checkMove(place_black[0][0],place_black[0][1],x,y,arr);
            for(i=0; possiblemovesh[i]!=0; i++)
            {
                piece=arr[possiblemovesv[i]][possiblemovesh[i]];
                arr[place_black[0][0]][place_black[0][1]]=b[place_black[0][0]][place_black[0][1]];
                arr[possiblemovesv[i]][possiblemovesh[i]]='R';
                if(checked_black(x,y,arr)!=1)
                {
                    g=0;
                    arr[possiblemovesv[i]][possiblemovesh[i]]= piece;
                    arr[place_black[0][0]][place_black[0][1]]='R';
                    break;
                }
                arr[possiblemovesv[i]][possiblemovesh[i]]= piece;
                arr[place_black[0][0]][place_black[0][1]]='R';

            }
        }

        if(arr[place_black[7][0]][place_black[5][1]]=='R')
        {
            checkMove(place_black[7][0],place_black[7][1],x,y,arr);
            for(i=0; possiblemovesh[i]!=0; i++)
            {
                piece=arr[possiblemovesv[i]][possiblemovesh[i]];
                arr[place_black[7][0]][place_black[7][1]]=b[place_black[7][0]][place_black[7][1]];
                arr[possiblemovesv[i]][possiblemovesh[i]]='R';
                if(checked_black(x,y,arr)!=1)
                {
                    g=0;
                    arr[possiblemovesv[i]][possiblemovesh[i]]= piece;
                    arr[place_black[7][0]][place_black[7][1]]='R';
                    break;
                }
                arr[possiblemovesv[i]][possiblemovesh[i]]= piece;
                arr[place_black[7][0]][place_black[7][1]]='R';

            }
        }

        //knight
        if(arr[place_black[1][0]][place_black[1][1]]=='N')
        {
            checkMove(place_black[1][0],place_black[1][1],x,y,arr);
            for(i=0; possiblemovesh[i]!=0; i++)
            {
                piece=arr[possiblemovesv[i]][possiblemovesh[i]];
                arr[place_black[1][0]][place_black[1][1]]=b[place_black[1][0]][place_black[1][1]];
                arr[possiblemovesv[i]][possiblemovesh[i]]='N';
                if(checked_black(x,y,arr)!=1)
                {
                    g=0;
                    arr[possiblemovesv[i]][possiblemovesh[i]]= piece;
                    arr[place_black[1][0]][place_black[1][1]]='N';
                    break;
                }
                arr[possiblemovesv[i]][possiblemovesh[i]]= piece;
                arr[place_black[1][0]][place_black[1][1]]='N';

            }
        }

        if(arr[place_black[6][0]][place_black[6][1]]=='N')
        {
            checkMove(place_black[6][0],place_black[6][1],x,y,arr);
            for(i=0; possiblemovesh[i]!=0; i++)
            {
                piece=arr[possiblemovesv[i]][possiblemovesh[i]];
                arr[place_black[6][0]][place_black[6][1]]=b[place_black[6][0]][place_black[6][1]];
                arr[possiblemovesv[i]][possiblemovesh[i]]='N';
                if(checked_black(x,y,arr)!=1)
                {
                    g=0;
                    arr[possiblemovesv[i]][possiblemovesh[i]]= piece;
                    arr[place_black[6][0]][place_black[6][1]]='N';
                    break;
                }
                arr[possiblemovesv[i]][possiblemovesh[i]]= piece;
                arr[place_black[6][0]][place_black[7][1]]='N';

            }
        }

        //queen
        if(arr[place_black[4][0]][place_black[4][1]]=='Q')
        {
            checkMove(place_black[4][0],place_black[4][1],x,y,arr);
            for(i=0; possiblemovesh[i]!=0; i++)
            {
                piece=arr[possiblemovesv[i]][possiblemovesh[i]];
                arr[place_black[4][0]][place_black[4][1]]=b[place_black[4][0]][place_black[4][1]];
                arr[possiblemovesv[i]][possiblemovesh[i]]='Q';
                if(checked_black(x,y,arr)!=1)
                {
                    g=0;
                    arr[possiblemovesv[i]][possiblemovesh[i]]= piece;
                    arr[place_black[4][0]][place_black[4][1]]='Q';
                    break;
                }
                arr[possiblemovesv[i]][possiblemovesh[i]]= piece;
                arr[place_black[4][0]][place_black[4][1]]='Q';

            }
        }

        //pawn
        int c;
        for(c=1; c<=8; c++)
        {
            if(arr[place_black[7+c][0]][place_black[7+c][1]]=='P'||arr[place_black[7+c][0]][place_black[7+c][1]]=='Q'||arr[place_black[7+c][0]][place_black[7+c][1]]=='R'||arr[place_black[7+c][0]][place_black[7+c][1]]=='B'||arr[place_black[7+c][0]][place_black[7+c][1]]=='N')
            {
                checkMove(place_black[7+c][0],place_black[7+c][1],x,y,arr);
                for(i=0; possiblemovesh[i]!=0; i++)
                {
                    piece=arr[possiblemovesv[i]][possiblemovesh[i]];
                    arr[place_black[7+c][0]][place_black[7+c][1]]=b[place_black[7+c][0]][place_black[7+c][1]];
                    arr[possiblemovesv[i]][possiblemovesh[i]]='P';
                    if(checked_black(x,y,arr)!=1)
                    {
                        g=0;
                        arr[possiblemovesv[i]][possiblemovesh[i]]= piece;
                        arr[place_black[7+c][0]][place_black[7+c][1]]='P';
                        break;
                    }
                    arr[possiblemovesv[i]][possiblemovesh[i]]= piece;
                    arr[place_black[7+c][0]][place_black[7+c][1]]='P';
                }
            }
        }
    }


    arr[x][y]='K';
    return g;
}
//x,y king place //arr board //place_black  black pieces place
int draw_black(int x,int y,char arr[10][10],int place_black[16][2])
{
    int g=0;
    int i;
    char piece;
    if(checked_black(x,y,arr)!=1)
    {
        arr[x][y]='.';
        g=1;
        if(checked_black(x-1,y-1,arr)!=1)
        {
            arr[x][y]='K';
            if(checkMove(x,y,x-1,y-1,arr)==1)
            {
                g=0;
            }
            arr[x][y]='.';
        }
        if(checked_black(x,y-1,arr)!=1)
        {
            arr[x][y]='K';
            if(checkMove(x,y,x,y-1,arr)==1)
            {
                g=0;
            }
            arr[x][y]='.';
        }
        if(checked_black(x+1,y-1,arr)!=1)
        {
            arr[x][y]='K';
            if(checkMove(x,y,x+1,y-1,arr)==1)
            {
                g=0;
            }
            arr[x][y]='.';
        }
        if(checked_black(x,y+1,arr)!=1)
        {
            arr[x][y]='K';
            if(checkMove(x,y,x,y+1,arr)==1)
            {
                g=0;
            }
            arr[x][y]='.';
        }
        else if(checked_black(x+1,y,arr)!=1)
        {
            arr[x][y]='K';
            if(checkMove(x,y,x+1,y,arr)==1)
            {
                g=0;
            }
            arr[x][y]='.';
        }
        if(checked_black(x-1,y,arr)!=1)
        {
            arr[x][y]='K';
            if(checkMove(x,y,x-1,y,arr)==1)
            {
                g=0;
            }
            arr[x][y]='.';
        }
        if(checked_black(x-1,y+1,arr)!=1)
        {
            arr[x][y]='K';
            if(checkMove(x,y,x-1,y+1,arr)==1)
            {
                g=0;
            }
            arr[x][y]='.';
        }
        if(checked_black(x+1,y+1,arr)!=1)
        {
            arr[x][y]='K';
            if(checkMove(x,y,x+1,y+1,arr)==1)
            {
                g=0;
            }
            arr[x][y]='.';
        }
        arr[x][y]='K';

        //bishop
        if(arr[place_black[2][0]][place_black[2][1]]=='B')
        {
            checkMove(place_black[2][0],place_black[2][1],x,y,arr);
            {
                if(possiblemovesh[0]!=0)
                {
                    g=0;
                }
            }
        }

        if(arr[place_black[5][0]][place_black[5][1]]=='B')
        {
            checkMove(place_black[5][0],place_black[5][1],x,y,arr);
            {
                if(possiblemovesh[0]!=0)
                {
                    g=0;
                }
            }
        }

        //ROCK
        if(arr[place_black[0][0]][place_black[0][1]]=='R')
        {
            checkMove(place_black[0][0],place_black[0][1],x,y,arr);
            {
                if(possiblemovesh[0]!=0)
                {
                    g=0;
                }
            }
        }

        if(arr[place_black[7][0]][place_black[5][1]]=='R')
        {
            checkMove(place_black[7][0],place_black[7][1],x,y,arr);
            {
                if(possiblemovesh[0]!=0)
                {
                    g=0;
                }

            }
        }

        //knight
        if(arr[place_black[1][0]][place_black[1][1]]=='N')
        {
            checkMove(place_black[1][0],place_black[1][1],x,y,arr);
            {
                if(possiblemovesh[0]!=0)
                {
                    g=0;
                }

            }
        }

        if(arr[place_black[6][0]][place_black[6][1]]=='N')
        {
            checkMove(place_black[6][0],place_black[6][1],x,y,arr);
            {
                if(possiblemovesh[0]!=0)
                {
                    g=0;
                }
            }
        }

        //queen
        if(arr[place_black[4][0]][place_black[4][1]]=='Q')
        {
            checkMove(place_black[4][0],place_black[4][1],x,y,arr);
            {
                if(possiblemovesh[0]!=0)
                {
                    g=0;
                }
            }
        }

        //pawn
        int c;
        for(c=1; c<=8; c++)
        {
            if(arr[place_black[7+c][0]][place_black[7+c][1]]=='P'||arr[place_black[7+c][0]][place_black[7+c][1]]=='Q'||arr[place_black[7+c][0]][place_black[7+c][1]]=='R'||arr[place_black[7+c][0]][place_black[7+c][1]]=='B'||arr[place_black[7+c][0]][place_black[7+c][1]]=='N')
            {
                checkMove(place_black[7+c][0],place_black[7+c][1],x,y,arr);
                {
                    if(possiblemovesh[0]!=0)
                    {
                        g=0;
                    }
                }
            }
        }



        arr[x][y]='K';
    }

    return g;
}

int main()
{
    system("COLOR F0");
    int redo=0;
    int undo=1;
    char ubo[300][10][10];
    char upw[300][16][2];
    char upb[300][16][2];
    char ulw[300][15];
    ulw[0][15]="000000000000000";
    char ulb[300][15];
    ulb[0][15]="000000000000000";
    int uco[300];
    uco[0]='\0';
    int ucoco[300];
    ucoco[0]='\0';
    int r,c;
    int co=0,coco=0;
    int k1,k2,k3,k4,k6,k7,c8,i8,lm;
    int a8[3]= {0,0,0};
    char c22='*';
    char lettres[10]=" ABCDEFGH ";
    char num[10]=" 12345678 ";
    char white1[9]=" rnbkqbnr";
    char black1[9]=" RNBKQBNR";
    char white2[9]=" pppppppp";
    char black2[9]=" PPPPPPPP";
    char a[10][10];
    int i=0;
    int g=0;
    int f=0;
    int place_white[16][2]= {1,1,1,2,1,3,1,4,1,5,1,6,1,7,1,8,2,1,2,2,2,3,2,4,2,5,2,6,2,7,2,8};
    int place_black[16][2]= {8,1,8,2,8,3,8,4,8,5,8,6,8,7,8,8,7,1,7,2,7,3,7,4,7,5,7,6,7,7,7,8};
    char lost_black[15]="\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    char lost_white[15]="\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";


    //board
    {
        for(r=0; r<10; r++)
        {
            for(c=0; c<10; c++)
            {
                if(r==0||r==9)
                    a[r][c]=lettres[c];
                else if(c==0||c==9)
                    a[r][c]=num[r];
                else if(r==1&&c!=0)
                    a[r][c]=white1[c];
                else if(r==2&&c!=0)
                    a[r][c]=white2[c];
                else if(r==7&&c!=0)
                    a[r][c]=black2[c];
                else if(r==8&&c!=0)
                    a[r][c]=black1[c];
                else if(r%2!=0 && c%2!=0 && r!=0 && r!=9 && c!=0 && c!=9 && r!=8 && r!=7 && r!=1 && r!=2)
                    a[r][c]='.';
                else if(r%2==0&&c%2==0&&r!=0&&r!=9&&c!=0&&c!=9&&r!=8&&r!=7&&r!=1&&r!=2)
                    a[r][c]='.';
                else
                    a[r][c]='-';
            }
        }
    }

    for(r=0; r<10; r++)
    {
        for(c=0; c<10; c++)
        {
            ubo[0][r][c]=a[r][c];
        }
    }
    for(r=0; r<16; r++)
    {
        for(c=0; c<2; c++)
        {
            upw[0][r][c]=place_white[r][c];
            upb[0][r][c]=place_black[r][c];
        }
    }

    printf("Welcome!!\nTo start a new game press (N) and to load saved one press (L).\nYou should enter your move as string of 4 characters:\nthe first two are the place of your piece and the other two are the place you    want to move to.\nIn case of promotion enter your promotion piece as 5th character.\nExcept this your string will be denied.\nTO undo your move press (U) and to redo it press (R).\nHave a nice game :D\n\n");

    //load
    {
        int n22=0;
        char c12;
        char c11[2];
        int z1,z2,z5;
        while(n22!=1)
        {
            printf("if you want to start new game press (N) or load press (L) : ");
            scanf("%s",&c11);
            if(c11[0]=='L'&&c11[1]=='\0')
            {
                save =fopen("save.txt","r");
                if (save == NULL)
                {
                    printf("Error! Could not find the file\n");
                }
                else
                {

                    z2=0,z1=0,z5=1,k1=0,k2=0,k3=0,k4=0,k6=0,k7=0,c8=0,lm=0,i8=0;
                    while ((c12 = fgetc(save)) != EOF)
                    {
                        if(c12!= '\n'&&c8==0)
                        {
                            a8[i8]=c12-'0';
                            i8++;
                            lm++;
                        }
                        else if(c12== '\n'&&c8==0)
                        {
                            if(lm==1)
                            {
                                co=a8[0];
                            }
                            else
                            {
                                co=a8[0]*10+a8[1];
                            }
                            lm=0;
                            c8++;
                            i8=0;
                            a8[0]=0;
                            a8[1]=0;
                        }

                        else if(c12!= '\n'&&c8==1)
                        {
                            a8[i8]=c12-'0';
                            i8++;
                            lm++;
                        }
                        else if(c12== '\n'&&c8==1)
                        {
                            if(lm==1)
                            {
                                coco=a8[0];
                            }
                            else
                            {
                                coco=a8[0]*10+a8[1];
                            }
                            lm=0;
                            c8++;
                            i8=0;
                            a8[0]=0;
                            a8[1]=0;
                            a8[2]=0;
                        }

                        else if(c12!= '\n'&&c8==2)
                        {
                            a8[i8]=c12-'0';
                            i8++;
                            lm++;
                        }
                        else if(c12== '\n'&&c8==2)
                        {
                            if(lm==1)
                            {
                                g=a8[0];
                            }
                            else if(lm==2)
                            {
                                g=a8[0]*10+a8[1];
                            }
                            else
                            {
                                g=a8[0]*100+a8[1]*10+a8[2];
                            }

                            lm=0;
                            c8++;
                        }
                        else if(z5>0&&z5<=32)
                        {
                            char y15=c12;
                            z5++;
                            place_white[k1][k2]=y15-'0';
                            k2++;
                            if(k2==2)
                            {
                                k1++;
                                k2=0;
                            }

                        }
                        else if(z5>32&&z5<=64)
                        {

                            char y15=c12;
                            z5++;
                            place_black[k3][k4]=y15-'0';
                            k4++;
                            if(k4==2)
                            {
                                k3++;
                                k4=0;
                            }

                        }
                        else if(z5>64&&z5<=164)
                        {
                            a[z1][z2] = c12;
                            z2++;
                            z5++;
                            if(z2==10)
                            {
                                z2=0;
                                z1++;
                            }
                        }
                        else if(z5>164&&z5<=179)
                        {
                            lost_white[k6]= c12;
                            k6++;
                            z5++;
                        }
                        else if(z5>179&&z5<=194)
                        {
                            lost_black[k7]= c12;
                            z5++;
                            k7++;
                        }
                    }
                }
                fclose(save);
                n22=1;
            }
            else if(c11[0]=='N'&&c11[1]=='\0')
            {
                n22=1;
            }
            else
                printf("Error !!\n");
            scanf("%c",&c11);
        }
    }

    //print board
    {
        printf("Lost white: ");
        for(r=0; r<co; r++)
        {
            printf("%c ",lost_white[r]);
        }
        printf("\n\n");
        for(r=0; r<10; r++)
        {
            for(c=0; c<10; c++)
            {
                printf("%c  ",a[r][c]);
            }
            printf("\n\n");
        }
        printf("Lost black: ");
        for(r=0; r<coco; r++)
        {
            printf("%c ",lost_black[r]);
        }
        printf("\n");
    }
    //empty board
    {
        for(r=0; r<10; r++)
        {
            for(c=0; c<10; c++)
            {
                if(r==0||r==9)
                    b[r][c]=lettres[c];
                else if(c==0||c==9)
                    b[r][c]=num[r];
                else if(r%2!=0 && c%2!=0 && r!=0 && r!=9)
                    b[r][c]='.';
                else if(r%2==0&&c%2==0&&r!=0&&r!=9)
                    b[r][c]='.';
                else
                    b[r][c]='-';
            }
        }
    }

    /**************************************************************************************/

    /*Main loop*/
    char moves[5]="00000";
    int xyz=0;
    while(xyz==0)
    {
        f=g;
        while(1)
        {

            f=g;
            f++;
            int count;

            //Turn
            if(f%2==0)
                printf("\nBlack's turn:");
            else if(f%2!=0)
                printf("\nWhite's turn:");

            //Input
            scanf("%s",&moves);
            printf("\n");


            if(moves[0]=='U'&&moves[1]=='\0')
            {
                c22='U';
            }

            //undo
            if(c22=='U')
            {
                if(undo>1)
                {
                    redo++;
                    undo=undo-2;
                    for(k1=0; k1<10; k1++)
                    {
                        for(k2=0; k2<10; k2++)
                        {
                            a[k1][k2]=ubo[undo][k1][k2];
                        }
                    }
                    for(k1=0; k1<16; k1++)
                    {
                        for(k2=0; k2<2; k2++)
                        {
                            place_white[k1][k2]=upw[undo][k1][k2];
                        }
                    }
                    for(k1=0; k1<16; k1++)
                    {
                        for(k2=0; k2<2; k2++)
                        {
                            place_black[k1][k2]=upb[undo][k1][k2];
                        }
                    }
                    for(k1=0; k1<15; k1++)
                    {
                        lost_white[k1]=ulw[undo][k1];
                    }
                    for(k1=0; k1<15; k1++)
                    {
                        lost_black[k1]=ulb[undo][k1];
                    }
                    undo++;
                    co=uco[undo];
                    coco=ucoco[undo];
                    g=g-1;
                    c22='\0';

                    //save
                    {
                        save = fopen("save.txt","w");
                        fprintf(save,"%d",co);
                        fprintf(save,"\n");
                        fprintf(save,"%d",coco);
                        fprintf(save,"\n");
                        fprintf(save,"%d",g);
                        fprintf(save,"\n");
                        for(k1=0; k1<16; k1++)
                        {
                            for(k2=0; k2<2; k2++)
                            {
                                fprintf(save,"%d",place_white[k1][k2]);
                            }
                        }
                        for(k1=0; k1<16; k1++)
                        {
                            for(k2=0; k2<2; k2++)
                            {
                                fprintf(save,"%d",place_black[k1][k2]);
                            }
                        }
                        for(k1=0; k1<10; k1++)
                        {
                            for(k2=0; k2<10; k2++)
                            {
                                fprintf(save,"%c",a[k1][k2]);
                            }
                        }
                        for(k1=0; k1<15; k1++)
                        {
                            fprintf(save,"%c",lost_white[k1]);
                        }
                        for(k1=0; k1<15; k1++)
                        {
                            fprintf(save,"%c",lost_black[k1]);
                        }
                        fclose(save);
                    }

                    //PRINT BOARD
                    {
                        printf("Lost white: ");
                        for(r=0; r<co; r++)
                        {
                            printf("%c ",lost_white[r]);
                        }
                        printf("\n\n");
                        for(r=0; r<10; r++)
                        {
                            for(c=0; c<10; c++)
                            {
                                printf("%c  ",a[r][c]);
                            }
                            printf("\n\n");
                        }
                        printf("Lost black: ");
                        for(r=0; r<coco; r++)
                        {
                            printf("%c ",lost_black[r]);
                        }
                        printf("\n");
                    }
                    g--;
                    break;
                }

                else if(undo==1)
                {
                    printf("NO saved game.\n");
                    c22='\0';
                    g++;
                    break;
                }
            }

            if(moves[0]=='R'&&moves[1]=='\0')
            {
                c22='R';
            }

            //redo
            if(c22=='R')
            {
                if(redo>0)
                {
                    redo--;
                    for(k1=0; k1<10; k1++)
                    {
                        for(k2=0; k2<10; k2++)
                        {
                            a[k1][k2]=ubo[undo][k1][k2];
                        }
                    }
                    for(k1=0; k1<16; k1++)
                    {
                        for(k2=0; k2<2; k2++)
                        {
                            place_white[k1][k2]=upw[undo][k1][k2];
                        }
                    }
                    for(k1=0; k1<16; k1++)
                    {
                        for(k2=0; k2<2; k2++)
                        {
                            place_black[k1][k2]=upb[undo][k1][k2];
                        }
                    }
                    for(k1=0; k1<15; k1++)
                    {
                        lost_white[k1]=ulw[undo][k1];
                    }
                    for(k1=0; k1<15; k1++)
                    {
                        lost_black[k1]=ulb[undo][k1];
                    }
                    co=uco[undo];
                    coco=ucoco[undo];
                    undo++;
                    g++;
                    c22='\0';

                    //save
                    {
                        save = fopen("save.txt","w");
                        fprintf(save,"%d",co);
                        fprintf(save,"\n");
                        fprintf(save,"%d",coco);
                        fprintf(save,"\n");
                        fprintf(save,"%d",g);
                        fprintf(save,"\n");
                        for(k1=0; k1<16; k1++)
                        {
                            for(k2=0; k2<2; k2++)
                            {
                                fprintf(save,"%d",place_white[k1][k2]);
                            }
                        }
                        for(k1=0; k1<16; k1++)
                        {
                            for(k2=0; k2<2; k2++)
                            {
                                fprintf(save,"%d",place_black[k1][k2]);
                            }
                        }
                        for(k1=0; k1<10; k1++)
                        {
                            for(k2=0; k2<10; k2++)
                            {
                                fprintf(save,"%c",a[k1][k2]);
                            }
                        }
                        for(k1=0; k1<15; k1++)
                        {
                            fprintf(save,"%c",lost_white[k1]);
                        }
                        for(k1=0; k1<15; k1++)
                        {
                            fprintf(save,"%c",lost_black[k1]);
                        }
                        fclose(save);
                    }
                    g--;

                    //PRINT BOARD
                    {
                        printf("Lost white: ");
                        for(r=0; r<co; r++)
                        {
                            printf("%c ",lost_white[r]);
                        }
                        printf("\n\n");
                        for(r=0; r<10; r++)
                        {
                            for(c=0; c<10; c++)
                            {
                                printf("%c  ",a[r][c]);
                            }
                            printf("\n\n");
                        }
                        printf("Lost black: ");
                        for(r=0; r<coco; r++)
                        {
                            printf("%c ",lost_black[r]);
                        }
                        printf("\n");
                    }
                    break;
                }

                else if(undo==1)
                {
                    printf("NO saved game.\n");
                    c22='\0';
                    g++;
                    break;
                }
                else
                   {
                       printf("You can't redo because there is no previous undo.\n");
                   }
            }
            redo=0;

            //validation of string
            {
                for(count=0; count<8; count++)
                {
                    if(moves[1]==num[count+1])
                        break;
                    else if(count==7)
                        printf("Enter valid String.");
                }
                if(count==8)
                {
                    g=g-1;
                    break;
                }
                for(count=0; count<8; count++)
                {
                    if(moves[3]==num[count+1])
                        break;
                    else if(count==7)
                        printf("Enter valid String.");
                }
                if(count==8)
                {
                    g=g-1;
                    break;
                }

                for(count=0; count<8; count++)
                {
                    if(moves[0]==lettres[count+1])
                        break;
                    else if(count==7)
                        printf("Enter valid String.");
                }
                if(count==8)
                {
                    g=g-1;
                    break;
                }

                for(count=0; count<8; count++)
                {
                    if(moves[2]==lettres[count+1])
                        break;
                    else if(count==7)
                        printf("Enter valid String.");
                }
                if(count==8)
                {
                    g=g-1;
                    break;
                }
            }
            //translation
            {
                for(i=1; i<9; i++)
                {
                    if(moves[0]==lettres[i])
                        moves[0]=num[i];
                    if(moves[2]==lettres[i])
                        moves[2]=num[i];
                }
            }
            //his piece or not or empty place
            {
                if(a[(int)moves[1]-'0'][(int)moves[0]-'0']=='.' || a[(int)moves[1]-'0'][(int)moves[0]-'0']=='-')
                {
                    printf("This square is empty.Enter valid one.");
                    g=g-1;
                    break;
                }
                else if(((int)moves[1]-'0')==((int)moves[3]-'0')&&((int)moves[0]-'0')==((int)moves[2]-'0'))
                {
                    printf("This is the same square.Enter valid move.");
                    g=g-1;
                    break;
                }

                if(f%2==0)
                {
                    if(a[(int)moves[1]-'0'][(int)moves[0]-'0']=='k'||a[(int)moves[1]-'0'][(int)moves[0]-'0']=='q'||a[(int)moves[1]-'0'][(int)moves[0]-'0']=='r'||a[(int)moves[1]-'0'][(int)moves[0]-'0']=='b'||a[(int)moves[1]-'0'][(int)moves[0]-'0']=='n'||a[(int)moves[1]-'0'][(int)moves[0]-'0']=='p')
                    {
                        printf("This is not your piece.Enter valid move.");
                        g=g-1;
                        break;
                    }
                }
                else
                {
                    if(a[(int)moves[1]-'0'][(int)moves[0]-'0']=='K'||a[(int)moves[1]-'0'][(int)moves[0]-'0']=='Q'||a[(int)moves[1]-'0'][(int)moves[0]-'0']=='R'||a[(int)moves[1]-'0'][(int)moves[0]-'0']=='B'||a[(int)moves[1]-'0'][(int)moves[0]-'0']=='N'||a[(int)moves[1]-'0'][(int)moves[0]-'0']=='P')
                    {
                        printf("This is not your piece.Enter valid move.");
                        g=g-1;
                        break;
                    }
                }
            }
            //possible move or not
            {
                if((checkMove((int)moves[1]-'0',(int)moves[0]-'0',(int)moves[3]-'0',(int)moves[2]-'0',a)==1));
                else
                {
                    printf("Invalid move.");
                    g=g-1;
                    break;
                }
            }
            //promotion
            {
                if((promotion((int)moves[3]-'0',(int)moves[2]-'0',(int)moves[1]-'0',(int)moves[0]-'0',a,moves)==1)&&moves[5]=='\0')
                {
                    printf("Valid promotion.");
                    a[(int)moves[1]-'0'][(int)moves[0]-'0']=moves[4];
//                    a[(int)moves[3]-'0'][(int)moves[2]-'0']=a[(int)moves[1]-'0'][(int)moves[0]-'0'];

                }
                else if(moves[4]!='\0')
                {
                    printf("Invalid promotion.\n");
                    g=g-1;
                    break;
                }
                else if (moves[4]=='\0'&&(a[(int)moves[1]-'0'][(int)moves[0]-'0']=='p'||a[(int)moves[1]-'0'][(int)moves[0]-'0']=='P')&&((int)moves[3]-'0'==8||(int)moves[3]-'0'==1))
                {
                    printf("Enter your prom. piece.");
                    g=g-1;
                    break;
                }
            }

            //lost piece(if valid move we will use it)
            char piece=a[(int)moves[3]-'0'][(int)moves[2]-'0'];

            //place king //0 X //1 Y
            {
                if(a[(int)moves[1]-'0'][(int)moves[0]-'0']=='k'||a[(int)moves[1]-'0'][(int)moves[0]-'0']=='K')
                {
                    if(a[(int)moves[1]-'0'][(int)moves[0]-'0']=='k')
                    {
                        place_white[3][0]=(int)moves[3]-'0';
                        place_white[3][1]=(int)moves[2]-'0';
                    }
                    else
                    {
                        place_black[3][0]=(int)moves[3]-'0';
                        place_black[3][1]=(int)moves[2]-'0';
                    }
                }
            }
            //Move
            {
                a[(int)moves[3]-'0'][(int)moves[2]-'0']=a[(int)moves[1]-'0'][(int)moves[0]-'0'];
                a[(int)moves[1]-'0'][(int)moves[0]-'0']=b[(int)moves[1]-'0'][(int)moves[0]-'0'];
            }
            //check
            {
                if((checked_white(place_white[3][0],place_white[3][1],a)==1))
                {
                    if(a[(int)moves[3]-'0'][(int)moves[2]-'0']=='k')
                    {
                        printf("King can't move there.");
                        a[(int)moves[1]-'0'][(int)moves[0]-'0']=a[(int)moves[3]-'0'][(int)moves[2]-'0'];
                        a[(int)moves[3]-'0'][(int)moves[2]-'0']=piece;
                        place_white[3][0]=(int)moves[1]-'0';
                        place_white[3][1]=(int)moves[0]-'0';
                        g=g-1;
                        break;
                    }
                    else if((checked_white(place_white[3][0],place_white[3][1],a)==1)&&f%2!=0)
                    {
                        printf("king shouldn't be checked. ");
                        a[(int)moves[1]-'0'][(int)moves[0]-'0']=a[(int)moves[3]-'0'][(int)moves[2]-'0'];
                        a[(int)moves[3]-'0'][(int)moves[2]-'0']=piece;
                        g=g-1;
                        break;
                    }
                    else
                        printf("\nCheck\n\n");
                }

                if((checked_black(place_black[3][0],place_black[3][1],a)==1))
                {
                    if(a[(int)moves[3]-'0'][(int)moves[2]-'0']=='K')
                    {
                        printf("King can't move there.");
                        a[(int)moves[1]-'0'][(int)moves[0]-'0']=a[(int)moves[3]-'0'][(int)moves[2]-'0'];
                        a[(int)moves[3]-'0'][(int)moves[2]-'0']=piece;
                        place_black[3][0]=(int)moves[1]-'0';
                        place_black[3][1]=(int)moves[0]-'0';
                        g=g-1;
                        break;
                    }
                    else if((checked_black(place_black[3][0],place_black[3][1],a)==1)&&f%2==0)
                    {
                        printf("king shouldn't be checked. ");
                        a[(int)moves[1]-'0'][(int)moves[0]-'0']=a[(int)moves[3]-'0'][(int)moves[2]-'0'];
                        a[(int)moves[3]-'0'][(int)moves[2]-'0']=piece;
                        g=g-1;
                        break;
                    }
                    else
                        printf("\nCheck\n\n");
                }
            }
            //PLACE PIECES
            {
                if(a[(int)moves[3]-'0'][(int)moves[2]-'0']=='r')
                {
                    if((int)moves[1]-'0'==place_white[0][0]&&(int)moves[0]-'0'==place_white[0][1])
                    {
                        place_white[0][0]=(int)moves[3]-'0';
                        place_white[0][1]=(int)moves[2]-'0';
                    }
                    else
                    {
                        place_white[7][0]=(int)moves[3]-'0';
                        place_white[7][1]=(int)moves[2]-'0';
                    }
                }
                else if(a[(int)moves[3]-'0'][(int)moves[2]-'0']=='R')
                {
                    if((int)moves[1]-'0'==place_black[0][0]&&(int)moves[0]-'0'==place_black[0][1])
                    {
                        place_black[0][0]=(int)moves[3]-'0';
                        place_black[0][1]=(int)moves[2]-'0';
                    }
                    else
                    {
                        place_black[7][0]=(int)moves[3]-'0';
                        place_black[7][1]=(int)moves[2]-'0';
                    }
                }


                else if(a[(int)moves[3]-'0'][(int)moves[2]-'0']=='n')
                {
                    if((int)moves[1]-'0'==place_white[1][0]&&(int)moves[0]-'0'==place_white[1][1])
                    {
                        place_white[1][0]=(int)moves[3]-'0';
                        place_white[1][1]=(int)moves[2]-'0';
                    }
                    else
                    {
                        place_white[6][0]=(int)moves[3]-'0';
                        place_white[6][1]=(int)moves[2]-'0';
                    }
                }
                else if(a[(int)moves[3]-'0'][(int)moves[2]-'0']=='N')
                {
                    if((int)moves[1]-'0'==place_black[1][0]&&(int)moves[0]-'0'==place_black[1][1])
                    {
                        place_black[1][0]=(int)moves[3]-'0';
                        place_black[1][1]=(int)moves[2]-'0';
                    }
                    else
                    {
                        place_black[6][0]=(int)moves[3]-'0';
                        place_black[6][1]=(int)moves[2]-'0';
                    }
                }

                else if(a[(int)moves[3]-'0'][(int)moves[2]-'0']=='b')
                {
                    if((int)moves[1]-'0'==place_white[2][0]&&(int)moves[0]-'0'==place_white[2][1])
                    {
                        place_white[2][0]=(int)moves[3]-'0';
                        place_white[2][1]=(int)moves[2]-'0';
                    }
                    else
                    {
                        place_white[5][0]=(int)moves[3]-'0';
                        place_white[5][1]=(int)moves[2]-'0';
                    }
                }
                else if(a[(int)moves[3]-'0'][(int)moves[2]-'0']=='R')
                {
                    if((int)moves[1]-'0'==place_black[2][0]&&(int)moves[0]-'0'==place_black[2][1])
                    {
                        place_black[2][0]=(int)moves[3]-'0';
                        place_black[2][1]=(int)moves[2]-'0';
                    }
                    else
                    {
                        place_black[5][0]=(int)moves[3]-'0';
                        place_black[5][1]=(int)moves[2]-'0';
                    }
                }

                else if(a[(int)moves[3]-'0'][(int)moves[2]-'0']=='q')
                {
                    if((int)moves[1]-'0'==place_white[4][0]&&(int)moves[0]-'0'==place_white[4][1])
                    {
                        place_white[4][0]=(int)moves[3]-'0';
                        place_white[4][1]=(int)moves[2]-'0';
                    }
                }
                else if(a[(int)moves[3]-'0'][(int)moves[2]-'0']=='Q')
                {
                    if((int)moves[1]-'0'==place_black[4][0]&&(int)moves[0]-'0'==place_black[4][1])
                    {
                        place_black[4][0]=(int)moves[3]-'0';
                        place_black[4][1]=(int)moves[2]-'0';
                    }
                }
                else if(a[(int)moves[3]-'0'][(int)moves[2]-'0']=='p')
                {
                    int cc;
                    for(cc=1; cc<=8; cc++)
                    {
                        if((int)moves[1]-'0'==place_white[7+cc][0]&&(int)moves[0]-'0'==place_white[7+cc][1])
                        {
                            place_white[7+cc][0]=(int)moves[3]-'0';
                            place_white[7+cc][1]=(int)moves[2]-'0';
                        }
                    }
                }
                else if(a[(int)moves[3]-'0'][(int)moves[2]-'0']=='P')
                {
                    int cc;
                    for(cc=1; cc<=8; cc++)
                    {
                        if((int)moves[1]-'0'==place_black[7+cc][0]&&(int)moves[0]-'0'==place_black[7+cc][1])
                        {
                            place_black[7+cc][0]=(int)moves[3]-'0';
                            place_black[7+cc][1]=(int)moves[2]-'0';
                        }
                    }
                }
            }
            //Check mate
            {
                if (checkmate_white(place_white[3][0],place_white[3][1],a,place_white)==1)
                {
                    printf("Checkmate.\n Black wins.\n");
                    xyz=1;
                    break;
                }
                if (checkmate_black(place_black[3][0],place_black[3][1],a,place_black)==1)
                {
                    printf("Checkmate.\nWhite wins.\n");
                    xyz=1;
                    break;
                }
            }
            //draw
            {
                if (draw_white(place_white[3][0],place_white[3][1],a,place_white)==1&&f%2!=0)
                {
                    printf("Draw\n");
                    xyz=1;
                    break;
                }
                if (draw_black(place_black[3][0],place_black[3][1],a,place_black)==1&&f%2==0)
                {
                    printf("Draw\n");
                    xyz=1;
                    break;
                }
            }

            //lost piece
            {
                if(f%2==0&&(piece=='r'||piece=='q'||piece=='n'||piece=='p'||piece=='b'))
                {
                    lost_white[co]=piece;
                    co++;
                }
                else if(f%2!=0&&(piece=='R'||piece=='Q'||piece=='N'||piece=='P'||piece=='B'))
                {
                    lost_black[coco]=piece;
                    coco++;
                }
            }

            //PRINT BOARD
            {
                printf("Lost white: ");
                for(r=0; r<co; r++)
                {
                    printf("%c ",lost_white[r]);
                }
                printf("\n\n");
                for(r=0; r<10; r++)
                {
                    for(c=0; c<10; c++)
                    {
                        printf("%c  ",a[r][c]);
                    }
                    printf("\n\n");
                }
                printf("Lost black: ");
                for(r=0; r<coco; r++)
                {
                    printf("%c ",lost_black[r]);
                }
                printf("\n");
            }

            //saving each move to use in undo
            {
                for(k1=0; k1<10; k1++)
                {
                    for(k2=0; k2<10; k2++)
                    {
                        ubo[undo][k1][k2]=a[k1][k2];
                    }
                }
                for(k1=0; k1<16; k1++)
                {
                    for(k2=0; k2<2; k2++)
                    {
                        upw[undo][k1][k2]=place_white[k1][k2];
                    }
                }
                for(k1=0; k1<16; k1++)
                {
                    for(k2=0; k2<2; k2++)
                    {
                        upb[undo][k1][k2]=place_black[k1][k2];
                    }
                }
                for(k1=0; k1<15; k1++)
                {
                    ulw[undo][k1]=lost_white[k1];
                }
                for(k1=0; k1<15; k1++)
                {
                    ulb[undo][k1]=lost_black[k1];
                }
                uco[undo]=co;
                ucoco[undo]=coco;
                undo++;

            }


            g++;
            //save
            {
                save = fopen("save.txt","w");
                fprintf(save,"%d",co);
                fprintf(save,"\n");
                fprintf(save,"%d",coco);
                fprintf(save,"\n");
                fprintf(save,"%d",g);
                fprintf(save,"\n");
                for(k1=0; k1<16; k1++)
                {
                    for(k2=0; k2<2; k2++)
                    {
                        fprintf(save,"%d",place_white[k1][k2]);
                    }
                }
                for(k1=0; k1<16; k1++)
                {
                    for(k2=0; k2<2; k2++)
                    {
                        fprintf(save,"%d",place_black[k1][k2]);
                    }
                }
                for(k1=0; k1<10; k1++)
                {
                    for(k2=0; k2<10; k2++)
                    {
                        fprintf(save,"%c",a[k1][k2]);
                    }
                }
                for(k1=0; k1<15; k1++)
                {
                    fprintf(save,"%c",lost_white[k1]);
                }
                for(k1=0; k1<15; k1++)
                {
                    fprintf(save,"%c",lost_black[k1]);
                }
                fclose(save);
            }


        }
        g++;
    }



    return 0;
}
