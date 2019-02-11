#ifndef Stopwatch_h
#define Stopwatch_h

#include <ctime>

class Stopwatch {
  private:
    double start;
    double _stopwatch() const
    {
      clock_t time = clock();
      return time * .001;
    }
  public:
    Stopwatch() { reset(); }
    void reset() { start = _stopwatch(); }
    double read() const { return _stopwatch() - start; }
};

#endif
