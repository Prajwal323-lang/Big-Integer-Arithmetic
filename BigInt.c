#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "digits.h"
#define SIZE 310

int IsSmallerThanMax(char* );
int IsgreaterthanMin(char*);
void reverseStr(char*,int);
char* addNums(char*,char*);
void compareNums(char*,char*);
char* subtractNums(char*,char*);
char* findDiff(char*,char*);
char* findDiff(char*,char*);
char* multiplyNums(char*,char*);


int IsSmallerThanMax(char* str)
{
    int ret_val ;
    if(str[0] == '-')
    {
        ret_val = 1;
    }
    else
    {
        if(strlen(str) > strlen(MAX_NUMBER))
        {
            ret_val = 0;
        }
        else if(strlen(str) < strlen(MAX_NUMBER))
        {
            ret_val = 1;
        }
        else
        {
            if(strcmp(str,MAX_NUMBER) < 0 || strcmp(str,MAX_NUMBER) == 0)
            {
                ret_val = 1;
            }
            else
            {
                ret_val = 0;
            }
        }
    }
    return ret_val;
}

int IsgreaterthanMin(char *str){
    int ret_val;
    if(str[0] == '-'){
        if(strlen(str) > strlen(MIN_NUMBER))
        {
            ret_val = 0;
        }
        else if(strlen(str) < strlen(MIN_NUMBER))
        {
            ret_val = 1;
        }
        else
        {
            if(strcmp(str,MIN_NUMBER) > 0 || strcmp(str,MIN_NUMBER) == 0)
            {
                ret_val = 1;
            }
            else
            {
                ret_val = 0;
            }
        } 
    }
    else{
        ret_val = 1;
    }
    return ret_val;
}

void reverseStr(char* str, int len) {
    int s = 0, e = len - 1;
    char t;
    while (s < e) 
    {
        t = str[s];
        str[s] = str[e];
        str[e] = t;
        s++;
        e--;
    }
}


char* addNums(char* n1, char* n2) {
    static char res[SIZE];
    memset(res, 0, sizeof(res));

    int l1 = strlen(n1);
    int l2 = strlen(n2);

    int isNeg1 = 0;
    int isNeg2 = 0;
    isNeg1 = (n1[0] == '-');
    isNeg2 = (n2[0] == '-');
    if (isNeg1) {
        memmove(n1, n1 + 1, l1);
        l1--;
    }
    if (isNeg2) {
        memmove(n2, n2 + 1, l2);
        l2--;
    }
    reverseStr(n1, l1);
    reverseStr(n2, l2);
    if(isNeg1 && !isNeg2)
    {
        reverseStr(n1, l1);
        reverseStr(n2, l2);
        strcpy(res,findDiff(n2,n1));
    }
    else if(!isNeg1 && isNeg2)
    {
        reverseStr(n1, l1);
        reverseStr(n2, l2);
        strcpy(res,findDiff(n1,n2));
    }
    else{
        int cy = 0, i, sm;
        int idx = 0;

        for (i = 0; i < l1 || i < l2 || cy; i++) {
            int d1 = (i < l1) ? n1[i] - '0' : 0;
            int d2 = (i < l2) ? n2[i] - '0' : 0;

            sm = d1 + d2 + cy;
            cy = sm / 10;
            res[idx++] = (sm % 10) + '0';
        }
        res[idx] = '\0';

        reverseStr(res, idx);

        if (isNeg1 && isNeg2) {
            memmove(res + 1, res, strlen(res) + 1);
            res[0] = '-';
        }
    }
    return res;
}

int a = 0, c = 0, ad = -1;
int sg = -1;
void compareNums(char* s1, char* s2) {
    a = (s1[0] == '-') ? 1 : 0;
    c = (s2[0] == '-') ? 1 : 0;

    if (a) 
    {
        memmove(s1, s1 + 1, strlen(s1));
    }
    if (c) 
    {
        memmove(s2, s2 + 1, strlen(s2));
    }
    int l1 = strlen(s1);
    int l2 = strlen(s2);

    if (a == 1 && c == 0) 
    { 
        ad = 1;
        sg = 0;
    } 
    else if (a == 0 && c == 1) 
    {
        ad = 1;
        sg = 1;
    } 
    else if (a == 0 && c == 0) 
    {
        ad = 0;
        if (l1 < l2) {
            sg = 0;
        } else if (l1 > l2) {
            sg = 1;
        } else {
            if (strcmp(s1, s2) == 0) {
                sg = 1;
            } else {
                sg = (strcmp(s1, s2) > 0) ? 1 : 0;
            }
        }
    }
    else 
    {
        ad = 0;
        if (l1 < l2) {
            sg = 1;
        } else if (l1 > l2) {
            sg = 0;
        } else {
            if (strcmp(s1, s2) == 0) {
                sg = 1;
            } else {
                sg = (strcmp(s1, s2) < 0) ? 1 : 0;
            }
        }
    }
}

