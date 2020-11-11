/*
자료구조 HW1
2015405060 온승찬
*/

//MyIntVector 체크
//printf() , scanf() 함수 사용 x
// vector 사용 x
// 전역 변수 사용 x
// precondition , postcondition 작성

#ifndef MYINTVECTOR_H
#define MYINTVECTOR_H

class MyIntVector {
private:
	int* data;
	size_t cp; // capacity
	size_t sz; // size

public:
	MyIntVector();
	MyIntVector(const MyIntVector& v);
	~MyIntVector();

	MyIntVector operator =(const MyIntVector& source);
	void operator +=(const MyIntVector& source);
	int operator [](const int i);
	MyIntVector& operator +(const MyIntVector& v);
	MyIntVector& operator -(const MyIntVector& v);
	MyIntVector& operator *(const MyIntVector& v);
	MyIntVector& operator -();
	bool operator ==(const MyIntVector& v);
	MyIntVector& operator ()(int num);
	void pop_back();
	void push_back(int x);
	size_t capacity() const;
	size_t size() const;
	void reserve(size_t n);
	bool is_empty() const;
	void clear();

};

#endif