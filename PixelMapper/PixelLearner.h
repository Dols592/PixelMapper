#pragma once

#include "PixelCameraBase.h"
#include "PixelDriverBase.h"

class CPixelLearner
{
public: //Constructor
	CPixelLearner(CPixelCameraBase& NewCamera, CPixelDriverBase& NewDriver);
	virtual ~CPixelLearner();

public: //Interface

protected: //Help Functions

protected: //Variables
  CPixelCameraBase& Camera;
  CPixelDriverBase& Driver;

};
