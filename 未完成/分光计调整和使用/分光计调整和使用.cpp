#include <stdio.h>
#include <math.h>

void main()
{
	printf("��������ڱ�����ͨ��ѧ����У������ʵ�����ơ��ֹ�Ƶ�����ʹ�á�������\n\n�����ߣ�����j\n\n��ע�����ݵĵ�λ��\n\n");

	int i;
	double a[6]={0.0};

	printf("�뽫�Ƕȵ�������С������ʽ���룬�������Զ���֮ת��Ϊ��Ӧ�Ķ�����\n\n"
		"��1��\n\tԭʼ����196��8�� \tӦ����196.08\t��תΪ196.133333��\n"
		"��2��\n\tԭʼ����195��10��\tӦ����195.10��195.1\t��תΪ195.166667��\n\n");
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

	printf("__\n��=%g\n", average);

	double S=0;
	for (i=0; i<=5; i++)
	{
		S+=pow(a[i]-average, 2);
	}
	double s=0;
	s=sqrt(S/5);

	printf("S(��)=%g\n3S(��)=%g\n", s, 3*s);

	for (i=0; i<=5; i++)
	{
		printf("%g\n", a[i]-average);
	}

	double u;
	u=sqrt(S+1/10800);
	printf("u(��)=%g\n", u);

	double E;
	E=u/average*100;
	printf("E(��)=%g%%\n", E);
}