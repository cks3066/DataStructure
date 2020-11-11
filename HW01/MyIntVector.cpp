#include <iostream>
#include <stdlib.h>
#include <cassert>
#include <algorithm>
#include "MyIntVector.h"

using namespace std;

MyIntVector::MyIntVector() { cp = 8, sz = 0, data = new int[cp]; }
MyIntVector::MyIntVector(const MyIntVector& v)
{
	data = new int[v.cp];
	cp = v.cp;
	sz = v.sz;
	copy(v.data, v.data + sz, data);
}
MyIntVector::~MyIntVector() { delete[] data; }
MyIntVector MyIntVector::operator =(const MyIntVector& v)
{
	if (this == &v)
		return *this;
	if (cp != v.cp)
	{
		delete[] data;
		data = new int[cp];
		cp = v.cp;
	}
	sz = v.sz;
	copy(v.data, v.data + sz, data);
	return *this;
}
void MyIntVector::operator +=(const MyIntVector& v)
{
	int tmp = sz;
	sz += v.sz;
	while (cp < sz) cp *= 2;
	copy(v.data, v.data + v.sz, data + tmp);

}
int MyIntVector::operator [](const int i)
{
	assert(sz >= i);
	return data[i];
}
MyIntVector& MyIntVector::operator +(const MyIntVector& v)
{
	assert(sz == v.sz);

	static MyIntVector plus;
	delete[] plus.data;
	plus.data = new int[plus.cp];
	plus.sz = sz;
	for (int i = 0; i < sz; i++)
		plus.data[i] = (data[i] + v.data[i]);
	return plus;
}
MyIntVector& MyIntVector::operator -(const MyIntVector& v)
{
	assert(sz == v.sz);

	static MyIntVector minus;
	delete[] minus.data;
	minus.data = new int[cp];
	minus.sz = sz;
	for (int i = 0; i < sz; i++)
		minus.data[i] = (data[i] - v.data[i]);
	return minus;
}
MyIntVector& MyIntVector::operator *(const MyIntVector& v)
{
	assert(sz == v.sz);

	static MyIntVector mul;
	delete[] mul.data;
	mul.data = new int[cp];
	mul.sz = sz;
	for (int i = 0; i < sz; i++)
		mul.data[i] = (data[i] * v.data[i]);
	return mul;
}
MyIntVector& MyIntVector::operator -()
{
	for (int i = 0; i < sz; i++)
		data[i] = -data[i];
	return *this;
}
bool MyIntVector::operator ==(const MyIntVector& v)
{
	assert(sz == v.sz);

	bool check = true;

	for (int i = 0; i < sz; i++)
	{
		if (data[i] != v.data[i])
		{
			check = false;
			break;
		}
	}
	return check;
}
MyIntVector& MyIntVector::operator ()(int num)
{
	for (int i = 0; i < sz; i++)
		data[i] = num;
	return *this;
}
void MyIntVector::pop_back()
{
	data[--sz] = NULL;
}
void MyIntVector::push_back(int x)
{
	if (sz == cp) {
		int* tmp = new int[cp];
		for (int i = 0; i < cp; i++)
			tmp[i] = data[i];

		cp *= 2;

		delete[] data;
		data = new int[cp];

		for (int i = 0; i < cp; i++)
			data[i] = tmp[i];
	}
	data[sz++] = x;

}
size_t MyIntVector::capacity() const { return cp; }
size_t MyIntVector::size() const { return sz; }
void MyIntVector::reserve(size_t n)
{
	int* larger_array;
	if (n == cp)
		return;
	if (n < sz)
		n = sz;

	larger_array = new int[n];
	copy(data, data + sz, larger_array);
	delete[] data;
	data = larger_array;
	cp = n;
}
bool MyIntVector::is_empty() const
{
	if (sz == 0)
		return true;
	else
		return false;
}
void MyIntVector::clear()
{
	cp = 8;
	sz = 0;

	delete[] data;

	data = new int[cp];
}