#pragma once

#include "PixelDriverBase.h"

#include "PixelCameraSimulator.h"

#define NROFPIXELS 10

struct SImageXY
{
  int32_t x;
  int32_t y;
};

class CPixelDriverSimulator : public CPixelDriverBase
{
public: //Constructor
  CPixelDriverSimulator(CPixelCameraSimulator& NewCameraSimulator);
  virtual ~CPixelDriverSimulator();

public: //Interface
  virtual void SetPixelGray(int32_t Pos, uint8_t Value);
  virtual void SetPixelColor(int32_t Pos, uint64_t Value);

protected: //Help functions

protected: //Variables
  CPixelCameraSimulator& CameraSimulator;

  SImageXY PosToImageXY[NROFPIXELS];
};