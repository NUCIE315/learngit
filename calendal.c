//��ӡ����������ĳһ���Լ������1��1�����ܼ��������ǵ�һ�죬�����ǵ����죩�����磺2019 3��
#include <stdio.h>
#include <stdlib.h>

int DivideYear(int year, int month);
void PrintCalendal(int days, int n);

int main()
{
   int year = 0, month = 0, first1 = 0,sum = 0;
   printf("The year is:");
   scanf("%d", &year);
   printf("The first day is the day of the week:");
   scanf("%d",&first1);

   for(month = 1;month <= 12;month++)
   {
       printf("\nThe %d month's calendar:",month);
       PrintCalendal(DivideYear(year,month),(sum + first1)%7);
       sum += DivideYear(year,month);
   }

    return 0;
}
/*
 *Name:�ָ�һ��
 *Effect:��һ��ָ�Ϊ12���£�������ÿ���µ�����
 *Inputs:ĳһ��: year,�����ĳһ���·�: month
 *Output:������µ�����
 *Version:0.0
 *Author:LiuNing
 *Time:2019.2.18
 */
int DivideYear(int year,int month)
{
    int m =0;
    switch(month)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        m = 31;
        break;
    case 2:
        if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            m = 29;
        else
            m = 28;
        break;
    case 4: case 6: case 9: case 11:
        m = 30;
        break;
    default:
        printf("Illegal digit");
        break;
    }
    return m;
}
/*
 *Name:��ӡ����
 *Effect:����ÿ���µĵ�һ����һ�ܵĵڼ����Լ����µ�������ӡ����������
 *Inputs:�����м��죺days,ÿ���µĵ�һ����һ�ܵĵڼ��죺n��
 *Version:0.0
 *Author:LiuNing
 *Time:2019.2.18
 */
 void PrintCalendal(int days, int n)
 {
     int i = 0,j = 0;
     printf("\nSun Mon Thur Wes Tues Fri Sat\n");
    if(n != 0)
    {
    for(j = 1;j < n;j++)
    printf("    ");
    }
    else
    {
        for(j = 1;j < 7;j++)
            printf("    ");
    }
    for(i = 1; i <= days; i++)
    {

        if(j != 7)
        {
            printf("%3d ",i);
            j++;
        }
        else
        {
            printf("%3d\n",i);
            j = 1;
        }

    }
    printf("\n");
 }
