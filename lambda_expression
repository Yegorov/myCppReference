#include <iostream>
#include <typeinfo>
#include <exception>
#include <cxxabi.h>
#include <string>
/*
	const std::type_info  &ti = typeid(u);
	realname = abi::__cxa_demangle(ti.name(), 0, 0, &status);
	std::cout << ti.name() << "\t=> " << realname << "\t: " << status << '\n';
	
	http://gcc.gnu.org/onlinedocs/libstdc++/manual/ext_demangling.html
*/	


class qwe
{
private:
	qwe()
	{
	}
public:
	static qwe * obj;
	int operator()(const int &q) 
	{
		return 2*q;
	}
	static qwe & getInstanse()
	{
		if(obj==NULL)
			obj = new qwe();
		return *obj;
	}
	~qwe()
	{
		if(obj!=NULL)
			delete obj;
	}
};
qwe * qwe::obj = NULL;
int main()
{
	int status;
	
	qwe & functor = qwe::getInstanse();
	qwe & func = qwe::getInstanse();
	std::cout<<"qwe:  "<<functor(10)<<std::endl;
	
	auto lambda = [](const int & q)-> int
					{
						return 2*q;
					};
	
	std::cout<<"lambda  "<<typeid(lambda).name()<<std::endl;
	
	const std::type_info  &tinfo = typeid(lambda);
	std::cout << abi::__cxa_demangle(tinfo.name(), 0, 0, &status) << '\n';
	
	

	std::cin.get();
	return 0;
}
