#pragma once

#include "PixelCameraBase.h"

class CPixelCameraSimulator: public CPixelCameraBase
{
public: //Constructor
  CPixelCameraSimulator();
  virtual ~CPixelCameraSimulator();

public: //Interface overrides from CPixelCameraBase
  virtual CPixelimage& GetImage();


public: //Interface
  void CreateImage(uint32_t Width, uint32_t Height, bool Color);

public: //Variables
  CPixelimage TestImage;
};