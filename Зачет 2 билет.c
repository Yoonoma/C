#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

/*
6.Train: ����� ����������, ����� ������, ����� �����������,����� ����� ����.

 ������� ������ ��������. ������� � ����  ������ ��������. �������� � ����:

�) ������ �������, ��������� �� ��������� ������ ���������� � �� ����������;
�) ������ �������, ��������� �� ��������� ������ ���������� �
�������������� ����� ��������� ����;
�) ������ �������, ��������������� ��  ������ ����������

�� ������ �� ������� �������� �������
*/

struct Train
{
    char destination[30];
    int train_number;
    int time_hour;
    int time_min;
    int place_number;
};


int main()
{
    //������� ����
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n = 3,i,j;

    //printf("Enter n - ");
    //scanf("%d",&n);

    struct  t = (struct Train)malloc(sizeof(struct Train)*n);

    char name[] = "Train.txt";
    FILE *f = fopen(name,"w+");

//���� � ����
fprintf(f,"\n                          ���������� �������");
fprintf(f,"\n _______________________________________________________________________\n");
fprintf(f,"| ����� ���������� | ����� ������ | ����� ����������� | ����� ���. ���� |\n");
fprintf(f,"|__________________|______________|___________________|_________________|\n");

//���� ���������
for(i = 0; i < n; i++)
{
    printf("����� ����������, ����� ������, ����� �����������(���� | ������),����� ����� ����: \n");
    scanf("%s%d%d%d%d",t[i]->destination,&t[i]->train_number,&t[i]->time_hour,&t[i]->time_min,&t[i]->place_number);
    fprintf(f,"|%11s       |%9d     | %7d:%d        |%10d       |\n",t[i]->destination,t[i]->train_number,t[i]->time_hour,t[i]->time_min,t[i]->place_number);
    fprintf(f,"|__________________|______________|___________________|_________________|\n");
}

//����� ���������
printf("\n���������� �������");
printf("\n _______________________________________________________________________\n");
printf("| ����� ���������� | ����� ������ | ����� ����������� | ����� ���. ���� |\n");
printf("|__________________|______________|___________________|_________________|\n");

for(i = 0; i < n; i++)
{
printf("|%11s       |%9d     | %7d:%d        |%10d       |\n",t[i]->destination,t[i]->train_number,t[i]->time_hour,t[i]->time_min,t[i]->place_number);
printf("|__________________|______________|___________________|_________________|\n");
}
printf("*������ �������� � ����*\n");

list(t,n);

}

//�) ������ �������, ��������� �� ��������� ������ ���������� � �� ����������;

void list(struct Train (*p)[],int size)
{
char s[20];

printf("������� ����� ���������� : ");
scanf("%s",s);
printf("%s",s);

for(int i = 0; i < size; i++)
{
    if(strcmp(*(p[i]->place_number),s))
    {
        printf("134");
    }
}
}
