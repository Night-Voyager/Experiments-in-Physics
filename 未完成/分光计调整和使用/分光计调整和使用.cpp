#include <stdio.h>
#include <math.h>

void main()
{
	printf("本程序基于北京交通大学威海校区物理实验桌牌《分光计调整和使用》制作。\n\n制作者：郝宇焜\n\n请注意数据的单位！\n\n");

	int i;
	double a[6]={0.0};

	printf("请将角度的数据以小数的形式输入，本程序将自动将之转化为对应的度数。\n\n"
		"例1：\n\t原始数据196°8′ \t应输入196.08\t将转为196.133333°\n"
		"例2：\n\t原始数据195°10′\t应输入195.10或195.1\t将转为195.166667°\n\n");
	for (i=0; i<=5; i++)
	{
		scanf("%lf", &a[i]);
	}

	for (i=0; i<=5; i++)
	{
		a[i] = (int)a[i] + (a[i]-(int)a[i])*100/60;
	}

	for (i=0; i<=5; i++)
	{
		printf("%lf\n", a[i]);
	}

	double sum=0.0;
	for (i=0; i<=5; i++)
	{
		sum+=a[i];
	}

	printf("sum=%g\n", sum);

	double average=0.0;
	average = sum/6;

	printf("__\nθ=%g\n", average);

	double S=0;
	for (i=0; i<=5; i++)
	{
		S+=pow(a[i]-average, 2);
	}
	double s=0;
	s=sqrt(S/5);

	printf("S(θ)=%g\n3S(θ)=%g\n", s, 3*s);

	for (i=0; i<=5; i++)
	{
		printf("%g\n", a[i]-average);
	}

	double u;
	u=sqrt(S+1/10800);
	printf("u(θ)=%g\n", u);

	double E;
	E=u/average*100;
	printf("E(θ)=%g%%\n", E);
}