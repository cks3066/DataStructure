//MyIntVector 체크
//printf() , scanf() 함수 사용 x
// vector 사용 x
// 전역 변수 사용 x
// precondition , postcondition 작성

#include <iostream>
#include <stdlib.h>
#include <cassert>
#include <algorithm>
#include "MyIntVector.h"


using namespace std;

int main()
{
	cout << "Test Execution\n\n";

	MyIntVector test;

	cout << "//check MyIntVector() \n";
	cout << "test.sz : " << test.size() << "\n"
		<< "test.cp : " << test.capacity() << "\n";

	cout << "\n";

	test.push_back(1);
	test.push_back(2);
	test.push_back(3);

	cout << "//check push_back()\n";
	cout << "test.sz : " << test.size() << "\n"
		<< "test.cp : " << test.capacity() << "\n";
	for (int i = 0; i < test.size(); i++)
		cout << "test[" << i << "] : " << test[i] << "\n";

	cout << "\n";

	cout << "//check pop_back()\n";
	test.pop_back();
	cout << "test.sz : " << test.size() << "\n"
		<< "test.cp : " << test.capacity() << "\n";
	for (int i = 0; i < test.size(); i++)
		cout << "test[" << i << "] : " << test[i] << "\n";

	cout << "\n";
	cout << "test.push_back(3);\n";
	test.push_back(3);

	cout << "\n";

	MyIntVector test2;

	cout << "//check operator =()\n";
	cout << "'test2 = test'\n";
	test2 = test;
	cout << "test2.sz : " << test2.size() << "\n"
		<< "test2.cp : " << test2.capacity() << "\n";
	for (int i = 0; i < test2.size(); i++)
		cout << "test2[" << i << "] : " << test2[i] << "\n";
	
	cout << "\n";

	cout << "//check operator ==()\n";
	cout << "'cout << (test == test2)'\n";
	cout << (test == test2) << "\n";

	cout << "\n";
	
	cout << "//check operator +=()\n";
	cout << "'test += test2'\n";
	test += test2;
	cout << "test.sz : " << test.size() << "\n";
	for (int i = 0; i < test.size(); i++)
		cout << "test[" << i << "] : " << test[i] << "\n";

	cout << "\n";

	cout << "'test = test2'\n";
	test = test2;
	cout << "\n";

	cout << "//check MyIntVector(const MyIntVector & v)\n";
	MyIntVector test3(test);
	cout << "'MyIntVector test3(test)'\n";
	cout << "test3.sz : " << test3.size() << "\n"
		<< "test3.cp : " << test3.capacity() << "\n";
	for (int i = 0; i < test3.size(); i++)
		cout << "test3[" << i << "] : " << test3[i] << "\n";

	cout << "\n";

	cout << "// mcheck operator +()\n";
	MyIntVector result;
	result = (test + test2);
	cout << "'MyIntVector result\n";
	cout << "'result = test + test2'\n";
	for (int i = 0; i < result.size(); i++)
		cout << "result[" << i << "] : " << result[i] << "\n";

	cout << "\n";

	cout << "check operator -()\n";
	result = (test - test2);
	cout << "'result = test - test2'\n";
	for (int i = 0; i < result.size(); i++)
		cout << "result[" << i << "] : " << result[i] << "\n";

	cout << "\n";

	cout << "check operator *()\n";
	result = (test * test2);
	cout << "'result = test * test2'\n";
	for (int i = 0; i < result.size(); i++)
		cout << "result[" << i << "] : " << result[i] << "\n";

	cout << "\n";

	cout << "check unary operator -()\n";
	cout << "'test2 = -test'\n";
	test2 = -test;
	for (int i = 0; i < test2.size(); i++)
		cout << "test2[" << i << "] : " << test2[i] << "\n";

	cout << "\n";

	cout << "check unary operator ()()\n";
	cout << "'test = test(1)'\n";
	test = test(1);
	for (int i = 0; i < test.size(); i++)
		cout << "test[" << i << "] : " << test[i] << "\n";

	cout << "\n";

	cout << "check clear()\n";
	cout << "test.clear()\n";
	test.clear();
	cout << "test.sz : " << test.size() << "\n";
	cout << "test.cp : " << test.capacity() << "\n";

	cout << "\n";

	cout << "check is_empty()\n";
	cout << "cout << test.is_empty()\n";
	cout << "cout << test2.is_empty()\n";
	cout << test.is_empty();
	cout << "\n";
	cout << test2.is_empty();
	cout << "\n";

	cout << "\n";

	cout << "check reserve()\n";
	cout << "test.cp : " << test.capacity() << "\n";
	cout << "test.reserve(16)\n";
	test.reserve(16);
	cout << "test.cp : " << test.capacity() << "\n";
                
}
