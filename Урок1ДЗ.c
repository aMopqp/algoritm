#include <stdio.h>
#include <math.h>


double IndexMass(int m, int h)   //workout 1
{
	return m / (h*h);
}

void average()  // workout on lecture
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

void Choose(int old) //workout  3 
{
	if ((old % 10 == 1) && (old != 11))
		printf("%d \ngod", old);
	else if ((old % 10 > 1) && (old % 10 < 5) && (old / 10 != 1))
		printf("%d \ngodaа", old);
	else printf("%d \nlet", old);
}

void BinaryEquation(int a, int b, int c)  //workout  2
{
	double D = b*b - 4 * a*c;
	if (D > 0) {
		printf("\nx1 = %0.2f", ((0 - b) + sqrt(D)) / 2 * a);
		printf("\nx2 = %0.2f", ((0 - b) - sqrt(D)) / 2 * a);
	}
	if (D == 0)
	{
		printf("\nx1 = %0.2f", ((0 - b) + sqrt(D)) / 2 * a);
	}
	if (D<0)
	{
		printf("\nno root");
	}
}

void Chess(int x1, int x2, int y1, int y2)    //workout  4
{
	printf((x1 + x2 + y1 + y2) % 2 != 0 ? "\n equal" : "\n no equal");
}

void autoMorf10k()               //workout  5
{
	int i = 1;
	while (i<100)
	{
		if (i*i % 100 == i) printf("\n%d^2=%d",i ,i*i);
		i++;
	}
}

int main(int argc, char *argv[])
{
	double a = IndexMass(78,172);
	printf("»ндекс массы тела %0.2f", a);

	Choose(25);

	BinaryEquation(3, 6, 9);

	Chess(1, 1, 5, 6);

	autoMorf10k();

	average();
	return 0;
}