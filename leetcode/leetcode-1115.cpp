#include <semaphore.h>
class FooBar {
private:
    int n;
    sem_t foodone;
    sem_t bardone;

public:
    FooBar(int n) {
        this->n = n;
        sem_init(&bardone, 0, 1);
        sem_init(&foodone, 0, 0);
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            sem_wait(&bardone);
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            sem_post(&foodone);
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            sem_wait(&foodone);
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            sem_post(&bardone);
        }
    }
};