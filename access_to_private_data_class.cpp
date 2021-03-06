#include <iostream>
// Обращение к приватным данным по прямым адресам (не рекомендуется использовать данный подход)

class MyTest
{
	private:
		int a;
		double k;
		char c;
	public:
		MyTest(int a, double k, char c)
		{
			this->a = a;
			this->k = k;
			this->c = c;
		}
		void print() 
		{
			printf("a=%d, k=%f, c=%c\n", a, k, c);
		}
};

class MyTest_
{
	public:
		int a;
		double k;
		char c;
};

int __main(void) {
	
	MyTest* t = new MyTest(10, 2.2, 'a');
	t->print();
	MyTest_* t_ = (MyTest_*)t;
	t_->a = 42;
	t_->k = 9.9;
	t_->c = 'y';
	
	t->print();
	
	return 0;
}

struct Cls {
    Cls(char c, double d, int i) {
        this->c = c;
        this->d = d;
        this->i = i;
        this->aa = 'b';
        this->a2 = 'b';
    }
    public:
    char c;
    double d;
    int i;
    char aa;
    char a2;
};

int main() {
    
    Cls cls('a', 9.4, 42);
    
    char ch = *(char *)&cls;
    double db = *(double*)(&cls + 8);
    int in = *(int*)(&cls + 10);
    
    std::cout << ch << std::endl;
    std::cout << db << std::endl;
    std::cout << in << std::endl;
    std::cout << std::endl;
    int aa = reinterpret_cast<int>(&cls);
    std::cout << &cls     <<  "   " << (&cls + 0)  << std::endl;
    std::cout << &(cls.d) <<  "   " << *(double*)(aa + 8) << std::endl;
    std::cout << &(cls.i) <<  "   " << *(int*)(aa + 16) << std::endl;
    
    return 0;
}