char* subtractNums(char* n1, char* n2) {
    static char res[SIZE];
    memset(res, 0, sizeof(res));

    int l1 = strlen(n1);
    int l2 = strlen(n2);

    reverseStr(n1, l1);
    reverseStr(n2, l2);

    int cy = 0, sub, i;
    int idx = 0;

    for (i = 0; i < l2; i++) {
        sub = (n1[i] - '0') - (n2[i] - '0') - cy;
        if (sub < 0) {
            sub += 10;
            cy = 1;
        } else {
            cy = 0;
        }
        res[idx++] = sub + '0';
    }

    for (i = l2; i < l1; i++) {
        sub = (n1[i] - '0') - cy;
        if (sub < 0) {
            sub += 10;
            cy = 1;
        } else {
            cy = 0;
        }
        res[idx++] = sub + '0';
    }

    while (idx > 1 && res[idx - 1] == '0') idx--;

    res[idx] = '\0';
    reverseStr(res, idx);
    return res;
}

char* findDiff(char* n1, char* n2) {
    compareNums(n1, n2);

    static char res[SIZE];
    memset(res, 0, sizeof(res));

    if (ad == 0 && sg == 0) {
        snprintf(res, sizeof(res), "-%s", subtractNums(n2, n1));
    } else if (ad == 0 && sg == 1) {
        strcpy(res, subtractNums(n1, n2));
    } else if (ad == 1 && sg == 0) {
        snprintf(res, sizeof(res), "-%s", addNums(n1, n2));
    } else {
        strcpy(res, addNums(n1, n2));
    }

    return res;
}

char* multiplyNums(char* n1, char* n2) {
    static char prod[SIZE];
    memset(prod, 0, sizeof(prod));

    int l1 = strlen(n1);
    int l2 = strlen(n2);

    reverseStr(n1, l1);
    reverseStr(n2, l2);

    int arr[2000] = {0};
    int i, j;

    for (i = 0; i < l1; i++) {
        for (j = 0; j < l2; j++) {
            arr[i + j] += (n1[i] - '0') * (n2[j] - '0');
        }
    }

    int cy = 0, idx = 0;

    for (i = 0; i < l1 + l2 || cy; i++) {
        int sm = arr[i] + cy;
        arr[i] = sm % 10;
        cy = sm / 10;
    }

    for (i = 0; i < l1 + l2 || arr[i]; i++) {
        prod[idx++] = arr[i] + '0';
    }

    prod[idx] = '\0';
    reverseStr(prod, idx);
    return prod;
}

int main() {
    char a1[SIZE] = NUMBER1; 
    char a2[SIZE] = NUMBER2;  
    if(!IsSmallerThanMax(a1) || !IsSmallerThanMax(a2) || !IsgreaterthanMin(a1) || !IsgreaterthanMin(a2))
    {
        printf("Out of bound Number");
    }
    else
    {
        int op;

        printf("Enter 1 for addition, 2 for subtraction, 3 for multiplication:\n");
        scanf("%d", &op);

        switch (op) {
            case 1:
            {
                char ans[SIZE];
                strcpy(ans,addNums(a1,a2));
                if(IsSmallerThanMax(ans) && IsgreaterthanMin(ans))
                {
                    printf("%s\n", ans);
                }
                else
                {
                    printf("Addition out of bound\n");
                }
                break;
            }
            case 2:
            {
                char ans[SIZE];
                strcpy(ans,findDiff(a1,a2));
                if(IsSmallerThanMax(ans) && IsgreaterthanMin(ans))
                {
                    printf("%s\n", ans);
                }
                else
                {
                    printf("Subtraction out of bound\n");
                }
                break;
            }
            case 3:
            {
                char ans[SIZE];
                strcpy(ans,multiplyNums(a1,a2));
                if(IsSmallerThanMax(ans) && IsgreaterthanMin(ans))
                {
                    printf("%s\n", ans);
                }
                else
                {
                    printf("Multiplication out of bound\n");
                }
                break;
            }
            default:
                printf("Invalid option.\n");
                break;
        }
    }
    return 0;
}