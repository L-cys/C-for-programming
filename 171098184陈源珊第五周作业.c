//
//  main.c
//  Week_5
//
//  Created by 陈源珊 on 2020/3/15.
//  Copyright © 2020 陈源珊. All rights reserved.
//

#include<stdio.h>
#include<math.h>
void Fun5_1(void);
void Fun5_2(void);
void Fun5_3(void);
void Fun5_4(void);
void Fun5_5(void);
void Fun5_6(void);
void Fun5_7(void);
long inverse(long a);
int is_prime(int a);
int main()
{
    int c;
    while(1)
    {
       putchar('\n');
       puts("1. 判断日期正确性");
       puts("2. 判断Armstrong数");
       puts("3. 输出所有2位和3位平方镜反数");
       puts("4. 输出满足所给条件的素数");
       puts("5. 输出前5个默尼森数");
       puts("6. 验证素数生成公式");
       puts("7. 输出既是回文数同时也是完全平方数的6位十进制整数");
       puts("0. 退出");
       puts("请输入命令（数字）:");
       fflush(stdin);     /*清空标准输入缓冲区 */
       scanf("%d",&c);    /*接收输入命令*/
       switch(c)          /*根据输入命令调用相关函数*/
       {
            case 0:  return 0;
            case 1:  Fun5_1();  break;
            case 2:  Fun5_2();  break;
            case 3:  Fun5_3();  break;
            case 4:  Fun5_4();  break;
            case 5:  Fun5_5();  break;
            case 6:  Fun5_6();  break;
            case 7:  Fun5_7();  break;
           default:  printf("\n 输入命令错，请重新输入! ");
       }
    }
}
void Fun5_1(void)
{
    int year,month,day,flag = 1,f = 1;;
    printf("Please enter your date: ");
    scanf("%d%d%d",&year,&month,&day);
    int a[] = {1,3,5,7,8,10,12};
    for (int i = 0; i < 7; i = i + 1) {
        if (month == a[i]) {
            flag = 0;
        }
    }
    if (flag != 0 && day > 30) {
        f = 0;
    }
    if (!(!(year % 4) && (year % 100) || !(year % 400))) {
        if (month == 2 && day > 28) {
            f = 0;
        }
    }
    if (f == 0) {
        printf("错误");
    } else {
        printf("正确");
    }
}
void Fun5_2(void)
{
    int x,first,second,third;
    printf("Please enter the number: ");
    scanf("%d",&x);
    if ((x / 100) == 0 || x / 100 > 9) {
        printf("%d不是3位整数",x);
    } else {
        first = x / 100;
        second = (x - first * 100) / 10;
        third = x - first * 100 - second * 10;
        if (x == first * first * first + second* second * second + third * third * third) {
            printf("%d是Armstrong数",x);
        } else {
            printf("%d不是Armstrong数",x);
        }
    }
}
void Fun5_3(void)
{
    long mul, self_inv, mul_inv;
    for (long i = 10; i < 1000; i = i + 1) {
        mul = i * i;
        self_inv = inverse(i);
        mul_inv = inverse(mul);
        if (mul_inv == self_inv * self_inv && inverse(self_inv * self_inv) == mul) {
            printf("%ld ",i);
        }
    }
}
void Fun5_4(void)
{
    int first, second, third,flag;
    for (int i = 100; i < 1000; i = i + 1) {
        flag = 1;
        /* flag = 1说明这是一个素数*/
        for (int j = 2; j < i ; j = j + 1) {
            if ( i % j == 0) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            first = i / 100;
            second = (i - first * 100) / 10;
            third = i - first * 100 - second * 10;
            if ((second + third) % 10 == first) {
                printf("%d ",i);
            }
        }
    }
}
void Fun5_5(void)
{
    int m,p = 2, count = 5;
    while (count > 0) {
        m = pow(2,p) - 1;
        if (is_prime(p) == 1 && is_prime(m)) {
            count = count - 1;
            printf("%d ",m);
        }
        p = p + 1;
    }
}
void Fun5_6(void)
{
    int n = 1,p,flag = 1;
    while (flag == 1) {
        p = n * n + n + 41;
        if (is_prime(p) == 1) {
            printf("n=%d\t%d*%d+%d+41=%d ok\n",n,n,n,n,p);
        } else {
            printf("n=%d\t%d*%d+%d+41=%d error\n",n,n,n,n,p);
            flag = 0;
        }
        n = n + 1;
    }
}
void Fun5_7(void)
{
    for (long a = 100000; a < 1000000; a = a + 1) {
        if (a == inverse(a) && sqrt(a) == (int) sqrt(a)) {
            printf("%ld",a);
        }
    }
}
long inverse(long a) {
    long a_copy,num,final = 0;
    a_copy = a;
    while (a_copy > 0) {
        num = a_copy % 10;
        final = final * 10 + num;
        a_copy = a_copy / 10;
    }
    return final;
}
int is_prime(int a) {
    int flag = 1;
    for (int j = 2; j < a ; j = j + 1) {
        if ( a % j == 0) {
            flag = 0;
            break;
        }
    }
    return flag;
}
