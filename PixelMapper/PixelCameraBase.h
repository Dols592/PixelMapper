#pragma once

#include "Pixelimage.h"

class CPixelCameraBase
{
public: //Constructor
	CPixelCameraBase();
	virtual ~CPixelCameraBase();

public: //Interface
  virtual CPixelimage& GetImage() = 0;

protected: //Help functions

protected: //Variables

};
