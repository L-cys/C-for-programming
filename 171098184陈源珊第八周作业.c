//
//  main.c
//  Week_8
//
//  Created by 陈源珊 on 2020/4/3.
//  Copyright © 2020 陈源珊. All rights reserved.
//

#include <stdio.h>

#include<math.h>
void Fun8_1(void);
void Fun8_2(void);
void Fun8_3(void);
void Fun8_4(void);
void Fun8_5(void);
void Fun8_6(void);
void Fun8_7(void);
void Fun8_8(void);
int max_divisor(int a, int b);
void newton(void);
void division(void);
void secant(void);
void fixedpoint(void);
double trapezoid (double a,double b, int n);
double rectangle(double a,double b,int n);
double simpson(double a,double b,int n);
double f(double x);
double f1(double x);
double fun(double x);
#define PI 3.1415926
int main()
{
    int c;
    while(1)
    {
       putchar('\n');
       puts("1. 输出满足条件的正整数对（a,b）");
       puts("2. 输出8个整数的最大公约数");
       puts("3. 计算并输出sinx的近似值");
       puts("4. 计算并输出π近似值");
       puts("5. 验证一个函数的级数展开式");
       puts("6. 输出一个数列前20项");
       puts("7. 计算并输出方程e^x+x=0的一个近似实根");
        puts("8.计算并输出一个定积分的近似值");
       puts("0. 退出");
       puts("请输入命令（数字）:");
       fflush(stdin);     /*清空标准输入缓冲区 */
       scanf("%d",&c);    /*接收输入命令*/
       switch(c)          /*根据输入命令调用相关函数*/
       {
            case 0:  return 0;
            case 1:  Fun8_1();  break;
            case 2:  Fun8_2();  break;
            case 3:  Fun8_3();  break;
            case 4:  Fun8_4();  break;
            case 5:  Fun8_5();  break;
            case 6:  Fun8_6();  break;
            case 7:  Fun8_7();  break;
            case 8:  Fun8_8();  break;
           default:  printf("\n 输入命令错，请重新输入! ");
       }
    }
}
void Fun8_1(void) {
    for (int a = 1; a <= 50; a = a + 1) {
        int b = 99 - a;
        if (max_divisor(a,b) % 3 == 0) {
            printf("(%d,%d)",a,b);
        }
    }
}
void Fun8_2(void) {
    int lst[8],x,y,temp;
    printf("Input: ");
    for (int i = 0; i < 8; i = i + 1) {
        scanf("%d", &lst[i]);
    }
    x = lst[0];
    for (int j = 0; j < 8; j = j + 1) {
        y = lst[j];
        temp = max_divisor(x, y);
        x = temp;
    }
    printf("最大公约数=%d",x);
}
void Fun8_3(void) {
    double x,mdx,sum,a,n;
    sum = 0;
    n = 1;
    printf("x=");
    scanf("%lf",&x);
    mdx = fmod(x, 2*PI);
    a = mdx;
    while(fabs(a) > 1e-10) {
        sum = sum + a;
        a = (-1) * a * mdx * mdx / (n + 2) / (n + 1);
        n = n + 2;
    }
    printf("%lf",sum);
}
void Fun8_4(void) {
    double mul,term,frac;
    mul = 1;
    term = 2;
    frac = 0;
    while (term > 1) {
        mul = mul * term;
        frac = pow(2 + frac, 0.5);
        term = 2 / frac;
    }
    printf("π=%lf",mul);
}
void Fun8_5(void) {
    int n = 1;
    double sum = 0,term,x,left,a;
    for (x = 0.1; x <= 1.0; x = x + 0.1) {
        n = 1;
        a = -1 * (x / 2);
        term = a;
        sum = 0;
        left = (x*x + 1 + 1/x) * exp(-x) - 1/x;
        while (fabs(term) > 1e-8) {
            sum = sum + term;
            n = n + 1;
            a = (-1) * a * x / (n + 1);
            term = pow(n,3) * a;
            printf("n:%d term:%lf a:%lf sum:%lf \n",n,term,a,sum);
        }
        if (fabs(sum - left) / (fabs(left) + fabs(sum)) <= 1e-6) {
            printf("right, x=%.1lf, 函数=%lf, 级数=%lf\n",x,left,sum);
        } else {
            printf("wrong, x=%.1lf, 函数=%lf, 级数=%lf\n",x,left,sum);
        }
    }
}
void Fun8_6(void) {
    int count=1,a=2,b=3;
    printf("%d %d ",a,b);
    while (count <= 18) {
        a = a + b;
        b = b - a;
        count = count + 2;
        printf("%d %d ",a,b);
    }
}
void Fun8_7(void) {
    char c;
    while(1)
    {
       putchar('\n');
       puts("A. 牛顿迭代法");
       puts("B. 不动点迭代法");
       puts("C. 二分法");
       puts("D. 弦截法");
       puts("E. 退出");
       puts("请输入命令（字母）:");
       fflush(stdin);     /*清空标准输入缓冲区 */
       scanf("%c",&c);    /*接收输入命令*/
       switch(c)          /*根据输入命令调用相关函数*/
       {
               
            case 'A':  newton();  break;
            case 'B':  fixedpoint();  break;
            case 'C':  division();  break;
            case 'D':  secant();  break;
           case 'E':  return;
           default:  printf("\n 输入命令错，请重新输入! ");
       }
    }
}
    
