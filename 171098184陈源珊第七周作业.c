//
//  main.c
//  Week_7
//
//  Created by 陈源珊 on 2020/3/26.
//  Copyright © 2020 陈源珊. All rights reserved.
//

#include <stdio.h>
void Fun7_1(void);
void Fun7_2(void);
void Fun7_3(void);
void Fun7_4(void);
void Fun7_5(void);
void Fun7_6(void);
void Fun7_7(void);
void Fun7_8(void);
int main() {
    int c;
    while(1) {
        putchar('\n');
        puts("1. 钱币兑换方案");
        puts("2. 找出满足条件的十进制3位数");
        puts("3. 图书分配方案");
        puts("4. 验证算式PEAR-ARA=PEA");
        puts("5. 计算鸡兔数量");
        puts("6. 找出做好事的人");
        puts("7. 计算丢番图的寿命");
        puts("8.计算韩信最少有多少兵");
        puts("0. 退出");
        puts("输入命令（0~8）:");
        fflush(stdin);     /*清空标准输入缓冲区 */
        scanf("%d",&c);    /*接收输入命令*/
        switch(c)          /*根据输入命令调用相关函数*/
        {
            case 0:  return 0;
            case 1:  Fun7_1();  break;
            case 2:  Fun7_2();  break;
            case 3:  Fun7_3();  break;
            case 4:  Fun7_4();  break;
            case 5:  Fun7_5();  break;
            case 6:  Fun7_6();  break;
            case 7:  Fun7_7();  break;
            case 8: Fun7_8();   break;
            default:  printf("\n 输入命令错，请重新输入! ");
        }
    }
}
void Fun7_1(void) {
    int count = 0;
    for (int x = 0; x <= 2; x = x + 1) {
        for (int y = 0; y <= 5; y = y + 1) {
            for (int z = 0; z <= 10; z = z + 1) {
                if (50 * x + 20 * y + 10 * z == 100 ) {
                    count = count + 1;
                    printf("50元：%d张，20元：%d张，10元：%d张\n",x,y,z);
                }
            }
        }
    }
    printf("共有%d种兑换方案",count);
    
}
void Fun7_2(void) {
    int outcome;
    for (int i = 1; i <= 4; i = i + 1) {
        for (int j = 1; j <= 4; j = j + 1) {
            if (i == j) {
                continue;
            }
            for (int k = 1; k <= 4; k = k + 1) {
                if (k == i || k == j) {
                    continue;
                }
                outcome = i * 100 + j * 10 + k;
                printf("%d ",outcome);
            }
        }
    }
}
void Fun7_3(void) {
    int count = 0;
    for (int i = 1; i <= 9; i = i + 1) {
        for (int j = 1; j <= 8; j = j + 1) {
            for (int k = 1; k <= 7; k = k + 1) {
                
                if (23 - i - j - k >= 1 && 23 - i - j - k <= 6) {
                    count = count + 1;
                    printf("第%d种分法:\t甲%d本\t乙%d本\t丙%d本\t丁%d本\n",count,i,j,k,23 - i - j - k);
                }
            }
        }
    }
}
void Fun7_4(void) {
    int first,second,third;
    for (int p = 0; p <= 9; p = p + 1) {
        for (int e = 0; e <= 9; e = e + 1) {
            if (p == e) continue;
            for (int a = 0; a <= 9; a = a + 1) {
                if (a == e || a == p) continue;
                for (int r = 0; r <= 9; r = r + 1) {
                    if (r == a || r == e || r == p) continue;
                    first = p * 1000 + e * 100 + a * 10 + r;
                    second = a * 100 + r * 10 + a;
                    third = p * 100 + e * 10 + a;
                    if ((first - second) == third ) {
                        printf("p:%d,e:%d,a:%d,r:%d\t%04d-%03d=%03d\n",p,e,a,r,first,second,third);
                    }
                }
            }
        }
    }
}
void Fun7_5(void) {
    for (int ckn = 0; ckn <= 35; ckn = ckn + 1) {
        int rbt = 35 - ckn;
        if (2 * ckn + 4 * rbt == 94) {
            printf("鸡%d只，兔%d只",ckn,rbt);
        }
    }
    
}
void Fun7_6(void) {
    int t1, t2, t3, t4;
    for (int a = 0; a <= 1; a = a + 1) {
        for (int b = 0; b <= 1; b = b + 1) {
            for (int c = 0; c <= 1; c = c + 1) {
                for (int d = 0; d <= 1; d = d + 1) {
                    t1 = (a != 1);
                    t2 = (c == 1);
                    t3 = (d == 1);
                    t4 = (!t3);
                    if (t1 + t2 + t3 + t4 == 3 && a + b + c + d == 1) {
                        if (a == 1) {
                            printf("做好事的人是A");
                        } else if (b == 1) {
                            printf("做好事的人是B");
                        } else if (c == 1) {
                            printf("做好事的人是C");
                        } else if (d == 1) {
                            printf("做好事的人是D");
                        }
                    }
                }
            }
        }
    }
    
}
void Fun7_7(void) {
    for (double x = 10; x <= 100; x = x + 1) {
        double child = x / 6.0;
        double young = child + x / 12.0;
        double family = young + x / 7.0;
        double born = family + 5;
        double die = born + x / 2.0 + 4;
        if (die == x) {
            printf("丢番图活到%.lf岁",x);
        }
    }
    
}
void Fun7_8(void) {
    int num = 10;
    while(1) {
        if (num % 5 == 1 && num % 6 == 5 && num % 7 == 4 && num % 11 == 10 ) {
            printf("韩信最少有%d个兵",num);
            break;
        }
        num = num + 1;
    }
}
