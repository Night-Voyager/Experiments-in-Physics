#include <stdio.h>
#include <math.h>
#include <windows.h>

#define PI 3.1415926

void main()
{
	printf("��������ڱ�����ͨ��ѧ����У������ʵ�����ơ�͸���դ���䡷������\n\n"
		"�����ߣ�����j��������\n\n"
		"�����н����ݵ�λ����Ϊ�ȣ��㣩�����롣\n");

	float a[5][3];

	int i, j;

	for (i=0; i<4; i++)
		for (j=0; j<3; j++)
			scanf("%f", &a[i][j]);

	for (j=0; j<3; j++)
		a[4][j] = ( fabs(a[0][j]-a[2][j]) + fabs(a[1][j]-a[3][j]) ) / 4;

	float average_phi = (a[4][0]+a[4][1]+a[4][2])/3;

	float lambda = sin(average_phi*PI/180)/300;

	for (j=0; j<3; j++)
		printf("\n��%d\n\t=(1/4)*(|S1-S1'|+|S2-S2'|)\n\t=(1/4)*(|%g��-%g��|+|%g��-%g��|)\n\t=%g��\n", j+1, a[0][j], a[2][j], a[1][j], a[3][j], a[4][j]);

	printf("\n__\n��=(��1+��2+��3)/3=%g��\n", average_phi);
	printf("\n��=dsin��/k=(sin%g��/300)mm=%fmm=%fnm\n\n", average_phi, lambda, lambda*1000000);

	system("pause");
}