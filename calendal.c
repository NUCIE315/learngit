//打印日历，输入某一年以及该年的1月1日是周几（周日是第一天，周六是第七天）（例如：2019 3）
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
 *Name:分割一年
 *Effect:将一年分割为12个月，并返回每个月的天数
 *Inputs:某一年: year,该年的某一个月份: month
 *Output:该年该月的天数
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
 *Name:打印日历
 *Effect:根据每个月的第一天是一周的第几天以及该月的天数打印该月日历；
 *Inputs:该月有几天：days,每个月的第一天是一周的第几天：n；
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
