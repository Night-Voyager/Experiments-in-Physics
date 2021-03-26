#include <stdio.h>
#include <windows.h>
#include <math.h>

#define PI 3.1415926
#define g 9.8

void main()
{
	float L, d0, d1, d2;
	float D_measure[7] = {0.0};
	float D_real[7] = {0.0};
	float s_up[8] = {0.0};
	float s_down[8] = {0.0};
	float s_i[8] = {0.0};
	float y[8] = {0.0};
	int i;

	printf("本程序基于北京交通大学威海校区物理实验桌牌《杨氏模量的静态法测量》制作。\n\n制作者：郝宇焜\n\n请注意数据的单位！\n\n");

	printf("请输入钢丝长度L（毫米）\n");
	scanf("%f", &L);

	printf("请输入镜面到标尺的距离d1（毫米）\n");
	scanf("%f", &d1);

	printf("请输入光杠杆前后两脚间的距离d2（毫米）\n");
	scanf("%f", &d2);

	printf("请输入螺旋测微器的零差d0（毫米）\n");
	scanf("%f", &d0);

	printf("请输入测得的6个钢丝直径D的数据（毫米）\n");
	for (i=1; i<=6; i++)
	{
		scanf("%f", &D_measure[i]);
	}

	for (i=1; i<=6; i++)
		D_real[i] = D_measure[i] - d0;

	printf("请输入8个加力时的标尺刻度（毫米）（由小到大）\n");
	for (i=0; i<=7; i++)
	{
		scanf("%f", &s_up[i]);
	}

	printf("请输入8个减力时的标尺刻度（毫米）（由小到大）\n");
	for (i=0; i<=7; i++)
	{
		scanf("%f", &s_down[i]);
	}

	for (i=0; i<=7; i++)
		s_i[i] = (s_up[i]+s_down[i])/2;

	for (i=0; i<=7; i++)
		y[i] = s_i[i] - s_i[0];

	printf("\n       表1 一次性测量数据\n"
		"钢丝长度L(mm)    d1(mm)    d2(mm)\n"
		"   %.1f         %.1f     %.2f\n",
		L, d1, d2);
	Sleep(1000);

	printf("\n       表2 金属丝直径测量数据\n"
		"    螺旋测微器的零差 d0 = %.3f mm\n"
		"钢丝直径D(mm)   ",
		d0);
	for (i=1; i<=6; i++)
		printf("%d      ", i);
	printf("\n    测量值  ");
	for (i=1; i<=6; i++)
		printf("  %.3f", D_measure[i]);
	printf("\n    实际值  ");
	for (i=1; i<=6; i++)
		printf("  %.3f", D_real[i]);
	Sleep(1000);

	printf("\n\n       表3 加减力时标尺刻度与对应拉力数据");
	printf("\n   拉力视值m(kg)    ");
	for (i=0; i<=7; i++)
		printf("%-7.2f", (float)i);
	printf("\n加力时标尺刻度 (mm) ");
	for (i=0; i<=7; i++)
		printf("%-7.1f", s_up[i]);
	printf("\n减力时标尺刻度 (mm) ");
	for (i=0; i<=7; i++)
		printf("%-7.1f", s_down[i]);
	printf("\n  平均标尺刻度(mm)  ");
	for (i=0; i<=7; i++)
		printf("%-7.2f", s_i[i]);
	printf("\n标尺刻度改变量y(mm) ");
	for (i=0; i<=7; i++)
		printf("%-7.2f", y[i]);
	printf("\n   y=si–s0(mm)");
	Sleep(1000);

	float X, Y, XY, XX;

	X = 3.5;

	Y = 0;
	for (i=0; i<=7; i++)
		Y += y[i];
	Y = Y/8;

	XY = 0;
	for (i=0; i<=7; i++)
		XY += i*y[i];
	XY = XY/8;

	XX = 0;
	for (i=0; i<=7; i++)
		XX += i*i;
	XX = XX/8;

	printf("\n\n\n实验数据处理：\n\n"
		"1. 用作图法求E：略\n\n"
		"2. 用最小二乘法处理数据（x为拉力视值m，y为标尺刻度改变量）\n");

	double k;
	k = (X*Y-XY)/(X*X-XX);

	float D=0;
	for (i=1; i<=6; i++)
		D += D_real[i];
	D = D/6;

	double E;
	E = (8*g*L*d1)/(PI*D*D*d2*k*0.001*0.001);

	printf(
		"\t_            _             ____                  ___\n"
		"\tx = %.2f kg, y = %.2f mm, x·y = %.2f kg·mm, x^2 = %.2f kg^2,\n"
		"\tk = %.2f mm/kg, E = %.3g N/m^2\n\n",
		X, Y, XY, XX, k, E
		);

	float s;
	s = (s_i[7]-s_i[0])/7;

	int M=1;

	E = (8*M*g*L*d1)/(PI*D*D*d2*s*0.001*0.001);

	double uE;
	uE = sqrt( pow(0.5/d1, 2) + pow(0.02/d2, 2) + pow(0.5/L, 2) + pow(2*0.004/D, 2)/6 + pow(0.5/s, 2) ) * E;

	printf("3. D = %.3f mm, Δs = %.2f mm, E = %.3g N/m^2, u(E) = %.2g N/m^2\n\n", D, s, E, uE);

	printf("4. 相对误差为%.3g%%\n\n", fabs(E-2.05e+11)*100/2.05e+11 );

	system("pause");
}