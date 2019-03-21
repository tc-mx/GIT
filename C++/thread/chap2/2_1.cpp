//函数已经退出，线程依旧在访问局部变量
#include <iostream>
#include <thread>

void do_something(int& i)
{
	++i;
}

struct func{
	int& i;
	func(int& i_):i(i_){}
	//将被线程调用的函数
	void operator()()
	{
		for(unsigned j=0;j<10;++j)
		{
			std::cout<<"void operator()():"<<i<<std::endl;
			do_something(i);	//引用了临时变量
		}
	}
};

void oops()
{
	int some_local_state=0;
	func my_fun(some_local_state);
	std::thread my_thread(my_fun);
	my_thread.detach();
}

int main()
{
	oops();
	std::this_thread::sleep_for(std::chrono::seconds(1));//随机crash
}
