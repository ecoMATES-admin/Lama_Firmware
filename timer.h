#ifndef TIMER_H
#define TIMER_H

class Timer {
    uint32_t count;
  public:
    Timer()
      : count(0)
    {};
    void increaseCount();
    uint32_t getCount();
    void resetCount();

};

inline void Timer::increaseCount(){
  count++;
}

inline uint32_t Timer::getCount(){
  return count;
}

inline void Timer::resetCount(){
  count = 0;
}




#endif
