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

	printf("��������ڱ�����ͨ��ѧ����У������ʵ�����ơ�����ģ���ľ�̬��������������\n\n�����ߣ�����j\n\n��ע�����ݵĵ�λ��\n\n");

	printf("�������˿����L�����ף�\n");
	scanf("%f", &L);

	printf("�����뾵�浽��ߵľ���d1�����ף�\n");
	scanf("%f", &d1);

	printf("�������ܸ�ǰ�����ż�ľ���d2�����ף�\n");
	scanf("%f", &d2);

	printf("������������΢�������d0�����ף�\n");
	scanf("%f", &d0);

	printf("�������õ�6����˿ֱ��D�����ݣ����ף�\n");
	for (i=1; i<=6; i++)
	{
		scanf("%f", &D_measure[i]);
	}

	for (i=1; i<=6; i++)
		D_real[i] = D_measure[i] - d0;

	printf("������8������ʱ�ı�߿̶ȣ����ף�����С����\n");
	for (i=0; i<=7; i++)
	{
		scanf("%f", &s_up[i]);
	}

	printf("������8������ʱ�ı�߿̶ȣ����ף�����С����\n");
	for (i=0; i<=7; i++)
	{
		scanf("%f", &s_down[i]);
	}

	for (i=0; i<=7; i++)
		s_i[i] = (s_up[i]+s_down[i])/2;

	for (i=0; i<=7; i++)
		y[i] = s_i[i] - s_i[0];

	printf("\n       ��1 һ���Բ�������\n"
		"��˿����L(mm)    d1(mm)    d2(mm)\n"
		"   %.1f         %.1f     %.2f\n",
		L, d1, d2);
	Sleep(1000);

	printf("\n       ��2 ����˿ֱ����������\n"
		"    ������΢������� d0 = %.3f mm\n"
		"��˿ֱ��D(mm)   ",
		d0);
	for (i=1; i<=6; i++)
		printf("%d      ", i);
	printf("\n    ����ֵ  ");
	for (i=1; i<=6; i++)
		printf("  %.3f", D_measure[i]);
	printf("\n    ʵ��ֵ  ");
	for (i=1; i<=6; i++)
		printf("  %.3f", D_real[i]);
	Sleep(1000);

	printf("\n\n       ��3 �Ӽ���ʱ��߿̶����Ӧ��������");
	printf("\n   ������ֵm(kg)    ");
	for (i=0; i<=7; i++)
		printf("%-7.2f", (float)i);
	printf("\n����ʱ��߿̶� (mm) ");
	for (i=0; i<=7; i++)
		printf("%-7.1f", s_up[i]);
	printf("\n����ʱ��߿̶� (mm) ");
	for (i=0; i<=7; i++)
		printf("%-7.1f", s_down[i]);
	printf("\n  ƽ����߿̶�(mm)  ");
	for (i=0; i<=7; i++)
		printf("%-7.2f", s_i[i]);
	printf("\n��߿̶ȸı���y(mm) ");
	for (i=0; i<=7; i++)
		printf("%-7.2f", y[i]);
	printf("\n   y=si�Cs0(mm)");
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

	printf("\n\n\nʵ�����ݴ���\n\n"
		"1. ����ͼ����E����\n\n"
		"2. ����С���˷��������ݣ�xΪ������ֵm��yΪ��߿̶ȸı�����\n");

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
		"\tx = %.2f kg, y = %.2f mm, x��y = %.2f kg��mm, x^2 = %.2f kg^2,\n"
		"\tk = %.2f mm/kg, E = %.3g N/m^2\n\n",
		X, Y, XY, XX, k, E
		);

	float s;
	s = (s_i[7]-s_i[0])/7;

	int M=1;

	E = (8*M*g*L*d1)/(PI*D*D*d2*s*0.001*0.001);

	double uE;
	uE = sqrt( pow(0.5/d1, 2) + pow(0.02/d2, 2) + pow(0.5/L, 2) + pow(2*0.004/D, 2)/6 + pow(0.5/s, 2) ) * E;

	printf("3. D = %.3f mm, ��s = %.2f mm, E = %.3g N/m^2, u(E) = %.2g N/m^2\n\n", D, s, E, uE);

	printf("4. ������Ϊ%.3g%%\n\n", fabs(E-2.05e+11)*100/2.05e+11 );

	system("pause");
}