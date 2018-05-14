#include "pch.h"


#include "..\PixelMapper\PixelLearner.h"
#include "..\PixelMapper\PixelDriverSimulator.h"
#include "..\PixelMapper\PixelCameraSimulator.h"

TEST(PixelLearner, CanCreateTestObject)
{
  CPixelCameraSimulator PixelCameraSimulator;
  CPixelDriverSimulator PixelDriverSimulator(PixelCameraSimulator);
  CPixelLearner PixelLearner(PixelCameraSimulator, PixelDriverSimulator);

}

