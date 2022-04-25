#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

/*
Abiturient: ФИО, Адрес (город), Оценки (как массив). Создать массив структур.
Вывести: в файл  массив структур. Добавить в файл

а) список абитуриентов, имеющих неудовлетворительные оценки;
б) список абитуриентов, сумма баллов у которых не меньше заданной;
в) выбрать N абитуриентов, имеющих самую высокую сумму баллов, и список абитуриентов, имеющих проходной балл.(он вводится с клавиатуры)
*/

struct Abiturient
{
    char fio[20];
    char address[20];
    int *mark;
    int countMark;
    int sumMarks;
}*card;

struct Abiturient unsatisfactory(struct Abiturient* card,int size);
struct Abiturient sumMarks(struct Abiturient* card, int size);
struct Abiturient excellentStudent(struct Abiturient* card, int size);

int main()
{
    //подключение кириллицы
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    FILE *f = fopen("Abiturient.txt","w+");

    int i,j,size;
    int marks,count = 0;
    printf("Введите количество абитуриентов :");
    scanf("%d",&size);

    card = (struct Abiturient*)malloc(size * sizeof(struct Abiturient));
    card->mark = (int *)malloc(size * 15 * sizeof(int));

fprintf(f,"\n              Студенты\n");
fprintf(f," ____________________________________\n");
fprintf(f,"|  Фамилия  |   Адрес   |   оценки   |\n");
fprintf(f,"|___________|___________|____________|\n");

//Ввод структуры ФИО, Адрес (город), Оценки (как массив) | запись в файл.
for(i = 0; i < size; i++)
{
    printf("Фамилия, адрес(улица), оценки(завершить ввод оценок - 0) :\n");
    scanf("%s%s",card[i].fio,card[i].address);
    fprintf(f,"|%7s    |%8s   |",card[i].fio,card[i].address);
    for(j = 0;; j++)
        {
        scanf("%d",&marks);
        if(marks == 0)
            break;
        card->mark[i*size+j] = marks;
        count++;
        fprintf(f,"%2d ",marks);
        }
    card[i].countMark = count;
    count = 0;
    fprintf(f,"  |\n|___________|___________|____________|\n");
}
fclose(f);

//Вывод структуры в консоль
printf("\n              Студенты\n");
printf(" ____________________________________\n");
printf("|  Фамилия  |   Адрес   |   оценки   |\n");
printf("|___________|___________|____________|\n");
for(i = 0; i < size; i++)
{
    printf("|%7s    |%8s   |",card[i].fio,card[i].address);
    for(j = 0; j < card[i].countMark; j++)
        {
        printf("%d ",card->mark[i*size+j]);
        }
    printf("  |\n|___________|___________|____________|\n");
}

unsatisfactory(card,size);
sumMarks(card,size);
excellentStudent(card,size);

free(card);
return 0;
}


//а) список абитуриентов, имеющих неудовлетворительные оценки;
struct Abiturient unsatisfactory(struct Abiturient* card,int size)
{
    FILE *f = fopen("Abiturient.txt","a+");
fprintf(f,"\nA1");
printf("\nA1");

fprintf(f,"\n    неудовлетворительные оценки\n");
fprintf(f," ____________________________________\n");
fprintf(f,"|  Фамилия  |   Адрес   |   оценки   |\n");
fprintf(f,"|___________|___________|____________|\n");

printf("\n    Неудовлетворительные оценки\n");
printf(" ____________________________________\n");
printf("|  Фамилия  |   Адрес   |   оценки   |\n");
printf("|___________|___________|____________|\n");
//вывод консоль + файл
for(int i = 0; i < size; i++)
    for(int j = 0; j < card[i].countMark; j++)
        if(card->mark[i*size+j] < 3)
        {
            printf("|%7s    |%8s   |",card[i].fio,card[i].address);
            fprintf(f,"|%7s    |%8s   |",card[i].fio,card[i].address);
            for(int k = 0; k < card[i].countMark; k++)
                {
                printf("%d ",card->mark[i*size+k]);
                fprintf(f,"%d ",card->mark[i*size+k]);
                }
            printf("  |\n|___________|___________|____________|\n");
            fprintf(f,"  |\n|___________|___________|____________|\n");
            break;
        }
fclose(f);
}

