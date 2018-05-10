#pragma once

#include "PixelDriverBase.h"

class CPixelDriverSimulator : public CPixelDriverBase
{
public: //Constructor
  CPixelDriverSimulator();
  virtual ~CPixelDriverSimulator();

public: //Interface
  virtual void SetPixel(int32_t Pos, int32_t Value);

protected: //Help functions

protected: //Variables
};