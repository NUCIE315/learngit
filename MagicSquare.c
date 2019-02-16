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

    printf("����÷��Ľ�����");
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
*Name: ��÷��Ĵ�ӡ
*Version: 1.1���޸��˵�һ��j����
*Inputs:Ҫ��ӡ�Ļ÷���a[N][N];��÷��Ľ�����n;�ӵڼ��к͵ڼ��п�ʼ��beginl, beginr;
*       ��һ��Ԫ�ص����֣�start�����һ��Ԫ�ص�ֵ:end;
*Author:LiuNing
*Time:2019.2.13
*
*/
void OddMagicSquare(int ms[][N],int n,int beginl,int beginr,int start,int end)
{
    int i = beginl, j = beginr,c = start + 1,lastr = 0;
    /*��*/    lastr = beginr + n;
    /*��*/  j = (beginr + lastr)/2;//�м��һλ�����һ�����һ���ĺͳ���2��v 1.1����
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
 *Name:��ż�÷��Ĵ�ӡ
 *Version:0.0
 *Inputs:Ҫ��ӡ�Ļ÷�ms���÷��Ľ���n��
 *Author:LiuNing
 *Time:2019.2.16
 */
void OddEvenMagicSquare(int ms[][N],int n)
{
    int m = 0,sm = 0,n0 = 0;

    //�ֽ�Ϊ�ĸ���÷�
    n0 = n;
    m = n/4;
    n = 2*m + 1;
    sm = n * n;

    //���ÿ����÷�
    OddMagicSquare(ms,n,0,0,1,sm);
    OddMagicSquare(ms,n,n,n,sm + 1,2*sm);
    OddMagicSquare(ms,n,0,n,2*sm + 1, 3*sm);
    OddMagicSquare(ms,n,n,0,3*sm + 1, 4*sm);
}
/*
 *Name:CDJ4:��4ά�÷������ܻ÷����ĶԽ��߶Գƣ����������Խ���
 *Input: beginl���÷�����ʼ�У�beginr���÷�����ʼ�У�a���÷���n���÷��Ľ���
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
 *Name:HCDJ(���������Գƣ�
 *Input: beginl,beginr ������������У�a���÷���n���÷��Ľ���
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
 *Name:˫ż�÷��Ĵ�ӡ
 *Version:0.0
 *Inputs:Ҫ��ӡ�Ļ÷���ms���÷��Ľ�����n;
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
