#include <stdio.h>
#include <math.h>


// G(6) = G(2)+F(1)+F(2)+F(2)+G(1)+F(2)+G(1)+G(2) = 13

void DecimalInBinary(int *a) // Workout1 Translation from decimal in binary
{
	int b = *a % 2;
	*a /= 2;
	if (*a> 1) DecimalInBinary(a);
	*a = *a * 10 + b;

}



void RaiseAPower(int *a, int b)  // Workout2 Numerialc value that you want to raise to a power.
{
	int c = *a;
	if (b - 1 > 1) RaiseAPower(a, b - 1);
	*a *= c;

}

void FastRaiseAPower(int *a, int b)
{
	int c = 1;
	if (b % 2 && b>1)
	{
		c = *a;
		FastRaiseAPower(a, b - 1);
	}
	else if (!(b % 2) && b > 1)
	{
		*a *= *a;
		FastRaiseAPower(a, b / 2);
	}
	*a *= c;
}

int G(int start, int end, int *i, char *oper, int *IndOper);   //This
int F(int start, int end, int *i, char *oper, int *IndOper);   //Is
int mult(int start, int end, int *i);		 //My
int NumberWay(int start, int end)   // workout 3
{
	int i = 0;
	char oper[100] = { 0 };
	int IndOper = 0;
	//mult(start, end, &i);
	G(start, end, &i, oper, &IndOper);
	F(start, end, &i, oper, &IndOper);
	return i;
}

int G(int start, int end, int *i, char *oper, int *IndOper)
{
	int j = 0;
	start++;
	oper[*IndOper] = 0;
	(*IndOper)++;
	if (start < end)
	{
		
		if (G(start, end, i, oper, IndOper))
		{
			(*IndOper)--;
			j = 1;
		}
		if (F(start, end, i, oper, IndOper))
		{
			(*IndOper)--;
			j = 1;
		}
		return j;
	}
	else if (start > end)
	{
		(*IndOper)--;
		return 0;
	}
	else
	{
		*i += 1;
		printf("\nWay n. '%d' ", *i);
		for (int k = 0; k < *IndOper; k++)
		{
			if (oper[k]) printf(" *2");
			else printf(" +1");
		}
		//(*IndOper)--;
		return 1;
	}

}

int F(int start, int end, int *i, char *oper, int *IndOper)
{
	int j = 0;
	start = start << 1;
	oper[*IndOper] = 1;
	(*IndOper)++;
	if (start < end)
	{
		
		if (G(start, end, i, oper, IndOper))
		{
			(*IndOper)--;
			j = 1;
		}
		if (F(start, end, i, oper, IndOper))
		{
			(*IndOper)--;
			j = 1;
		}
		return j;
	}
	else if (start > end)
	{
		(*IndOper)--;
		return 0;
	}
	else
	{
		*i += 1;
		printf("\nWay n. '%d' ", *i);
		for (int k = 0; k < *IndOper; k++)
		{
			if (oper[k]) printf(" *2");
			else printf(" +1");
		}
		//(*IndOper)--;
		return 1;
	}
}

//int mult(int start, int end , int *i)
//{
//	int S;
//	if (*i)
//	{
//
//	}
//	if (start < end)
//	{
//
//	}
//	return 0;
//}

//int inc(int start, int end)
//{
//	int S;
//	start++;
//	if (start < end)
//	{
//
//	}
//	return 0;
//}


int main(int argc, char *argv[])
{
	int dec = 38;
	DecimalInBinary(&dec);
	printf("%d\n", dec);

	int Num = 3;
	RaiseAPower(&Num, 4);
	printf("%d\n", Num);
	Num = 2;
	FastRaiseAPower(&Num, 5);
	printf("%d\n", Num);

	printf("\nAll way = %d", NumberWay(3, 20));

	return 0;
}