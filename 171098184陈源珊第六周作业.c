//
//  main.c
//  Week_6
//
//  Created by 陈源珊 on 2020/3/22.
//  Copyright © 2020 陈源珊. All rights reserved.
//

#include<stdio.h>
#include<math.h>
#include<time.h>
void Fun6_1(void);
void Fun6_2(void);
void Fun6_3(void);
void Fun6_4(void);
int dayThisYear(int year, int month);
int main() {
    int c;
    while(1) {
        putchar('\n');
        puts("1. 输入已给年份中包含不吉利日期的所有月份");
        puts("2. 计算某人生命的天数");
        puts("3. 计算银行账户存款额从指定数额变为0的年数");
        puts("4. 计算某企业发放奖金数额");
        puts("0. 退出");
        puts("输入命令（数字0～4）:");
        fflush(stdin);     /*清空标准输入缓冲区 */
        scanf("%d",&c);    /*接收输入命令*/
        switch(c) {
            case 0: return 0;
            case 1: Fun6_1(); break;
            case 2: Fun6_2(); break;
            case 3: Fun6_3(); break;
            case 4: Fun6_4(); break;
            default: printf("\n 输入命令错，请重新输入! ");
        }
    }
}
void Fun6_1(void) {
    int count,year,month,dif,day,day_this;
    month = 1;
    dif = 0;
    printf("Please enter the year: ");
    scanf("%d",&year);
    if (year >= 1990) {
        count = 0;
        dif = year - 1990;
        for (int i = 1990; i < year; i = i + 1) {
            if (!(i%4) && i % 100 || !(i % 400)) {
                count = count + 1;
            }
        }
        day = (dif - count) * 365 + count * 366;
        for (month = 1; month <= 12; month = month + 1) {
            day_this = dayThisYear(year, month) + 13;
            int temp = day + day_this;
            if ((day + day_this) % 7 == 5) {
                printf("%d月 ", month);
            }
        }
    } else {
        count = 0;
        dif = 1990 - dif;
        for (int i = year + 1; i < 1990; i = i + 1) {
            if (!(i%4) && i % 100 || !(i % 400)) {
                count = count + 1;
            }
        }
        day = (dif - count - 1) * 365 + count * 366;
        for (month = 1; month <= 12; month = month + 1) {
            if (!(year % 4) && year % 100 || !(year % 400)) {
                day_this = 366 - dayThisYear(year, month) - 13;
            } else {
                day_this = 365 - dayThisYear(year, month) - 13;
            }
            if ((-day - day_this) % 7  + 7 == 5) {
                printf("%d月 ", month);
            }
        }
    }
}
void Fun6_2(void) {
    int nyear, nmonth, nday, yr, mth, d, count = 0, dif = 0, daylong = 0, flag=0;
    printf("Please enter your date: ");
    scanf("%d%d%d", &yr, &mth, &d);
    time_t timep;
    struct tm *p;
    time (&timep);
    p = gmtime(&timep);
    nyear = 1900+p->tm_year;
    nmonth = 1+p->tm_mon;
    nday = p->tm_mday;
    if (yr > nyear) {
        flag = 1;
    } else if (yr == nyear && mth > nmonth) {
        flag = 1;
    } else if (yr == nyear && mth == nmonth && d > nday) {
        flag = 1;
    }
    if (flag) {
        printf("今天是%d年%d月%d日，出生日期超过今日日期,请重新输入!",nyear,nmonth,nday);
    } else {
        dif = nyear - yr;
        for (int i = yr + 1; i < nyear; i = i + 1) {
            if (!(i%4) && i % 100 || !(i % 400)) {
                count = count + 1;
            }
        }
        daylong = (dif - count - 1) * 365 + count * 366;
        daylong = daylong + dayThisYear(nyear, nmonth) + nday;
        if (!(yr % 4) && yr % 100 || !(yr % 400)) {
            daylong = daylong + 366 - dayThisYear(yr, mth) - d;
        } else {
            daylong = daylong + 365 - dayThisYear(yr, mth) - d;
        }
        printf("今天是%d年%d月%d日，他（她）的生命已有%d天!",nyear,nmonth,nday,daylong);
    }
    
}
void Fun6_3(void) {
    int deposit,t = 0;
    do {
        printf("Please enter the number here: ");
        scanf("%d",&deposit);
        if (deposit > 1250000)puts("输入金额不正确，请重新输入！");
    } while (deposit > 1250000);
    while(deposit > 0) {
        deposit = deposit * 1.08 - 100000;
        t = t + 1;
    }
    printf("%d年后该银行账户存款额变为0",t);
    
    
}
void Fun6_4(void) {
    int profit,salary;
    printf("Please enter the profit: ");
    scanf("%d",&profit);
    if (profit < 100000) {
        salary = profit * 0.1;
    } else if (profit <= 200000) {
        salary = 10000 + (profit - 100000) * 0.075;
    } else if (profit <= 400000) {
        salary = 10000 + 7500 + (profit - 200000) * 0.05;
    } else if (profit <= 600000) {
        salary = 10000 + 7500 + 10000 + (profit - 400000) * 0.03;
    } else if (profit <= 1000000) {
        salary = 10000 + 7500 + 10000 + 6000 + (profit - 600000) * 0.015;
    } else {
        salary = 10000 + 7500 + 10000 + 6000 + 6000 + (profit - 1000000) * 0.01;
    }
    printf("奖金=%d",salary);
}
int dayThisYear(int year, int month) {
    int leap,day;
    day = 0;
    leap = !(year % 4) && year % 100 || !(year % 400);
    switch(month) {
        case 12 : day = day + 30;
        case 11 : day = day + 31;
        case 10 : day = day + 30;
        case 9 : day = day + 31;
        case 8 : day = day + 31;
        case 7 : day = day + 30;
        case 6 : day = day + 31;
        case 5 : day = day + 30;
        case 4 : day = day + 31;
        case 3 : day = day + 28 + leap;
        case 2 : day = day + 31;
    }
    return day;
    
}
