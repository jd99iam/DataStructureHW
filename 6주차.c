#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct
{
	double xpos;
	double ypos;
}Point;

double randNum(int a, int b) //a<b인 랜덤한 정수 반환 
{
	return (rand() % b + a) / (double)100;
}

double checkDistance(Point* p)
{
	return sqrt((0.5 - (p->xpos)) * (0.5 - (p->xpos)) + (0.5 - (p->ypos)) * (0.5 - (p->ypos)));
}

int main()
{
	srand(time(NULL));

	int count = 0;

	char s1[10] = { 0 };
	char s2[10] = { 0 };

	int n = 10000;


	FILE* f = fopen("square.txt", "wt");


	for (int i = 0; i < n; i++)
	{
		Point* p = (Point*)malloc(sizeof(Point));
		p->xpos = randNum(0, 100);
		p->ypos = randNum(0, 100);
		sprintf(s1, "%f\t", p->xpos);
		sprintf(s2, "%f", p->ypos);
		fputs(s1, f);
		fputs(s2, f);
		fputc('\n', f);

	}

	fclose(f);

	f = fopen("circle.txt", "wt");

	for (int i = 0; i < n; i++)
	{
		Point* p = (Point*)malloc(sizeof(Point));

		p->xpos = randNum(0, 100);
		p->ypos = randNum(0, 100);

		if (checkDistance(p) < 0.5)
		{
			sprintf(s1, "%f\t", p->xpos);
			sprintf(s2, "%f", p->ypos);
			fputs(s1, f);
			fputs(s2, f);
			fputc('\n', f);
			count += 1;
		}
	}

	double pi;
	pi = 4 * ((double)count / n);
	printf("%lf", pi);

	fclose(f);


	return 0;
}
