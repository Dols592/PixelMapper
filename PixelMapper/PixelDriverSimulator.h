#pragma once

#include "PixelDriverBase.h"
#include "PixelCameraSimulator.h"

#define NROFPIXELS 10


class CPixelDriverSimulator : public CPixelDriverBase
{
public: //Constructor
  CPixelDriverSimulator(CPixelCameraSimulator& NewCameraSimulator);
  virtual ~CPixelDriverSimulator();

public: //Interface
  virtual void SetPixelGray(int32_t Pos, uint8_t Value);
  virtual void SetPixelColor(int32_t Pos, uint64_t Value);
  void ResetImageGray(uint8_t Value);
  SImageXY GetPixelPos(int32_t Pos);

protected: //Help functions

protected: //Variables
  CPixelCameraSimulator& CameraSimulator;
  SImageXY PosToImageXY[NROFPIXELS];
};