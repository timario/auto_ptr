#include <iostream>
#include "my_auto_ptr.h"


#ifdef TEST

int main()
{
	std::string* A = new std::string("123");
	std::string* B = new std::string("123") ;

	std::auto_ptr <std::string> _q(A);
	std::auto_ptr <std::string> _q1;

	string_ptr _a(B);
	string_ptr _a1;


	_q1 = _q;  //check operator =
	_a1 = _a;  
	
	*_q1 = *_q1 + "123";  //check jperator *
	*_a1 = *_a1 + "123";

	assert(*_q1.get() == *_a1.get());  ////check this values with operator *

	std::auto_ptr <std::string> _q2(_q1);  //check constructor with auto_ptr

	string_ptr _a2(_a1);

	assert(*_q2 == *_a2);
	A = _q2.release();  
	B =_a2.release();  // check release

	assert(*A == *B);

	std::cout << "TESTS OK";

	return 0;
}

#endif // !TEST









#ifndef TEST
#define RELEASE

int main()
{
	std::string *A = new std::string("|123");
	std::string* B = new std::string("|4123");
	std::string* C = new std::string("qe");
	std::auto_ptr <std::string> _q(A);
	std::auto_ptr <std::string> _q1(A);

	std::cout << *A << std::endl;

	_q = _q1;

	string_ptr tmp;
	string_ptr tmp2(A);
	tmp = tmp2;
	string_ptr tmp1(tmp);

	*tmp1 = "12";
	*tmp1 = *B;
	*tmp1.get() = "321";

	std::cout << *tmp1.get() << std::endl;

	*tmp1 = *tmp1 + "eq";
	std::cout << *tmp1.get() << std::endl;

	//string_ptr tmp5;

	//tmp5 = tmp1;
	//////std::cout << *tmp.get() << std::endl;
	//std::cout << *tmp5.get() << std::endl;

	//////*tmp.get() = *tmp1.get();

	//A = tmp5.release();

	//std::cout << *A << std::endl;


	return 0;
}
#endif



