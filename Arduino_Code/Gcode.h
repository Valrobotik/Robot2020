#ifndef GCODE_H
#define GCODE_H

#include <Arduino.h>





class Gcode
{
  public :
  //Fonction pour décripter le Gcode
  void traductiongcode(String commande);
  void Compare(String stringcomplet, int lettre, int c, int sub_c);

  unsigned int m_G = 0;
  unsigned int m_M = 0;
  unsigned int m_N = 0;

  float m_X = 0.0;
  float m_Y = 0.0;
  float m_Z = 0.0;

  long m_S = 0;
  long m_P = 0;

  int m_T = 0;

  float m_A = 0.0;
  float m_B = 0.0;
  float m_C = 0.0;
  float m_D = 0.0;
  float m_E = 0.0;
  float m_F = 0.0;
  float m_H = 0.0;
  float m_I = 0.0;
  float m_J = 0.0;
  float m_K = 0.0;
  float m_L = 0.0;
  float m_O = 0.0;
  float m_Q = 0.0;
  float m_R = 0.0;
  float m_U = 0.0;
  float m_V = 0.0;
  float m_W = 0.0;


  inline bool hasG()
  {
    return ((param & 1)!= 0);
  }
  inline bool hasM()
  {
    return ((param & 2)!= 0);
  }
  inline bool hasN()
  {
    return ((param & 4)!= 0);
  }
  inline bool hasX()
  {
    return ((param & 8)!= 0);
  }
  inline bool hasY()
  {
    return ((param & 16)!= 0);
  }
  inline bool hasZ()
  {
    return ((param & 32)!= 0);
  }
  inline bool hasS()
  {
    return ((param & 64)!= 0);
  }
  inline bool hasP()
  {
    return ((param & 128)!= 0);
  }
  inline bool hasT()
  {
    return ((param & 256)!= 0);
  }
  inline bool hasA()
  {
    return ((param & 512)!= 0);
  }
  inline bool hasB()
  {
    return ((param & 1024)!= 0);
  }
  inline bool hasC()
  {
    return ((param & 2048)!= 0);
  }
  inline bool hasD()
  {
    return ((param & 4096)!= 0);
  }
  inline bool hasE()
  {
    return ((param & 8192)!= 0);
  }
  inline bool hasF()
  {
    return ((param & 16384)!= 0);
  }
  inline bool hasH()
  {
    return ((param & 32768)!= 0);
  }
  inline bool hasI()
  {
    return ((param & 65536)!= 0);
  }
  inline bool hasJ()
  {
    return ((param & 131072)!= 0);
  }
  inline bool hasK()
  {
    return ((param & 262144)!= 0);
  }
  inline bool hasL()
  {
    return ((param & 524288)!= 0);
  }
  inline bool hasO()
  {
    return ((param & 1048576)!= 0);
  }
  inline bool hasQ()
  {
    return ((param & 2097152)!= 0);
  }
  inline bool hasR()
  {
    return ((param & 4194304)!= 0);
  }
  inline bool hasU()
  {
    return ((param & 8388608)!= 0);
  }
  inline bool hasV()
  {
    return ((param & 16777216)!= 0);
  }
  inline bool hasW()
  {
    return ((param & 33554432)!= 0);
  }


  private :
  unsigned long param = 0;


};
#endif
