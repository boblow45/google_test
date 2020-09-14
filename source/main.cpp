#include <iostream>
#include <iterator> // for iterators
#include <math.h>
#include <vector>

class Stack {
protected:
	virtual bool is_full(void) { }
	virtual bool is_empty(void) { }

public:
	virtual void push(int value) { }
	virtual int pop(void) { }
};

class Stackarray : public Stack {
private:
	int* m_stack;
	unsigned int m_length;
	unsigned int m_index;

	bool is_full(void) {
		if(this->m_index == this->m_length) {
			return true;
		}
		else {
			return false;
		}
	}

	bool is_empty(void) {
		if(this->m_index == 0) {
			return true;
		}
		else {
			return false;
		}
	}

public:
	Stackarray(int* stack, unsigned int len)
		: m_stack(stack)
		, m_length(len) {
		this->m_index = 0;
	}

	void push(int value) {
		if(this->is_full()) {
			return;
		}
		else {
			this->m_stack[this->m_index++] = value;
			return;
		}
	}

	int pop(void) {
		if(this->is_empty()) {
			return -1;
		}
		else {
			return this->m_stack[--this->m_index];
		}
	}
};

class Number {
private:
	int m_num;

public:
	Number()
		: m_num(0) { }

	Number(int num)
		: m_num(num) { }
	Number operator+(const Number& a) {
		Number temp;

		temp.m_num = this->m_num + a.m_num;
		return temp;
	}
};

class Stackll : public Stack { };

class Complex {
private:
	double m_real;
	double m_imagery;

public:
	Complex()
		: m_real(0)
		, m_imagery(0) { }

	Complex(double real)
		: m_real(real)
		, m_imagery(0) { }

	Complex(double real, double imagery)
		: m_real(real)
		, m_imagery(imagery) { }

	double get_real() {
		return this->m_real;
	}

	double get_imagery() {
		return this->m_imagery;
	}

	// Overload + operator to add two Box objects.
	Complex operator+(const Complex& a) {
		Complex complex;
		complex.m_real = this->m_real + a.m_real;
		complex.m_imagery = this->m_imagery + a.m_imagery;
		return complex;
	}

	Complex operator-(const Complex& a) {
		Complex complex;
		complex.m_real = this->m_real - a.m_real;
		complex.m_imagery = this->m_imagery - a.m_imagery;
		return complex;
	}

	Complex operator*(const Complex& a) {
		Complex complex;
		complex.m_real = this->m_real * a.m_real - this->m_imagery * a.m_imagery;
		complex.m_imagery = this->m_imagery * a.m_real + this->m_real * a.m_imagery;
		return complex;
	}

	Complex operator/(const Complex& a) {
		Complex complex;
		int denom = a.m_real * a.m_real + a.m_imagery * a.m_imagery;
		complex.m_real = this->m_real * a.m_real + this->m_imagery * a.m_imagery;
		complex.m_imagery = this->m_imagery * a.m_real - this->m_real * a.m_imagery;
		complex.m_real /= denom;
		complex.m_imagery /= denom;
		return complex;
	}
};

double reflect_coff(Complex& z1, Complex& z2);

double reflect_coff(Complex& z1, Complex& z2) {

	Complex num = (z1 - z2) / (z1 + z2);
	return sqrt(num.get_real() * num.get_real() + num.get_imagery() * num.get_imagery());
}

template <class T>
class myComplex {
private:
	T m_real;
	T m_img;

public:
	myComplex(T real, T img)
		: m_real(real)
		, m_img(img) { }

	myComplex(T real)
		: m_real(real)
		, m_img(0) { }

	myComplex()
		: m_real(0)
		, m_img(0) { }
};

template <class T>
T myMax(T x, T y) {
	return x > y ? x : y;
}

int main() {

	std::cout << "Hello World" << std::endl;

	Complex a(10);
	Complex b(3, -15);
	Complex c = a + b;
	std::cout << "Real: " << c.get_real() << " Imargy: " << c.get_imagery() << std::endl;
	auto refl_cof = reflect_coff(a, b);
	std::cout << "Reflection: " << refl_cof << std::endl;

	int stack_array[1024];

	Stackarray stack(stack_array, sizeof(stack_array) / sizeof(stack_array[0]));
	stack.push(1);
	stack.push(2);

	std::vector<int> v = {1, 2, 3, 4, 5};

	std::vector<int>::iterator ptr;

	for(auto ptr = v.begin(); ptr < v.end(); ptr++)
		std::cout << *ptr << std::endl;

	std::cout << "The Vector elements are :" << std::endl;

	std::cout << "Last: " << stack.pop() << std::endl;
	std::cout << "Last: " << stack.pop() << std::endl;

	std::vector<int>::iterator ptr1 = v.begin();

	std::vector<int>::iterator it1 = next(ptr1, 1);

	std::cout << *it1 << std::endl;

	// Add two more integers to vector
	v.push_back(25);
	v.push_back(13);
	auto temp = v.back();

	std::cout << myMax<int>(1, 13) << std::endl;

	std::cout << "vector is of type: " << typeid(temp).name() << std::endl;
	std::cout << "vector last: " << temp << std::endl;

	// Iterate and print values of vector
	for(const auto& ele : v) {
		std::cout << "vector value: " << ele << std::endl;
	}

	return 0;
}