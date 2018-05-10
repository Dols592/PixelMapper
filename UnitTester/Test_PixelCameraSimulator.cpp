#include "pch.h"

#include "..\PixelMapper\PixelCameraSimulator.h"


TEST(CameraImageCreation, CreateBlackImage)
{
  CPixelCameraSimulator TestCamera;
  TestCamera.CreateImage(100, 100, false);

  CPixelimage& TestImage = TestCamera.GetImage();
  EXPECT_EQ(10000, TestImage.ImageBuffer.BytesAllocated);
  //EXPECT_TRUE(true);
}
