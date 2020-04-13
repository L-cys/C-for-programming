//
//  main.c
//  Week_9
//
//  Created by 陈源珊 on 2020/4/10.
//  Copyright © 2020 陈源珊. All rights reserved.
//

#include <stdio.h>

#include<math.h>
void Fun9_1(void);
void Fun9_2(void);
void Fun9_3(void);
void Fun9_4(void);
void Fun9_5(void);
void Fun9_6(void);
void Fun9_7(void);
void Fun9_8(void);
double power(double x,int y);
void itoah(int x);
double root(double a,double b);
double integral(double a,double b,int n,double (*f)(double));
double term(double x,int n);
long inverse(long x);
int verification(long n,long *hw);
void complex(char op,double a,double b,double c,double d);
double f(double x);
double f1(double x);
#define PI 3.141592
int main()
{
    int c;
    while(1)
    {
       putchar('\n');
       puts("1. 输出x的y次方");
       puts("2. 输出一个整数的十六进制形式");
       puts("3. 方程求根");
       puts("4. 输出三个定积分近似值");
       puts("5. 输出级数近似值");
       puts("6. 输出一个正整数的反序数");
       puts("7. 验证回文数猜想");
       puts("8.复数四则计算");
       puts("0. 退出");
       puts("请输入命令（数字）:");
       fflush(stdin);     /*清空标准输入缓冲区 */
       scanf("%d",&c);    /*接收输入命令*/
       switch(c)          /*根据输入命令调用相关函数*/
       {
            case 0:  return 0;
            case 1:  Fun9_1();  break;
            case 2:  Fun9_2();  break;
            case 3:  Fun9_3();  break;
            case 4:  Fun9_4();  break;
            case 5:  Fun9_5();  break;
            case 6:  Fun9_6();  break;
            case 7:  Fun9_7();  break;
            case 8:  Fun9_8();  break;
           default:  printf("\n 输入命令错，请重新输入! ");
       }
    }
}
void Fun9_1(void) {
    double x,y,result;
    printf("Please enter: ");
    scanf("%lf%lf",&x,&y);
    result = power(x,y);
    printf("%.2lf",result);
}
double power(double x,int y) {
    if (y == 0) {
        return 1.0;
    } else if (y > 0) {
        return x * power(x,y - 1);
    } else {
        return 1/x * power(x,y + 1);
    }
}
void Fun9_2(void) {
    int x;
    printf("Please enter: ");
    scanf("%d",&x);
    if (x < 0) {
        printf("%c",'-');
        itoah(-x);
    } else {
        itoah(x);
    }
}
void itoah(int x) {
    int temp;
    char e[6] = "ABCDEF";
    if ( x < 10) {
        printf("%d",x);
        return;
    } else if (x < 17) {
        printf("%c",e[x - 10]);
        return;
    } else {
        itoah(x / 16);
        temp = x % 16;
        if (temp < 10) {
            printf("%d",temp);
        } else {
            printf("%c",e[temp - 10]);
        }
    }
}
void Fun9_3(void) {
    double ans = root(1,2);
    printf("%lf",ans);
}
double f(double x) {
    return x * x / 4 - sin(x);
}
double root(double a,double b) {
    double x, eps = 1e-6;
    if (fabs(f(a)) < eps) {
        return a;
    } else if (fabs(f(b)) < eps) {
        return b;
    } else {
        x = (a + b) / 2;
        if (f(a) * f(x) <= 0) {
            return root(a,x);
        } else {
            return root(x,b);
        }
    }
}
void Fun9_4(void) {
    printf("第1个定积分值=%lf\n",integral(-PI/2,PI/2,3000,cos));
    printf("第2个定积分值=%lf\n",integral(-PI/2,PI/2,3000,sin));
    printf("第3个定积分值=%lf",integral(-PI/2,PI/2,3000,f1));
}
double integral(double a,double b,int n,double (*f)(double)) {
    double h;
    h = (b - a) / n;
    if (n == 1) {
        return (f(a) + f(a + h)) * h / 2 ;
    } else {
        return h * (f(a) + f(a + h)) / 2 + integral(a + h, b, n - 1, f);
    }
}
double f1(double x) {
    return 2 * x + 1;
}
void Fun9_5(void) {
    double x,eps,sum = 0;
    int n = 1;
    printf("Please enter: ");
    scanf("%lf%lf",&x,&eps);
    
    while (fabs(term(x,n)) > eps) {
        sum = sum + term(x,n);
        n = n + 2;
    }
    printf("x=%lf, eps=%lf, sum=%lf",x,eps,sum);
}
double term(double x,int n) {
    if (n == 1) {
        return x;
    } else {
        return term(x,n - 2) * (-1) * (n-2) * (n - 2) * x * x/((n - 1) * n);
    }
}

void Fun9_6(void) {
    long x,ans;
    printf("Please enter: ");
    scanf("%ld",&x);
    ans = inverse(x);
    printf("%ld",ans);
}
long inverse(long x) {
    long static sum = 0;
    long tail, sum_copy;
    if (x < 10) {
        sum_copy = sum;
        sum = 0;
        return x + sum_copy;
    } else {
        tail = x % 10;
        sum = (sum + tail) * 10;
        return inverse(x / 10);
    }
}
void Fun9_7(void) {
    long a,b = 0;
    int c;
    printf("Please enter: ");
    scanf("%ld",&a);
    c = verification(a,&b);
    printf("%d,%ld",c,b);
    
}
int verification(long n,long *hw) {
    long inv;
    if (*hw > 10000) {
        return n;
    } if  (n == inverse(n)) {
        return n;
    }
    inv = inverse(n);
    n = n + inv;
    *hw = *hw + 1;
    return verification(n,hw);
}
void Fun9_8(void) {
    double a,b,c,d;
    char op;
    fflush(stdin);
    printf("Please enter: ");
    scanf("(%lf+%lfi)%c(%lf+%lfi)",&a,&b,&op,&c,&d);
    printf("op:%c\n",op);
    printf("check:(%lf%lfi)op:%c,c:%lf,d:%lf\n",a,b,op,c,d);
    complex(op,a,b,c,d);
    
    
}
void complex(char op,double a,double b,double c,double d) {
    if (op == '+') {
        printf("(%.1lf+%.1lfi)%c(%.1lf+%.1lfi)=%.1lf%+.1lfi",a,b,op,c,d,a+c,b+d);
    } else if (op == '-') {
        printf("(%.1lf+%.1lfi)%c(%.1lf+%.1lfi)=%.1lf%+.1lfi",a,b,op,c,d,a-c,b-d);
    } else if (op == '*') {
        printf("(%.1lf+%.1lfi)%c(%.1lf+%.1lfi)=%.1lf%+.1lfi",a,b,op,c,d,a*c-b*d,b*c+a*d);
    } else if (op == '/') {
        double temp1 = (a*c + b*d)/(c*c + d*d);
        double temp2 = (b*c - a*d)/(c*c + d*d);
        printf("(%.1lf+%.1lfi)%c(%.1lf+%.1lfi)=%.1lf%+.1lfi",a,b,op,c,d,temp1,temp2);
    } else {
        printf("运算符错");
        return;
    }
}
