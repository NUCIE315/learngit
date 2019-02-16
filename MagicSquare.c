#include <stdio.h>
#include <stdlib.h>
#define N 100

void OddMagicSquare(int ms[][N],int n,int beginl,int beginr,int start,int end);
void OddEvenMagicSquare(int ms[][N],int n);
void CDJ4(int beginl, int beginr, int a[][N],int n);
void HCDJ(int beginl, int beginr, int a[][N],int n);
void Swap(int *a,int *b);
void DoubleEvenMagicSquare(int ms[][N],int n);
int main()
{
    int n = 0,i = 0, j = 0;
    int a[N][N] = {{0}};

    printf("输入幻方的阶数：");
    scanf("%d",&n);

    if(n%2 != 0)
        OddMagicSquare(a,n,0,0,1,n*n);
    else if(n % 4 != 0)
        OddEvenMagicSquare(a,n);
    else
        DoubleEvenMagicSquare(a,n);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            printf("%3d ",a[i][j]);
        printf("\n\n");
    }

    return 0;
}
/*
*Name: 奇幻方的打印
*Version: 1.1（修改了第一个j；）
*Inputs:要打印的幻方：a[N][N];奇幻方的阶数：n;从第几行和第几列开始：beginl, beginr;
*       第一个元素的数字：start；最后一个元素的值:end;
*Author:LiuNing
*Time:2019.2.13
*
*/
void OddMagicSquare(int ms[][N],int n,int beginl,int beginr,int start,int end)
{
    int i = beginl, j = beginr,c = start + 1,lastr = 0;
    /*改*/    lastr = beginr + n;
    /*改*/  j = (beginr + lastr)/2;//中间的一位是最后一个与第一个的和除以2：v 1.1改正
    ms[i][j] = start;


    while(c <= end)
    {
        if(i <= beginl)
            i = beginl + n -1;
        else
            i--;
        if(j >= beginr+n - 1)
            j = beginr;
        else
            j++;

        if(ms[i][j] != 0&&i !=beginl + n-1 &&j !=beginr)
        {
            i=i+2;
            j--;
        }
        else if(ms[i][j] != 0&&i == beginl+n-1&&j != beginr)
        {
            i = beginl + 1;
            j--;
        }
        else if(ms[i][j] != 0&&i != beginl+n-1&& j == beginr)
        {
            i = i+2;
            j = beginr +n - 1;
        }
        else if(ms[i][j] !=0 &&i == beginl+n - 1 && j==beginr)
        {
            i = beginl + 1;
            j = beginr+ n - 1;
        }

        ms[i][j] = c;
        c++;
    }

    /*for(i = beginl;i < beginl+n;i++)
    {
        for(j = beginr;j < n;j++)
            printf("%2d ",ms[i][j]);
        printf("\n");
    }*/
}
/*
 *Name:单偶幻方的打印
 *Version:0.0
 *Inputs:要打印的幻方ms，幻方的阶数n；
 *Author:LiuNing
 *Time:2019.2.16
 */
void OddEvenMagicSquare(int ms[][N],int n)
{
    int m = 0,sm = 0,n0 = 0;

    //分解为四个奇幻方
    n0 = n;
    m = n/4;
    n = 2*m + 1;
    sm = n * n;

    //填充每个奇幻方
    OddMagicSquare(ms,n,0,0,1,sm);
    OddMagicSquare(ms,n,n,n,sm + 1,2*sm);
    OddMagicSquare(ms,n,0,n,2*sm + 1, 3*sm);
    OddMagicSquare(ms,n,n,0,3*sm + 1, 4*sm);
}
/*
 *Name:CDJ4:（4维幻方关于总幻方中心对角线对称）包括主副对角线
 *Input: beginl：幻方的起始行，beginr：幻方的起始列，a：幻方，n：幻方的阶数
 *Version:0.0
 *Author:LiuNing
 *Time:2018.2.15
 */
void CDJ4(int beginl, int beginr,int a[][N],int n)
{
    int i = 0,j = 0, p = 0, q = 0;

    for(i = beginl,j = beginr; i - beginl < 4 && j - beginr < 4; i++,j++)
    {
        p = n - i - 1;
        q = n - j - 1;
        Swap(&a[i][j],&a[p][q]);
    }
    for(i = beginl + 3,j = beginr; i >= beginl&& j - beginr < 4; i--,j++)
    {
        p = n - i - 1;
        q = n - j - 1;
        Swap(&a[i][j],&a[p][q]);
    }
}
/*
 *Name:HCDJ(关于自身半对称）
 *Input: beginl,beginr ：数组的行与列，a：幻方，n：幻方的阶数
 *Version: 0.0
 *Author:LiuNing
 *Time:2019.2.15
 */
void HCDJ(int beginl, int beginr,int a[][N],int n)
{
    int i = 0,j = 0, p = 0, q = 0;

    for(i = beginl,j = beginr; i - beginl < n/2 && j - beginr < n/2; i++,j++)
    {
        p = 2 * beginl + n - i - 1;
        q = 2 * beginr + n - j - 1;
        Swap(&a[i][j],&a[p][q]);
    }
    for(i = beginl + n - 1 ,j = beginr ; i >= (beginl + n) /2&& j - beginr < n/2; i--,j++)

    {
        p = 2*beginl + n - i - 1;
        q = 2*beginr + n - j - 1;
        Swap(&a[i][j],&a[p][q]);
    }

}

void Swap(int *a,int *b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}
/*
 *Name:双偶幻方的打印
 *Version:0.0
 *Inputs:要打印的幻方：ms，幻方的阶数：n;
 *Author:LiuNing
 *Time:2019.2.16
 */
void DoubleEvenMagicSquare(int ms[][N],int n)
{
    int i = 0,j = 0,c = 1;

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
        {
            ms[i][j] = c;
            c++;
        }

    for(i = 0; i < (n/8)*4; i = i + 4)
        for(j = 0; j < n; j =j + 4)
            CDJ4(i,j,ms,n);

    if(n % 8 != 0)
    {
        i = (n / 8) * 4;
        for(j = 0; j < (n / 8) * 4; j = j + 4)
            CDJ4(i,j,ms,n);
        HCDJ(i,j,ms,4);
    }
}
