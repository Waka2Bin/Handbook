#pragma once


class Rational {
private:
	int hight{ 0 };
	int low{ 1 };
	Rational(int hight, int low);
public:
	Rational& operator + () {

	}
	Rational& operator - () {

	}
	Rational& operator * () {

	}
	Rational& operator / () {

	}
	int Numerator() const{
		return hight;
	}
	int Denominator() const {
		return low;
	}
};