#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int extended_euclid(int a, int b)
{
    int x1, x2, x3;
    int y1, y2, y3;
    int t1, t2, t3;
    int q = 0;

    x1 = 1;
    x2 = 0;
    x3 = b;

    y1 = 0;
    y2 = 1;
    y3 = a;

    printf("  q     x1     x2     x3     y1     y2     y3\n");
    printf("---------------------------------------------\n");
    printf("    %6d %6d %6d %6d %6d %6d\n", x1, x2, x3, y1, y2, y3);

    while (1)
    {
        if (y3 == 0) return 0; //no inverse
        if (y3 == 1) return y2; // the answer

        q = x3 / y3;

        t1 = x1 - q * y1;
        t2 = x2 - q * y2;
        t3 = x3 - q * y3;

        x1 = y1;
        x2 = y2;
        x3 = y3;

        y1 = t1;
        y2 = t2;
        y3 = t3;

        printf("---------------------------------------------\n");
        printf("%3d %6d %6d %6d %6d %6d %6d\n", q, x1, x2, x3, y1, y2, y3);
    }
}

int gcd(int a, int b) {

    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}



int main()
{
    int m, n, d, e, k,t;  // m은 은닉된 메시지,n은 법 d 는개인키 e는 공개키 , k는 임의 ,t은닉메시지
    printf("은닉메시지 : ");
    scanf("%d", &m);
    printf("공개키 : ");
    scanf("%d", &e);
    printf("개인키 : ");
    scanf("%d", &d);
    printf("법 : ");
    scanf("%d", &n);

    k = 11;
    while (gcd(n, k) != 1) {
        printf("임의의 수 k (단 GCD(k,n)=1이여함) : ");
        scanf("%d", &k);
    }
    printf("step 1 \n");
    printf("t=m*k^e(mod n)\n");
    t = m;
    for (int i = 0; i < e; i++) {
        t *= k;
        t %= n;
    }
    printf("t= %d\n", t);
    printf("step 2 \n");
    printf("t^d=m^d*k (mod n)\n");
    int temp = t;
    for (int i = 0; i < d-1; i++) {
        t *= temp;
        t %= n;
    }
    printf("t^d  (mod n ) = %d\n", t);
    printf("step 3 \n");
    printf("확장유클리드 k와 n\n");
    int kinverse = extended_euclid(k, n);
    if (kinverse < 0) kinverse += n;
    printf("k의 역원은 %d\n", kinverse);
    t = t * kinverse % n;
    printf("밥의 서명 s = %d\n", t);

}
