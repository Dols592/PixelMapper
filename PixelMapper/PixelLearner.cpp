//
#include "stdafx.h"

#include "PixelLearner.h"

CPixelLearner::CPixelLearner(CPixelCameraBase& NewCamera, CPixelDriverBase& NewDriver)
  : Camera(NewCamera)
  , Driver(NewDriver)
{
}

CPixelLearner::~CPixelLearner()
{

}