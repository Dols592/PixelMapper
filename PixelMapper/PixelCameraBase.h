#pragma once

#include "Pixelimage.h"

class CPixelCameraBase
{
public: //Constructor
	CPixelCameraBase();
	virtual ~CPixelCameraBase();

public: //Interface
  virtual const CPixelimage& GetImage() = 0;

protected: //Help functions

protected: //Variables

};
