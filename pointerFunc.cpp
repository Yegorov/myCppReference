/* Author Artem Yegorov
 * Date 03.11.2013
 * Указатели на функции (делегаты в C#) и std::function
 * Компилятор GCC 4.7.2 
 * g++ pointerFunc.cpp -o pf -std=c++11
*/
#include <iostream>
#include <functional>
#include <map>
#include <string>


int add(const int &a, const int &b)
{
	return a+b;
}

int multi(const int &a, const int &b)
{
	return a*b;
}

typedef int (*Func)(const int &, const int &);//Func - синоним указателя на функцию

using namespace std;
int main(int argc, char * argv[])
{
	//1 Описание с map с помощью std::function<>
	map<string, function<int(const int &,const int &)> > case1;
	case1.insert(pair<string, function<int(int,int)> >("+",add));
	case1["/"] = [](const int & a, const int & b)->int{if(b==0) return a; return (int)a/b;};
	cout<<case1["+"](2,3)<<"  "<< case1["/"](7,3)<<endl;
	
	//2 Описание с помощью указателя на функцию
	map<string, Func> * case2 = new map<string, Func>();
	case2->insert(pair<string, Func>("+", add));
	case2->insert(pair<string, Func>("*", multi));
	case2->insert(pair<string, Func>("-", [](const int & a, const int &b)->int{return a-b;}));
	
	cout<<(*case2)["+"](5,7)<<" "<<(*case2)["-"](5,7)<<"  "<<(*case2)["*"](5,7);
	
	delete case2;
	
	cin.get();
	return 0;
}