//б) список абитуриентов, сумма баллов у которых не меньше заданной;
struct Abiturient sumMarks(struct Abiturient* card, int size)
{
    FILE *f = fopen("Abiturient.txt","a+");

fprintf(f,"\nA2");
printf("\nA2");

fprintf(f,"\n      Сумма баллов студентов\n");
fprintf(f," ____________________________________\n");
fprintf(f,"|  Фамилия  |   Адрес   | Сум.оценок |\n");
fprintf(f,"|___________|___________|____________|\n");

printf("\n      Сумма баллов студентов\n");
printf(" ____________________________________\n");
printf("|  Фамилия  |   Адрес   | Сум.оценок |\n");
printf("|___________|___________|____________|\n");

for(int i = 0; i < size; i++)
{
    fprintf(f,"|%7s    |%8s   |",card[i].fio,card[i].address);
    printf("|%7s    |%8s   |",card[i].fio,card[i].address);

    int sum = 0;
    for(int j = 0; j < card[i].countMark; j++)
    {
        sum += card->mark[i*size+j];
    }
    card[i].sumMarks = sum;
    fprintf(f,"%7d     ",sum);
    fprintf(f,"|\n|___________|___________|____________|\n");
    printf("%7d     ",sum);
    printf("|\n|___________|___________|____________|\n");
}
int sb;
printf("Введите сумму баллов :");
scanf("%d",&sb);

fprintf(f,"\n    Сумма баллов студентов от %d\n",sb);
fprintf(f," ____________________________________\n");
fprintf(f,"|  Фамилия  |   Адрес   | Сум.оценок |\n");
fprintf(f,"|___________|___________|____________|\n");

printf("\n    Сумма баллов студентов от %d\n",sb);
printf(" ____________________________________\n");
printf("|  Фамилия  |   Адрес   | Сум.оценок |\n");
printf("|___________|___________|____________|\n");

for(int i = 0; i < size; i++)
    if(card[i].sumMarks > sb)
    {
        fprintf(f,"|%7s    |%8s   |%7d     |",card[i].fio,card[i].address,card[i].sumMarks);
        fprintf(f,"\n|___________|___________|____________|\n");
        printf("|%7s    |%8s   |%7d     |",card[i].fio,card[i].address,card[i].sumMarks);
        printf("\n|___________|___________|____________|\n");

    }
fclose(f);
}

//в) выбрать N абитуриентов, имеющих самую высокую сумму баллов, и список абитуриентов, имеющих проходной балл.(он вводится с клавиатуры)
struct Abiturient excellentStudent(struct Abiturient* card, int size)
{
    FILE *f = fopen("Abiturient.txt","a+");
    struct Abiturient tmp;

fprintf(f,"\nA3");
printf("\nA3\n");
int n,i,j;
float pb;

printf("Введите количество студентов :");
scanf("%d",&n);
printf("Введите проходной балл :");
scanf("%f",&pb);

fprintf(f,"\n  Самые высокие баллы (%d студентов)\n",n);
fprintf(f," ____________________________________\n");
fprintf(f,"|  Фамилия  |   Адрес   | Сум.оценок |\n");
fprintf(f,"|___________|___________|____________|\n");

printf("\n  Самые высокие баллы (%d студентов)\n",n);
printf(" ____________________________________\n");
printf("|  Фамилия  |   Адрес   | Сум.оценок |\n");
printf("|___________|___________|____________|\n");

//сортировка по сумме оценок
for(i = 0; i < size-1; i++)
    for(j = size - 1; j > i; j--)
        if(card[j-1].sumMarks < card[j].sumMarks)
        {tmp = card[j-1]; card[j-1] = card[j]; card[j] = tmp;}
//Вывод N абитуриентов, имеющих самую высокую сумму баллов.
for(i = 0; i < n; i++)
{
    printf("|%7s    |%8s   |%7d     |",card[i].fio,card[i].address,card[i].sumMarks);
    printf("\n|___________|___________|____________|\n");
    fprintf(f,"|%7s    |%8s   |%7d     |",card[i].fio,card[i].address,card[i].sumMarks);
    fprintf(f,"\n|___________|___________|____________|\n");
}

fprintf(f,"\n Студенты с проходным баллом выше - %.2f\n",pb);
fprintf(f," ______________________________________\n");
fprintf(f,"|  Фамилия  |   Адрес   | Средний балл |\n");
fprintf(f,"|___________|___________|______________|\n");

printf("\n Студенты с проходным баллом выше - %.2f\n",pb);
printf(" ______________________________________\n");
printf("|  Фамилия  |   Адрес   | Средний балл |\n");
printf("|___________|___________|______________|\n");
float a;
for(i = 0; i < size; i++)
    a = (float)card[i].sumMarks/card[i].countMark;
    if(a > pb)
    {
        printf("|%7s    |%8s   |%9.2f     |",card[i].fio,card[i].address,a);
        printf("\n|___________|___________|______________|\n");
        fprintf(f,"|%7s    |%8s   |%9.2f     |",card[i].fio,card[i].address,a);
        fprintf(f,"\n|___________|___________|______________|\n");
    }
fclose(f);
}
