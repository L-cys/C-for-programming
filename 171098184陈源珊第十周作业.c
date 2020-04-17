//
//  main.c
//  Week_10
//
//  Created by 陈源珊 on 2020/4/17.
//  Copyright © 2020 陈源珊. All rights reserved.
//

#include <stdio.h>

#include<math.h>
void Fun10_1(void);
void Fun10_2(void);
void Fun10_3(void);
void Fun10_4(void);
void Fun10_5(void);
void Fun10_6(void);
void Fun10_7(void);
int prime(int x);
void decomposite(int n,int *a,int *b,int *c);
int main()
{
    int c;
    while(1)
    {
       putchar('\n');
       puts("1.Verify the Goldbach Conjecture");
       puts("2.Data encoding");
       puts("3.Find all the prime numbers within given range");
       puts("4.Circle shift of array data");
       puts("5.Generate data array");
       puts("6.Find all the integer satisfying given conditions within certain range");
       puts("7.Score calculation");
       puts("0.Quit");
       puts("Please enter the number");
       fflush(stdin);     /*清空标准输入缓冲区 */
       scanf("%d",&c);    /*接收输入命令*/
       switch(c)          /*根据输入命令调用相关函数*/
       {
            case 0:  return 0;
            case 1:  Fun10_1();  break;
            case 2:  Fun10_2();  break;
            case 3:  Fun10_3();  break;
            case 4:  Fun10_4();  break;
            case 5:  Fun10_5();  break;
            case 6:  Fun10_6();  break;
            case 7:  Fun10_7();  break;
           default:  printf("\n Wrong command, enter again!");
       }
    }
}
void Fun10_1(void) {
    int a,b;
    printf("Please enter the range: ");
    scanf("%d%d",&a,&b);
    for (int j = a; j <= b; j = j + 1) {
        if (j % 2 == 0) {
            printf("\n");
            for (int z = 2; z <= j/2 + 1; z = z + 1 ) {
                if (prime(z) == 1 && prime(j-z) == 1) {
                    printf("%2d=%2d+%2d ",j,z,j-z);
                }
            }
        }
    }
}
int prime(int x) {
    if (x == 1) {
        return 0;
    }
    for (int i = 2; i < x; i = i + 1) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}
void Fun10_2(void) {
    int a[6],b[6];
    printf("Please enter: ");
    for (int i = 0; i < 6; i = i + 1) {
        scanf("%d",&a[i]);
    }
    b[0] = 0;
    for (int j = 1; j < 6; j = j + 1) {
        int count = 0;
        for (int k = 0; k < j; k = k + 1) {
            if (a[k] < a[j]) {
                count = count + 1;
            }
        }
        b[j] = count;
    }
    printf("Array a: ");
    for (int z = 0; z < 6; z = z + 1) {
        printf("%d ",a[z]);
    }
    printf("Array b: ");
    for (int z = 0; z < 6; z = z + 1) {
        printf("%d ",b[z]);
    }
}
void Fun10_3(void) {
    int n1,n2,b[100]= {0},count = 0,flag = 1;
    printf("Please enter the range: ");
    scanf("%d%d",&n1,&n2);
    for (int x = n1; x <= n2; x = x + 1) {
        if (prime(x) == 1) {
            int a[10] = {0};
            int x_copy = x*x, temp;
            while (x_copy > 0) {
                temp = x_copy % 10;
                a[temp] = a[temp] + 1;
                x_copy = x_copy / 10;
            }
            flag = 1;
            for (int i = 0; i < 10; i = i + 1) {
                if (a[i] > 1) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) {
                b[count] = x;
                count = count + 1;
            }
        }
    }
    for (int j = 0; j < count; j = j + 1) {
        printf("%d\t%d\n",b[j],b[j]*b[j]);
    }
}
void Fun10_4(void) {
    int t,m,temp;
    int x[10]={ 0,1,2,3,4,5,6,7,8,9};
    printf("Please enter t and m: ");
    scanf("%d%d",&t,&m);
    if (t == 0) {
        for (int i = 0; i < m; i = i + 1) {
            for (int j = 1; j < 10; j = j + 1) {
                temp = x[j];
                x[j] = x[j-1];
                x[j-1] = temp;
            }
        }
    }
    if (t == 1) {
        for (int i = 0; i < m; i = i + 1) {
            for (int j = 9; j > 0; j = j - 1) {
                temp = x[j];
                x[j] = x[j-1];
                x[j-1] = temp;
            }
        }
    }
    for (int z = 0; z < 10; z = z + 1) {
        printf("%d ",x[z]);
    }
}
void Fun10_5(void) {
    int n,n_copy,a[100] = {0},count = 0;
    printf("Please enter n: ");
    scanf("%d",&n);
    n_copy = n;
    a[0] = n_copy;
    count = count + 1;
    while (n_copy != 1) {
        if (n_copy % 2 == 0) {
            n_copy = n_copy / 2;
            a[count] = n_copy;
            count = count + 1;
        } else {
            n_copy = 3 * n_copy + 1;
            a[count] = n_copy;
            count = count + 1;
        }
    }
    for (int i = 0; i < count; i = i + 1) {
        printf("%d ",a[i]);
    }
}
void Fun10_6(void) {
    int x[100]={0},m,n,a,b,c,count = 0;
    do{
        printf("Please enter m and n: ");
        scanf("%d%d",&m,&n);
        if (100>m || m>10000|| 100 > n||n > 10000 || m>n){
            puts("Wrong!");
        }
    } while (100>m || m>10000|| 100 > n||n > 10000 || m>n);
    for (int i = m; i <= n; i = i + 1) {
        decomposite(i,&a,&b,&c);
        if (a*a + b*b == c*c && a != 0 && b != 0 && c != 0) {
            x[count] = i;
            count = count + 1;
        }
    }
    for (int j = 0; j < count; j = j + 1) {
        decomposite(x[j],&a,&b,&c);
        printf("%d:%d*%d+%d*%d=%d*%d\n",x[j],a,a,b,b,c,c);
    }
}
void decomposite(int n,int *a,int *b,int *c) {
    if ((n / 1000) > 0 && (n / 1000) < 10) {
        *a = n / 1000;
        *b = (n - 1000*(*a))/100;
        *c = n - 1000*(*a) - 100*(*b);
    } else if ((n/100) > 0 && (n/100) < 10) {
        *a = n / 100;
        *b = (n - 100*(*a))/10;
        *c = n - 100*(*a) - 10*(*b);
    }
}
void Fun10_7(void) {
    int id[50] = {1701,1702,1703,1704,1705,1706,1707,1708,1709,1710,1711,1712,1713},
    mid[50] = {80,72,97,57,88,42,75,82,91,68,82,95,51},
    final[50] = {85,68,90,66,92,61,62,81,94,80,71,97,57},n;
    double total[50] = {0},avrg,sum = 0;
    printf("Please enter n: ");
    scanf("%d",&n);
    for (int i = 0; i < n; i = i + 1) {
        total[i] = mid[i] * 0.45 + final[i] * 0.55;
        sum = sum + total[i];
    }
    avrg = sum / n;
    printf("Id\tMid\tFinal\tTotal\t+/-\n");
    for (int j = 0; j < n; j = j + 1) {
        printf("%d\t%d\t%d\t%.1lf\t%.1lf\n",id[j],mid[j],final[j],total[j],total[j]-avrg);
    }
    printf("Average= %.1lf",avrg);
}

