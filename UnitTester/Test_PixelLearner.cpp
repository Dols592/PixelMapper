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

TEST(PixelLearner, SetBackground)
{
  CPixelCameraSimulator PixelCameraSimulator;
  CPixelDriverSimulator PixelDriverSimulator(PixelCameraSimulator);
  CPixelLearner PixelLearner(PixelCameraSimulator, PixelDriverSimulator);

  PixelDriverSimulator.ResetImageGray(127);
  PixelLearner.SetBackground();

  PixelDriverSimulator.SetPixelGray(1, 255);
  SImageXY PixelPos = PixelLearner.FindPixelPos();
  EXPECT_EQ(PixelDriverSimulator.GetPixelPos(1).x, PixelPos.x);
  EXPECT_EQ(PixelDriverSimulator.GetPixelPos(1).y, PixelPos.y);
}
