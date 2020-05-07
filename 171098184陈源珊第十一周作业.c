//
//  main.c
//  Week_11
//
//  Created by 陈源珊 on 2020/4/25.
//  Copyright © 2020 陈源珊. All rights reserved.
//

#include <stdio.h>

#include<math.h>
void Fun11_1(void);
void Fun11_2(void);
void Fun11_3(void);
void Fun11_4(void);
void Fun11_5(void);
void Fun11_6(void);
void Fun11_7(void);
void joseph(int n,int m,int x[]);
int fact(int n,int *p);
void sort(int x[],int n);
void movesort(int x[],int n);
int deleven(int x[],int n);
int insert(int x[],int n,int key);
int bs(int x[],int low,int high,int key);
#define MAX 100
int main()
{
    int c;
    while(1)
    {
       putchar('\n');
       puts("1. Josephus circle simulation");
       puts("2. Factorial operation of long integer");
       puts("3. Selected sort");
       puts("4. Half-cut sort");
       puts("5. Array sortted and moved");
       puts("6. Delete all even numbers");
       puts("7. Insert new integer");
       puts("0. Quit");
       puts("Please enter number: ");
       fflush(stdin);
       scanf("%d",&c);
       switch(c)
       {
            case 0:  return 0;
            case 1:  Fun11_1();  break;
            case 2:  Fun11_2();  break;
            case 3:  Fun11_3();  break;
            case 4:  Fun11_4();  break;
            case 5:  Fun11_5();  break;
            case 6:  Fun11_6();  break;
            case 7:  Fun11_7();  break;
           default:  printf("\n Wrong command! Enter again!");
       }
    }
}
void Fun11_1(void) {
    int n,m;
    printf("Please enter n and m: ");
    scanf("%d%d",&n,&m);
    int x[n];
    joseph(n,m,x);
}
void joseph(int n,int m,int x[]) {
    int a[n];
    int count = 0;
    int p = 0;
    for (int i = 0; i < n; i = i + 1) {
        a[i] = i+1;
    }
    int i = 0;
    while (count < n) {
        int k;
        for (k = 1; k < m;){
            if (a[i] == 0) {
                i = i + 1;
                /*continue;*/
            } else {
                i = i + 1;
                k = k + 1;
                if (count == n - 1 && k == m) {
                    i = i - 1;
                }
            }
            if (i == n) {
                i = 0;
            }
        }
        if (k == m) {
            if (i > n) {
                i = 0;
            }
            while (a[i] == 0) {
                if (i == n) {
                    i = 0;
                } else {
                    i = i + 1;
                }
            }
            int temp = a[i];
            x[p] = temp;
            p = p + 1;
            a[i] = 0;
            k = 0;
        }
        count = count + 1;
    }
    for (int j = 0; j < n; j = j + 1) {
        printf("%d ",x[j]);
    }
}
void Fun11_2(void) {
    int n,result,m[MAX] = {0},flag = 1;
    printf("Please enter n: ");
    scanf("%d",&n);
    result = fact(n,&m[0]);
    if (result == 0) {
        printf("Out of range!");
    } else {
        printf("%d!=",n);
        for (int i = MAX-1; i >= 0; i = i - 1) {
            if(m[i] == 0 && flag) {
                continue;
            } if (m[i] != 0) {
                flag = 0;
            }
            printf("%d",m[i]);
        }
    }
}
int fact(int n,int *p) {
    int temp,digit = 1, carry = 0;
    *p = 1;
    for (int i = 2; i <= n; i = i + 1) {
        for (int j = 1; j <= digit; j = j + 1) {
            temp = *(p+j-1) * i + carry;
            *(p+j-1) = temp % 10;
            carry = temp / 10;
        }
        while(carry) {
            digit = digit + 1;
            *(p+digit-1) = carry % 10;
            carry = carry / 10;
        }
        if (digit > MAX) {
            return 0;
        }
    }
    return 1;
}
void Fun11_3(void) {
    int x[9] = {1,3,2,9,4,7,5,8,6};
    sort(x,9);
    for (int j = 0; j < 9; j = j + 1) {
        printf("%d ",x[j]);
    }
}
void sort(int x[],int n) {
    int k = n-1,temp;
    if (n==1) return;
    for(int i = n-1; i >= 0; i = i - 1) {
        if (x[i] < x[k]) {
            k = i;
        }
    }
    /*printf("mark=%d\n",x[mark]);*/
    temp = x[n-1];
    x[n-1] = x[k];
    x[k] = temp;
    sort(x,n-1);
}
void Fun11_4(void) {
    int x[10] = {5,23,28,34,43,45,56,60,67,90},target,result;
    printf("Please enter: ");
    scanf("%d",&target);
    result = bs(x,0,9,target);
    if (result != -1) {
        printf("%d is in a[%d]",target,result);
    } else {
        printf("Cannot find %d!",target);
    }
}
int bs(int x[],int low,int high,int key) {
    int mid;
    mid = (low + high) / 2;
    if (low == high && x[mid] != key) return -1;
    if (x[mid] == key) {
        return mid;
    } else {
        if (x[mid] > key) {
            return bs(x,low,mid-1,key);
        } else {
            return bs(x,mid+1,high,key);
        }
    }
}
void Fun11_5(void) {
    int x[9] = {1,3,2,9,4,7,5,8,6};
    movesort(x,9);
    for (int i = 0; i < 9; i = i + 1) {
        printf("%d ",x[i]);
    }
    
}
void movesort(int x[],int n) {
    int temp,even = 0;
    for (int i = 0; i < n; i = i + 1) {
        if (x[i] % 2 == 0) {
            for (int j = i + 1; j < n; j = j + 1) {
                temp = x[j];
                x[j] = x[j-1];
                x[j-1] = temp;
            }
        }
    }
    for (int a = 0; a < n; a = a + 1) {
        if (x[a] % 2 == 0) {
            even = even + 1;
        }
    }
    for (int z = 0; z <= n - even; z = z + 1) {
        int te = z,t;
        for (int y = z; y < n - even; y = y + 1) {
            if (x[y] > x[te]) {
                te = y;
            }
        }
        t = x[z];
        x[z] = x[te];
        x[te] = t;
    }
    for (int z = n - even - 1; z < n; z = z + 1) {
        int te = z,t;
        for (int y = z; y < n; y = y + 1) {
            if (x[y] < x[te]) {
                te = y;
            }
        }
        t = x[z];
        x[z] = x[te];
        x[te] = t;
    }
         
}
void Fun11_6(void) {
    int count,n = 9,x[9] = {1,3,2,9,4,7,5,8,6};
    count = deleven(x,n);
    for (int i = 0; i < count; i = i + 1) {
        printf("%d ",x[i]);
    }
}
int deleven(int x[],int n) {
    int j,i;
    for (i = 0,j = 0; i < n; i = i + 1) {
        if (x[i] % 2 != 0) {
            x[j] = x[i];
            j = j + 1;
        }
    }
    return j;
}
void Fun11_7(void) {
    int rsl,x[9] = {1,3,2,9,4,7,5,8,6};
    rsl = insert(x,9,0);
    for (int i = 0; i < rsl; i = i + 1) {
        printf("%d ",x[i]);
    }
}
int insert(int x[],int n,int key) {
    int i,j,k = 0;
    for (i = 0; i < n; i = i + 1) {
        if (x[i] > x[k]) {
            k = i;
        }
    }
    
    for (j = n-1; j >= k; j = j - 1) {
        x[j + 1] = x[j];
    }
    x[j+1] = 0;
    return n+1;
}
