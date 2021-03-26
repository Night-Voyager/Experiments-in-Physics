#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.1415926
#define g 9.8

void main()
{
	FILE *fp;

	printf("本程序基于北京交通大学威海校区物理实验桌牌《刚体转动惯量的测量》制作。\n\n制作者：郝宇焜\n\n请注意数据的单位！\n\n");

	int i;

	float t1[9] = {0.0};
	float b1[6] = {0.0};
	printf("请输入匀减速的8个时间数据（单位为秒）\n");
	for (i=1; i<=8; i++)
	{
		scanf("%f", &t1[i]);
	}

	float t2[9] = {0.0};
	float b2[6] = {0.0};
	printf("请输入匀加速的8个时间数据（单位为秒）\n");
	for (i=1; i<=8; i++)
	{
		scanf("%f", &t2[i]);
	}

	float R;
	printf("请输入塔轮半径（单位为米）\n");
	scanf("%f", &R);

	float m;
	printf("请输入砝码质量（单位为千克）\n");
	scanf("%f", &m);

	for (i=1; i<=4; i++)
	{
		b1[i] = ( 2*PI*( i*t1[i+4]-(i+4)*t1[i] ) ) / ( t1[i]*t1[i]*t1[i+4]-t1[i+4]*t1[i+4]*t1[i] );
	}
	b1[5] = (b1[1]+b1[2]+b1[3]+b1[4])/4;
	printf(
		"\n          匀减速\n"
		" k        1        2        3        4\n"
		"t(s)   %.4f   %.4f   %.4f   %.4f\n"
		" k        5        6        7        8\n"
		"t(s)   %.4f   %.4f   %.4f   %.4f  __\n"
		"β1   %.4f  %.4f  %.4f  %.4f  β=%.4f\n",
		t1[1], t1[2], t1[3], t1[4], t1[5], t1[6], t1[7], t1[8],
		b1[1], b1[2], b1[3], b1[4], b1[5]
		);

	for (i=1; i<=4; i++)
	{
		b2[i] = ( 2*PI*( i*t2[i+4]-(i+4)*t2[i] ) ) / ( t2[i]*t2[i]*t2[i+4]-t2[i+4]*t2[i+4]*t2[i] );
	}
	b2[5] = (b2[1]+b2[2]+b2[3]+b2[4])/4;
	printf(
		"\n          匀加速\n"
		" k        1        2        3        4\n"
		"t(s)   %.4f   %.4f   %.4f   %.4f\n"
		" k        5        6        7        8\n"
		"t(s)   %.4f   %.4f   %.4f   %.4f  __\n"
		"β2    %.4f   %.4f   %.4f   %.4f  β=%.4f\n",
		t2[1], t2[2], t2[3], t2[4], t2[5], t2[6], t2[7], t2[8],
		b2[1], b2[2], b2[3], b2[4], b2[5]
		);

	float J;
	J = (m*R*(g-R*b2[5]))/(b2[5]-b1[5]);
	printf("\n转动惯量为：J = %f kg*m^2\n", J);

wrongInput:
	printf("\n是否保存为Excel文件？（Y：是；N：否）\n");
	char c;
	c = getchar();
	c = getchar();
	if (c=='y'||c=='Y')
	{
		time_t timep;
		struct tm *p;
		time (&timep);
		p=gmtime(&timep);

		char year[5], mon[3], mday[3], hour[3], min[3], sec[3];
		itoa(p->tm_year+1900, year, 10);
		itoa(p->tm_mon+1, mon, 10);
		itoa(p->tm_mday, mday, 10);
		itoa(p->tm_hour+8, hour, 10);
		itoa(p->tm_min, min, 10);
		itoa(p->tm_sec, sec, 10);

		char file_name[50] = "刚体转动惯量的测量";
		strcat(strcat(strcat(strcat(strcat(strcat(strcat(file_name, year), mon), mday), hour), min), sec), ".xls");

		fp = fopen(file_name, "w");

		fprintf(fp, "匀减速");

		fprintf(fp, "\nk\t");
		for (i=1; i<=4; i++)
			fprintf(fp, "%d\t", i);

		fprintf(fp, "\nt(s)\t");
		for (i=1; i<=4; i++)
			fprintf(fp, "%.4f\t", t1[i]);

		fprintf(fp, "\nk\t");
		for (i=5; i<=8; i++)
			fprintf(fp, "%d\t", i);

		fprintf(fp, "\nt(s)\t");
		for (i=5; i<=8; i++)
			fprintf(fp, "%.4f\t", t1[i]);

		fprintf(fp, "平均\nβ\t");
		for (i=1; i<=5; i++)
			fprintf(fp, "%.4f\t", b1[i]);

		fprintf(fp, "\n\n匀加速");

		fprintf(fp, "\nk\t");
		for (i=1; i<=4; i++)
			fprintf(fp, "%d\t", i);

		fprintf(fp, "\nt(s)\t");
		for (i=1; i<=4; i++)
			fprintf(fp, "%.4f\t", t2[i]);

		fprintf(fp, "\nk\t");
		for (i=5; i<=8; i++)
			fprintf(fp, "%d\t", i);

		fprintf(fp, "\nt(s)\t");
		for (i=5; i<=8; i++)
			fprintf(fp, "%.4f\t", t2[i]);

		fprintf(fp, "平均\nβ\t");
		for (i=1; i<=5; i++)
			fprintf(fp, "%.4f\t", b2[i]);

		fprintf(fp, "\n\nJ(kg*m^2)\t%f", J);

		fclose(fp);
	}
	else if (c=='n'||c=='N')
	{
		;
	}
	else
	{
		goto wrongInput;
	}
}
