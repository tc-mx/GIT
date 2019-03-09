#include <iostream>
#include <pthread.h>
using namespace std;

#define NUM_THREADS 5

//线程的运行函数
void* say_hello(void* args)
{
    cout<<"Hello C++!"<<endl;
    return 0;
}

int main()
{
    //定义线程的id变量，多个变量使用数组
    pthread_t tids[NUM_THREADS];
    for(int i=0;i<NUM_THREADS;++i)
    {
	int ret=pthread_create(&tids[i],NULL,say_hello,NULL);
	if(ret!=0)
	    cout<<"pthread_create error:error_code="<<ret<<endl;
    }

    pthread_exit(NULL);
}
