#include <iostream>
#include <pthread.h>
#include <cstdlib>

using namespace std;

#define NUM_THREADS 5

void *PrintHello(void *threadid)
{
    //对传入的参数进行强制类型转换，由无类型指针变为整型指针，然后再读取
    int tid = *((int *)threadid);
    cout<<"Hello C++! 线程ID,"<<tid<<endl;
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int indexes[NUM_THREADS];//用数组来保存i的值
    int rc;
    int i;
    
    for(i=0;i<NUM_THREADS;i++)
    {
    	cout<<"main():创建线程，"<<i<<endl;
	indexes[i]=i;
	rc=pthread_create(&threads[i],NULL,PrintHello,(void *)&(indexes[i]));
	
	if(rc){
	    cout<<"ERROR:无法创建线程，"<<rc<<endl;
	    exit(-1);
	}
    }
    
    pthread_exit(NULL);
}
