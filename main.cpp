#include <stdio.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <future>
using namespace std;
int n = 0;
std::mutex mtx;
void countMutex(int num){
    for (int i = 0; i < num; i++)
    {
        mtx.lock();
        n++;
        mtx.unlock();
    }
}

void testMutex()
{
    thread t1(countMutex, 100000);
    thread t2(countMutex, 100000);
    t2.join();
    t1.join();
    cout << n << endl;
}
atomic_int atoN;
void count(int num)
{
    for (int i = 0; i < num; i++)
    {
        atoN++;
    }
}
void testAtomic(){
    thread t1(count, 100000);
    thread t2(count, 100000);
    t1.join();
    t2.join();
    cout << atoN << endl;
}
void test(){
    thread([](){cout << "a" << endl; }).join();
    thread([](){cout << "b" << endl; }).join();

}
int main(int, char**){
  
    testAtomic();
   
    
    system("pause");
    return 0;
}