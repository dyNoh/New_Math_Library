#include "basicArith.h"
#include <iostream>

double Add(double num1, double num2)
{
	return num1+num2;
}

double Min(double num1, double num2)
{
	return num1-num2;
}

double Mul(double num1, double num2)
{
	return num1*num2;
}

double Div(double num1, double num2)
{
	return num1/num2;
}

double Sqrt(const double& num)
{
	// 이 부분에 num이 0 이하일 경우 예외처리
	/*if (num <= 0)
	{
		cout << "NaN" << endl;
		return 0.0;
	}*/

	double Xn = 1;		// Xn
	double XnP1 = 1;	// Xn+1

	while (1)
	{
		XnP1 = 0.5 * (XnP1 + (num / XnP1));

		if (Xn - XnP1 < 0.00001 && Xn - XnP1 > -0.00001)  // 정확도 |0.00001|
		{
			break;
		}

		Xn = XnP1;
	}

	return XnP1;
}

double Pow(const double & num, const int & n)
{
	double val = 1;

	if (n < 0)
	{
		for (int m = 0; m < -n; m++)
		{
			val *= (1 / num);
		}
		return val;
	}

	for (int m = 0; m < n; m++)
	{
		val *= num;
	}

	return val;
}

double Cos(const double & x)
{
	return 0.0;
}

double Sin(const double & x)
{
	double val = x;
	if (x < -180 || x > 180)
	{
		int temp = (int)(x / 180);
		if (temp > 0)
		{
			if (!(temp % 2))
				val = x - (180 * temp);
			else
				val = x - (180 * (temp + 1));
		}
		else if (temp < 0)
		{
			if (!(temp % 2))
				val = x + (180 * -temp);
			else
				val = x + (180 * (-temp + 1));
		}
	}
	double rad = val * PI / 180;
	double sum = rad;
	double result = rad;
	double fact = 1.0f;
	double powX = -Pow(rad);
	int i = 1;

	while (1)
	{
		fact *= ((2 * i) * (2 * i + 1));
		result *= powX;
		sum += (result / fact);
		if ((result / fact) < 0.00001 && (result / fact) > -0.00001) // 정밀도 0.00001
			return sum;
		i++;
	}
}

double Tan(const double & x)
{
	return 0.0;
}

/*
	테일러 급수로 대체
static double Sinus(double arg, int quad)
{
	double e, f;
	int k;
	double ysq;
	double x, y;
	double temp1, temp2;
	x = arg;
	if (x < 0)
	{
		x = -x;
		quad = quad + 2;
	}
	x = x * twoopi;
	if (x > 32764)
	{
		y = modf(x, &e);
		e = e + quad;
		modf(0.25*e, &f);
		quad = e - 4 * f;
	}
	else
	{
		k = x;
		y = x - k;
		quad = (quad + k) & 03;
	}
	if (quad & 01)
	{
		y = 1 - y;
	}
	if (quad > 1)
	{
		y = -y;
	}
	ysq = y*y;
	temp1 = ((((p4*ysq + p3)*ysq + p2)*ysq + p1)*ysq + p0)*y;
	temp2 = ((((ysq + q3)*ysq + q2)*ysq + q1)*ysq + q0);
	return(temp1 / temp2);
}

double Cos(double x)
{
	if (x * PI / 180 < 0.0)
		x = -x;
	return (Sinus(x * PI / 180, 1));
}

double Sin(double x)
{
	return (Sinus(x * PI / 180, 0));
}

double Tan(double x)
{
	if(x * PI / 180 < 0.0)
		return (Sinus(x * PI / 180, 0) / (Sinus(-x * PI / 180, 1)));
	return (Sinus(x * PI / 180, 0) / (Sinus(x * PI / 180, 1)));
}

*/


double PowE(const double & n)
{
	return 0.0;
}
