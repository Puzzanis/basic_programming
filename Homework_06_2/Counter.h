#ifndef COUNTER_H
#define COUNTER_H

class Counter
{
private:
    int count{};

public:
    Counter(int setCount = 1);

    void increment();
    void decrement();
    void setCount(int setCount);
    int getCount();
};

#endif