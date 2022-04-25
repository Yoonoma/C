#include<stdio.h>

/*
����� ���������.
�������� � ��� ������� N ����������. �� ��� ����� ������������ ������� �� K �������.
������� ���������� ��������� ��� �������? �� �������� ������� ���������� �����������
����� - ����� ���������. ����������: ����� �������� � ��������� �� ���� ������ ����� �������.
*/

long factorial(int p) {
    int fact = 1;
    for (int i = 2; i <= p; i++)
        fact *= i;
    return fact;
}
float combin(int n, int k) {
    return (float)factorial(n) / factorial(k) / factorial(n-k);
}

int main(void){
    int n = 0, k = 0;
    scanf("%d%d",&n,&k);
    printf("%.2f", combin(n,k));
    return 0;
}
