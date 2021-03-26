#include <stdio.h>
#include <math.h>

void main()
{
	double C15[6]={0.0}, C5[6]={0.0}, C_5[6]={0.0}, C_15[6]={0.0}, D15[6]={0.0}, D5[6]={0.0};
	int i;

	printf("请输入6次测量的C15的数据（毫米）\n");
	for (i=0; i<=5; i++)
		scanf("%lf", &C15[i]);

	printf("请输入6次测量的C5的数据（毫米）\n");
	for (i=0; i<=5; i++)
		scanf("%lf", &C5[i]);

	printf("请输入6次测量的C5'的数据（毫米）\n");
	for (i=0; i<=5; i++)
		scanf("%lf", &C_5[i]);

	printf("请输入6次测量的C15'的数据（毫米）\n");
	for (i=0; i<=5; i++)
		scanf("%lf", &C_15[i]);

	for (i=0; i<=5; i++)
	{
		D15[i] = fabs(C15[i]-C_15[i]);
		D5[i] = fabs(C5[i]-C_5[i]);
	}

	printf("原始数据列表\n"
		"                     测量数据                计算结果\n"
		"测量次数    C15     C5      C5'     C15'    D15    D5  \n");
	for (i=0; i<6; i++)
		printf("    %d     %.3f  %.3f  %.3f  %.3f   %.3f  %.3f\n", i+1, C15[i], C5[i], C_5[i], C_15[i], D15[i], D5[i]);

	double sum, average, Sum, Average, S;

	printf("\n对于设备\n   0.01mm\nuB=------=%gmm\n    √3", 0.01/sqrt(3));

	printf("\n\n对于C15");
	for (i=0, sum=0.0; i<6; i++)
		sum += C15[i];
	average = sum/6;
	for (i=0, Sum=0.0; i<6; i++)
		Sum += (C15[i]-average)*(C15[i]-average);
	Average = Sum/5;
	S = sqrt(Average);
	double uAC15 = S;
	printf("          ___\n");
	printf("∑C15=%.3fmm, C15=%gmm, S(C15)=%gmm\n", sum, average, S);
	printf("uA=S(C15)=%gmm\n", S);
	printf("u(C15)=√(uA^2+uB^2)=%gmm\n", sqrt(S*S+0.0001/3));
	printf("所以\n  C15=%g±%gmm\n  E(C15)=%g%%", average, sqrt(S*S+0.0001/3), sqrt(S*S+0.0001/3)/average*100);

	printf("\n\n对于C5");
	for (i=0, sum=0.0; i<6; i++)
		sum += C5[i];
	average = sum/6;
	for (i=0, Sum=0.0; i<6; i++)
		Sum += (C5[i]-average)*(C5[i]-average);
	Average = Sum/5;
	S = sqrt(Average);
	double uAC5 = S;
	printf("          __\n");
	printf("∑C5=%.3fmm, C5=%gmm, S(C5)=%gmm\n", sum, average, S);
	printf("uA=S(C5)=%gmm\n", S);
	printf("u(C5)=√(uA^2+uB^2)=%gmm\n", sqrt(S*S+0.0001/3));
	printf("所以\n  C5=%g±%gmm\n  E(C5)=%g%%", average, sqrt(S*S+0.0001/3), sqrt(S*S+0.0001/3)/average*100);

	printf("\n\n对于C5'");
	for (i=0, sum=0.0; i<6; i++)
		sum += C_5[i];
	average = sum/6;
	for (i=0, Sum=0.0; i<6; i++)
		Sum += (C_5[i]-average)*(C_5[i]-average);
	Average = Sum/5;
	S = sqrt(Average);
	double uAC_5 = S;
	printf("          ___\n");
	printf("∑C5'=%.3fmm, C5'=%gmm, S(C5')=%gmm\n", sum, average, S);
	printf("uA=S(C5')=%gmm\n", S);
	printf("u(C5')=√(uA^2+uB^2)=%gmm\n", sqrt(S*S+0.0001/3));
	printf("所以\n  C5'=%g±%gmm\n  E(C5')=%g%%", average, sqrt(S*S+0.0001/3), sqrt(S*S+0.0001/3)/average*100);

	printf("\n\n对于C15'");
	for (i=0, sum=0.0; i<6; i++)
		sum += C_15[i];
	average = sum/6;
	for (i=0, Sum=0.0; i<6; i++)
		Sum += (C_15[i]-average)*(C_15[i]-average);
	Average = Sum/5;
	S = sqrt(Average);
	double uAC_15 = S;
	printf("          ____\n");
	printf("∑C15'=%.3fmm, C15'=%gmm, S(C15')=%gmm\n", sum, average, S);
	printf("uA=S(C15')=%gmm\n", S);
	printf("u(C15')=√(uA^2+uB^2)=%gmm\n", sqrt(S*S+0.0001/3));
	printf("所以\n  C15'=%g±%gmm\n  E(C15')=%g%%", average, sqrt(S*S+0.0001/3), sqrt(S*S+0.0001/3)/average*100);

	printf("\n\n对于D15");
	for (i=0, sum=0.0; i<6; i++)
		sum += D15[i];
	average = sum/6;
	printf("         ___\n");
	printf("∑D15=%.3fmm, D15=%gmm\n", sum, average);
	double uD15 = sqrt(uAC15*uAC15+uAC_15*uAC_15);
	printf("u(D15)=√(u(C15)^2+u(C15')^2)=%g", uD15);

	printf("\n\n对于D5");
	for (i=0, sum=0.0; i<6; i++)
		sum += D5[i];
	average = sum/6;
	printf("         __\n");
	printf("∑D5=%.3fmm, D5=%gmm\n", sum, average);
	double uD5 = sqrt(uAC5*uAC5+uAC_5*uAC_5);
	printf("u(D5)=√(u(C5)^2+u(C5')^2)=%g", uD5);
}