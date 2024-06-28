#pragma once

#include <numeric>

class Rational {
private:
	int hight = 0;
	int low = 1;
	
	void Reduce() {
		int d = std::gcd(hight, low);
		hight /= d;
		low /= d;
		if (low < 0) {
			hight *= -1;
			low *= -1;
		}
	}

public:
	Rational() = default;// объявление дефолтного конструктора
	Rational(int h, int l) : hight(h), low(l) {  // объявление конструктора
		Reduce();
	}; 
	
	Rational operator + () const {
		return { hight, low };
	}
	Rational operator - () const {
		return Rational{ -hight, low };
	}

	Rational& operator + (int val) { // операции с инт
		hight += low * val;
		return *this;
	}
	Rational& operator + (Rational& obj) { // перегрузка операции с классом
		int h = hight;
		int l = low;
		hight = hight*obj.Denominator() + low*obj.Numerator();
		low = low * obj.Denominator();
		return *this;
	}
	
	Rational& operator - (int val) {
		hight -= low * val;
		return *this;
	}
	Rational& operator - (Rational& obj) { 
		int h = hight;
		int l = low;
		hight = hight * obj.Denominator() - low * obj.Numerator();
		low = low * obj.Denominator();
		return *this;
	}
	
	Rational& operator * (int val) {
		hight *= val;
		return *this;
	}
	Rational& operator * (Rational& obj) {
		int h = hight;
		int l = low;
		hight = h * obj.Numerator();
		low = l * obj.Denominator();
		return *this;
	}

	Rational& operator / (int val) {
		low = low * val;
		return *this;
	}
	Rational& operator / (Rational& obj) {
		int h = hight;
		int l = low;
		hight = h * obj.Denominator();
		low = l * obj.Numerator();
		return *this;
	}

	Rational& operator += (int val) {
		hight -= low;
	}


	int Numerator() const{  //2 геттера
		return hight;
	}
	int Denominator() const {
		return low;
	}
};