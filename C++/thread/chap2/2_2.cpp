//等待线程退出
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
		for(unsigned j=0;j<1000000;++j)
		{
			std::cout<<"void operator()():"<<i<<std::endl;
			do_something(i);	//引用了临时变量
		}
	}
};

void do_something_in_current_thread(){}
void f()
{
	int some_local_state=0;
	func my_func(some_local_state);
	std::thread t(my_func);
	try{
		do_something_in_current_thread();
	}catch(...){
		t.join();
		throw;
	}//使用了try/catch块确保访问本地状态的线程退出后，函数才结束。
	t.join();
}

int main()
{
	f();
}
