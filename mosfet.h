#ifndef MOSFET_H
#define MOSFET_H

class Mosfet{
  private:
    uint8_t _gate;
  public:
    Mosfet(uint8_t gate): _gate(gate)
    {
    };
    void on(){
      analogWrite(_gate, 255);
    };
    void off(){
      analogWrite(_gate, 0);
    };
    void pwm(uint8_t dc){
      analogWrite(_gate, dc); 
    };

};


#endif
