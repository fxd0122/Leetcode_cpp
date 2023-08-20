#include <semaphore.h>
class Foo {
public:
    Foo() {
        sem_init(&firstd, 0, 0);
        sem_init(&secondd, 0, 0);
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        sem_post(&firstd);
    }

    void second(function<void()> printSecond) {
        sem_wait(&firstd);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        sem_post(&secondd);
    }

    void third(function<void()> printThird) {
        sem_wait(&secondd);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
private:
    sem_t firstd, secondd;
};