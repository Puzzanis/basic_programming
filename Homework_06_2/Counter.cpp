#include "Counter.h"

Counter::Counter(int setCount) : count{ setCount } {}

void Counter::increment() { ++count; }
void Counter::decrement() { --count; }
void Counter::setCount(int setCount) { count = setCount; }
int Counter::getCount() { return count; }