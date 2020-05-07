//
//  main.c
//  Week_12
//
//  Created by 陈源珊 on 2020/5/2.
//  Copyright © 2020 陈源珊. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
#include<math.h>
void Fun12_1(void);
void Fun12_2(void);
void Fun12_3(void);
void Fun12_4(void);
void Fun12_5(void);
void Fun12_6(void);
int combine(int a[],int ma,int b[],int mb,int c[]);
void fun(int p[][4],int n);
void magicmatrix(int (*a)[9],int n);
int main()
{
    int c;
    while(1)
    {
       putchar('\n');
       puts("1.Merge two increasing array.");
       puts("2.Switch the max and min number in a matrix into the specific position.");
       puts("3.Generate n level magic matrix.");
       puts("4.Find the specific point.");
       puts("5.Init Minesweeper.");
       puts("6.Calculate the number of items in an array.");
       puts("0.Quit");
       puts("Please enter the number");
       fflush(stdin);
       scanf("%d",&c);
       switch(c)
       {
            case 0:  return 0;
            case 1:  Fun12_1();  break;
            case 2:  Fun12_2();  break;
            case 3:  Fun12_3();  break;
            case 4:  Fun12_4();  break;
            case 5:  Fun12_5();  break;
            case 6:  Fun12_6();  break;
           default:  printf("\n Wrong command, enter again!");
       }
    }
}
void Fun12_1(void) {
    int x[10] = {3,6,7,18,23,33,35,43,48,78};
    int y[10] = {2,7,13,21,33,37,48,50,58,67};
    int z[20] = {0};
    int rsl,count;
    rsl = combine(x,10,y,10,z);
    count = 20 - rsl;
    for (int i = 0; i < count; i = i + 1) {
        printf("%d ",z[i]);
    }
    puts("\n");
    printf("%d items haven't been merged.",rsl);
    
}
int combine(int a[],int ma,int b[],int mb,int c[]) {
    int count = 0, i = 0, j = 0, k = 0;
    while (i < ma && j < mb) {
        if (a[i] < b[j]) {
            c[k++] = a[i++];
        } else if (a[i] > b[j]) {
            c[k++] = b[j++];
        } else {
            c[k++] = a[i++];
            j = j + 1;
            count = count + 1;
        }
    }
    while (i < ma) {
        c[k++] = a[i++];
    }
    while (j < mb) {
        c[k++] = b[j++];
    }
    return count;
}
void Fun12_2(void) {
    int a[4][4] = {{-1,6,4,17},{8,3,9,10},{12,19,7,23},{4,14,21,20}};
    fun(a,4);
    for (int i = 0; i < 4; i = i + 1) {
        for (int j = 0; j < 4; j = j + 1) {
            printf("%4d",a[i][j]);
        }
        puts("\n");
    }
}
void fun(int p[][4],int n) {
    int max = p[0][0],max_i = 0,max_j = 0,temp;
    for (int i = 0; i < n; i = i + 1) {
        for(int j = 0; j < 4; j = j + 1) {
            if (p[i][j] > max) {
                max_i = i;
                max_j = j;
                max = p[i][j];
            }
        }
    }
    temp = p[0][0];
    p[0][0] = max;
    p[max_i][max_j] = temp;
    
    int min = p[0][0],min_i = 0,min_j = 0;
    for (int i = 0; i < n; i = i + 1) {
        for(int j = 0; j < 4; j = j + 1) {
            if (p[i][j] < min) {
                min_i = i;
                min_j = j;
                min = p[i][j];
            }
        }
    }
    temp = p[n-1][3];
    p[n-1][3] = min;
    p[min_i][min_j] = temp;
    
}
void Fun12_3(void) {
    int a[9][9] = {0},n;
    printf("Please enter n= ");
    scanf("%d",&n);
    if ( n <= 9 && n % 2 != 0) {
        magicmatrix(a,n);
        for (int i = 0; i < n; i = i + 1) {
            for (int j = 0; j < n; j = j + 1) {
                printf("%4d",a[i][j]);
            }
            puts("\n");
        }
    } else {
        puts("Invalid n, please enter again.");
    }
    
}
void magicmatrix(int (*a)[9],int n) {
    int now_i,now_j;
    a[0][n/2] = 1; now_i = 0; now_j = n/2;
    for (int z = 2; z <= n*n; z = z + 1) {
        now_j = now_j + 1;
        now_i = now_i - 1;
        if (now_i < 0 && now_j < n) {
            now_i = n-1;
            a[now_i][now_j] = z;
        } else if (now_i >= 0 && now_j >= n) {
            now_j = 0;
            a[now_i][now_j] = z;
        } else if (now_i < 0 && now_j >= n ) {
            now_i = now_i + 2;
            now_j = now_j - 1;
            a[now_i][now_j] = z;
        } else if (now_i >= 0 && now_j < n && a[now_i][now_j] != 0) {
            now_i = now_i + 2;
            now_j = now_j - 1;
            a[now_i][now_j] = z;
        } else {
            a[now_i][now_j] = z;
        }
    }
}
void Fun12_4(void) {
    int a[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}, min, max, now_i = 0, now_j = 0 ;
    int result[16][3] = {0}, count = 0;
    for (int i = 0; i < 4; i = i + 1) {
        max = a[i][0];
        for (int j = 0; j < 4; j = j + 1) {
            if (a[i][j] > max) {
                now_i = i;
                now_j = j;
                max = a[i][j];
            }
        }
        int k = 0;
            for (k = 0; k < 4; k = k + 1) {
                min = a[now_i][now_j];
                if (a[k][now_j] < min) {
                    break;
                }
            }
            if (k == 4) {
                result[count][0] = now_i;
                result[count][1] = now_j;
                result[count][2] = a[now_i][now_j];
                count = count + 1;
            }
        }
        
    for (int z = 0; z < count; z = z + 1) {
        printf("The point is a[%d][%d], the value is %d\n",result[z][0],result[z][1],result[z][2]);
    }
}
void Fun12_5(void) {
    int a[9][9] = {0};
    for (int k = 0; k < 10; k = k + 1) {
        int i = rand() % 9;
        int j = rand() % 9;
        if (a[i][j] != -1) {
            a[i][j] = -1;
        } else {
            k = k - 1;
        }
    }
    for (int i = 0; i < 9; i = i + 1) {
        for (int j = 0; j < 9; j = j + 1) {
            if (a[i][j] != -1) {
                int count = 0;
                if (i+1 < 9 && a[i+1][j] == -1) {
                    count = count + 1;
                }
                if (j+1 < 9 && a[i][j+1] == -1) {
                    count = count + 1;
                }
                if (i+1<9 && j+1<9 && a[i+1][j+1] == -1) {
                    count = count + 1;
                }
                if (i-1 >= 0 && a[i-1][j] == -1) {
                    count = count + 1;
                }
                if (j-1 >= 0 && a[i][j-1] == -1) {
                    count = count + 1;
                }
                if (i-1 >= 0 && j-1 >= 0 && a[i-1][j-1] == -1) {
                    count = count + 1;
                }
                if (i-1 >= 0 && j-1 >= 0 && a[i-1][j-1] == -1) {
                    count = count + 1;
                }
                if (i-1 >= 0 && j+1 < 9 && a[i-1][j+1] == -1) {
                    count = count + 1;
                }
                if (i+1 < 9 && j-1 >= 0 && a[i+1][j-1] == -1) {
                    count = count + 1;
                }
                if (count == 0) {
                    a[i][j] = 32;
                } else {
                    a[i][j] = count;
                }
                
            }
        }
    }
    for (int x = 0; x < 9; x = x + 1) {
        for (int y = 0; y < 9; y = y + 1) {
            if (a[x][y] == -1 ){
                printf("%c\t",15);
            } else if (a[x][y] == 32) {
                printf("%c\t",a[x][y]);
            } else {
                printf("%d\t",a[x][y]);
            }
            
        }
    }
}
void Fun12_6(void) {
    char s1[100], *p, index;
    int b[26] = {0};
    printf("Please enter: ");
    scanf("%s",s1);
    for (p = s1; *p != '\0'; p = p + 1) {
        if(isalpha(*p)) {
            *p = toupper(*p);
            index = *p - 'A';
            b[index] = b[index] + 1;
        }
    }
    for (int i = 0; i < 26; i = i + 1) {
        if (b[i] != 0) {
            index = i + 'A';
            printf("%c: %d\t",index,b[i]);
        }
    }
}
