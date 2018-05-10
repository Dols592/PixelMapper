#pragma once

class CPixelDriverBase
{
public: //Constructor
  CPixelDriverBase();
  virtual ~CPixelDriverBase();

public: //Interface
  virtual void SetPixel(int32_t Pos, int32_t Value) = 0;

protected: //Help functions

protected: //Variables

};