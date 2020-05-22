#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**********************
ʾ�� 1:
����: 123
��� : "One Hundred Twenty Three"

ʾ�� 2 :
���� : 12345
��� : "Twelve Thousand Three Hundred Forty Five"

ʾ�� 3 :
���� : 1234567
��� : "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

ʾ�� 4 :
���� : 1234567891
��� : "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
*/


const char *ge[] = {
    "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
};
const char *shi1[] = {
    "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen",
};
const char *shi2[] = {
    "Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety",
};

#define N 2000
char result[N] = { 0 };
bool appended = false;

void baishige(int n)
{
    int b = (n / 100) % 10;
    n %= 100;
    if (b) { // ��λ
        if (appended) {
            strcat(result, " ");
        }
        strcat(result, ge[b]);
        strcat(result, " Hundred");
        appended = true;
    }
    int s = n / 10;
    n %= 10;
    if (s) { // ʮλ
        if (appended) {
            strcat(result, " ");
        }
        if (s == 1) {
            strcat(result, shi1[n]);
            n = 0; // ����Ҫ�ٿ���λ��
        } else {
            strcat(result, shi2[s]);
        }
        appended = true;
    }
    if (n) { // ��λ
        if (appended) {
            strcat(result, " ");
        }
        strcat(result, ge[n]);
        appended = true;
    }
}

#define BILLION 1000000000
#define MILLION 1000000
#define THOUSAND 1000
char *numberToWords(int n)
{
    if (n <= 0) {
        strcpy(result, "Zero");
        return result;
    }
    appended = false;
    memset(result, 0, sizeof(result));
    int b = n / BILLION;
    n %= BILLION;
    if (b) { // BILLION
        baishige(b);
        strcat(result, " Billion");
    }
    int m = n / MILLION;
    n %= MILLION;
    if (m) { // MILLION
        baishige(m);
        strcat(result, " Million");
    }
    int t = n / THOUSAND;
    n %= THOUSAND;
    if (t) { // ǧλ
        baishige(t);
        strcat(result, " Thousand");
    }
    baishige(n);
    return result;
}

int main()
{
    /*****************************
    */
    // int n = 123; // One Hundred Twenty Three
    // int n = 12345; // Twelve Thousand Three Hundred Forty Five
    // int n = 1234567; // One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven
    int n = 1234567891; // One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One
    printf("%s", numberToWords(n));
    return 0;
}

