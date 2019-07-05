#include <stdio.h>
#include <math.h>



double IndexMass(int m, int h)   //Задание 1
{
	return m / (h*h);
}

void average()  // Задание с лекции
{
	printf("\n write numbers. Exit =-1 \n");
	int counter = -1;
	float sum = 0;
	int in=0;
	do {
		sum += in;
		counter++;
		scanf("%d", &in);
	} while (in != -1);
	printf("\nmean = %.2f\n", (counter != 0) ? (float)(sum / counter) : 0.0);
	getchar();
}

void Choose(int old) //Задание 3 
{
	if ((old % 10 == 1) && (old != 11))
		printf("%d \nгод", old);
	else if ((old % 10 > 1) && (old % 10 < 5) && (old / 10 != 1))
		printf("%d \nгода", old);
	else printf("%d \nлет", old);
}

struct  root
{
	double x1;
	double x2;
};

struct root BinaryEquation(int a, int b, int c)  //Задание 2
{
	struct root Honda;
	double D = b*b - 4 * a*c;
	if (D > 0) {
		Honda.x1 = (0 - b) + sqrt(D) / 2 * a;
		Honda.x2= (0 - b) - sqrt(D) / 2 * a;
	}
	if (D == 0)
	{
		Honda.x1 = (0 - b) + sqrt(D) / 2 * a;
		Honda.x2 = acos(-1);
	}
	if (D<0)
	{
		Honda.x1 = acos(-1);
		Honda.x2 = acos(-1);
	}
	return Honda;
}

void Chess(int x1, int x2, int y1, int y2)    //Задание 4
{
	printf((x1 + x2 + y1 + y2) % 2 != 0 ? "\n equal" : "\n no equal");
}

void autoMorf10k(int Max)               //workout  5
{
	int divider = 100;
	int i = 1;
	while (i<sqrt(Max))
	{

		if (i*i % divider == i) printf("\n%d^2=%d", i, i*i);
		i++;
		if (!(i<divider)) divider *= 10;
	}
}

int main(int argc, char *argv[])
{
	double a = IndexMass(78,172);
	printf("Индекс массы тела %0.2f", a);

	Choose(25);
	struct root mazda;
	mazda = BinaryEquation(3, 6, 9);
	printf("Binary equals have root\n");
	if (mazda.x1 != acos(-1)) printf("x1=%0.2f\n", mazda.x1);
	if (mazda.x2 != acos(-1)) printf("x1=%0.2f\n", mazda.x2);
	Chess(1, 1, 5, 6);

	autoMorf10k(10000);

	average();
	return 0;
}