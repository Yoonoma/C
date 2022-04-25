#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

/*
6.Train: Пункт назначения, Номер поезда, Время отправления,Число общих мест.

 Создать массив структур. Вывести в файл  массив структур. Добавить в файл:

а) список поездов, следующих до заданного пункта назначения и их количество;
б) список поездов, следующих до заданного пункта назначения и
отправляющихся после заданного часа;
в) список поездов, отсортированных по  пункту назначения

По одному из пунктов написать функцию
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
    //русский язык
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n = 3,i,j;

    //printf("Enter n - ");
    //scanf("%d",&n);

    struct  t = (struct Train)malloc(sizeof(struct Train)*n);

    char name[] = "Train.txt";
    FILE *f = fopen(name,"w+");

//Ввод в файл
fprintf(f,"\n                          Расписание поездов");
fprintf(f,"\n _______________________________________________________________________\n");
fprintf(f,"| Пункт назначения | Номер поезда | Время отправления | Число общ. мест |\n");
fprintf(f,"|__________________|______________|___________________|_________________|\n");

//Ввод структуры
for(i = 0; i < n; i++)
{
    printf("Пункт назначения, Номер поезда, Время отправления(часы | минуты),Число общих мест: \n");
    scanf("%s%d%d%d%d",t[i]->destination,&t[i]->train_number,&t[i]->time_hour,&t[i]->time_min,&t[i]->place_number);
    fprintf(f,"|%11s       |%9d     | %7d:%d        |%10d       |\n",t[i]->destination,t[i]->train_number,t[i]->time_hour,t[i]->time_min,t[i]->place_number);
    fprintf(f,"|__________________|______________|___________________|_________________|\n");
}

//Вывод структуры
printf("\nРасписание поездов");
printf("\n _______________________________________________________________________\n");
printf("| Пункт назначения | Номер поезда | Время отправления | Число общ. мест |\n");
printf("|__________________|______________|___________________|_________________|\n");

for(i = 0; i < n; i++)
{
printf("|%11s       |%9d     | %7d:%d        |%10d       |\n",t[i]->destination,t[i]->train_number,t[i]->time_hour,t[i]->time_min,t[i]->place_number);
printf("|__________________|______________|___________________|_________________|\n");
}
printf("*Данные записаны в файл*\n");

list(t,n);

}

//а) список поездов, следующих до заданного пункта назначения и их количество;

void list(struct Train (*p)[],int size)
{
char s[20];

printf("Введите пункт назначения : ");
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