void Fun8_8(void) {
    char c;
    while(1)
    {
       putchar('\n');
       puts("A. 梯形法");
       puts("B. 矩形法");
       puts("C. 辛普森法");
       puts("D. 退出");
       puts("请输入命令（字母）:");
       fflush(stdin);
       scanf("%c",&c);
       switch(c)
       {
               
           case 'A':  printf("s=%.2lf",trapezoid(1, 3, 10000));  break;
            case 'B':  printf("s=%.2lf",rectangle(1, 3, 10000));  break;
            case 'C':  printf("s=%.2lf",simpson(1, 3, 10000));  break;
            case 'a':  printf("s=%.2lf",trapezoid(1, 3, 10000));  break;
            case 'b':  printf("s=%.2lf",rectangle(1, 3, 10000));  break;
            case 'c':  printf("s=%.2lf",simpson(1, 3, 10000));  break;
            case 'D':  return;
            case 'd':  return;
            default:  printf("\n 输入命令错，请重新输入! ");
       }
    }
}
int max_divisor(int a, int b) {
    int r;
    if (b == 0) {
        return a;
    }
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
void newton(void) {
    double x = 0;
    while(fabs(f(x)) > 1e-7) {
        x = x - f(x)/f1(x);
    }
    printf("x=%lf",x);
}
void division(void) {
    double a = -1, b = 0,x = 0,eps = 1e-7;
    if (fabs(exp(a)+a) <= eps) {
        printf("x=%lf",a);
    } else if (fabs(exp(a)+a) <= eps) {
        printf("x=%lf",b);
    } else {
        while (1) {
            x = (a + b) / 2;
            if (fabs(exp(x)+x) <= eps) {
                break;
            }
            if ((exp(x) + x)*(exp(a) + a) < 0) {
                b = x;
            }
            else {
                a = x;
            }
        }
    }
    printf("x=%lf",x);
}
void secant(void) {
    double a = -1, b = 0,x = 0,eps = 1e-7;
    if (fabs(exp(a)+a) <= eps) {
        printf("x=%lf",a);
    } else if (fabs(exp(a)+a) <= eps) {
        printf("x=%lf",b);
    } else {
        while (1) {
            x = (a * (exp(b) + b) - b * (exp(a) + a)) / ((exp(b) + b)-(exp(a) + a));
            if (fabs(exp(x)+x) <= eps) {
                break;
            }
            if ((exp(x) + x)*(exp(a) + a) < 0) {
                b = x;
            }
            else {
                a = x;
            }
        }
    }
    printf("x=%lf",x);
}
void fixedpoint(void) {
    double x = 0,x1,eps = 1e-7;
     do {
        x1 = x;
        x = -exp(x);
     } while (fabs(exp(x) + x) > eps && fabs(x - x1) > eps);
     printf("x=%lf",x);
}
double f(double x) {
    return exp(x) + x;
}
double f1(double x) {
    return exp(x) + 1;
}
double trapezoid (double a,double b, int n) {
    double h, s, x;
    h = (b - a)/n;
    s = (fun(a) + fun(b)) / 2;
    x = a;
    for (int i = 1; i < n; i = i + 1) {
        x = x + h;
        s = s + fun(x);
    }
    return s * h;
}
double rectangle(double a,double b,int n) {
    double h, s = 0, x;
    h = (b - a)/n;
    x = a + h/2;
    for (int i = 1; i < n; i = i + 1) {
        x = x + h;
        s = s + fun(x);
    }
    return s * h;
}
double simpson(double a,double b,int n) {
    double h, s, x;
    h = (b - a)/(2 * n);
    s = (fun(a) + fun(b)) / 2 + 2 * fun(a + h);
    x = a;
    for (int i = 1; i < n ; i = i + 1) {
        s = s + 2 * fun(a + (2 * i + 1) *h) + fun(a + 2 * i * h);
    }
    return s * (b - a) / (3 * n);
}
double fun(double x) {
    return (exp(3 * x) + pow(x,7));
}
