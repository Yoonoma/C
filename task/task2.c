#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>
#define SIZE 100
/*
�������� ���������, ������� �������� ���� ������� � ������� �������, ���� ��� ������� �������� �����,
 ��� ���������� �������� �������� ����� ������� ��� �����, ���� ����� ������, ��� ��������� � ���������� �������.
��������� ��������� ������ ��������, ��������������� ����� ������� "\n" ������ ������ ������ ���� ������������� �
 ������ ��������, � ��� ������ ������ ���������� ��������� ������ ��������.*/


int main(){
    char s[SIZE];
    char mas[SIZE][SIZE+1];
    int i, j, n = 0, lenght = 0;

    while(fgets(s, SIZE+1, stdin) && s[0] != '\n')
    {
        lenght = strlen(s);
        if(s[lenght-1] == '\n')
            s[--lenght] = '\0';
        strncpy(mas[n], s, lenght);
        n++;
    }
    fflush(stdin);

    for(i = 0; i < n; ++i)
    {
        for(j = 0; j < lenght; ++j)
        {
            if(isdigit(mas[i][j]))
                if((mas[i][j] - '0') % 2 == 0)
                    break;
                else
                    continue;
            putchar(mas[i][j]);
        }
        putchar('\n');
    }

    return 0;
}
