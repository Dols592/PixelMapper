#pragma once

class CPixelDriverBase
{
public: //Constructor
  CPixelDriverBase();
  virtual ~CPixelDriverBase();

public: //Interface
  virtual void SetPixelGray(int32_t Pos, uint8_t Value) = 0;
  virtual void SetPixelColor(int32_t Pos, uint64_t Value) = 0;

protected: //Help functions

protected: //Variables
  uint32_t NrOfPixels;

};