#include <iostream>
#include <thread>

void hello()
{
	std::cout<<"Hello Concurrent World\n";
}

int main()
{
	std::thread t(hello);//每个线程都必须具有一个初始函数，新线程的执行在这里开始。
	t.join();//等待线程退出
}
