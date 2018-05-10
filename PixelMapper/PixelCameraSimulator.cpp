//
#include "stdafx.h"

#include "PixelCameraSimulator.h"

CPixelCameraSimulator::CPixelCameraSimulator()
{
}

CPixelCameraSimulator::~CPixelCameraSimulator()
{
}

void CPixelCameraSimulator::CreateImage(uint32_t Width, uint32_t Height, bool Color)
{
  uint32_t ImageSize = Width * Height * (Color ? 3 : 1);
  TestImage.EnsureAllocation(ImageSize);
  memset(TestImage.ImageBuffer.Buffer, 0, TestImage.ImageBuffer.BytesAllocated);
}

CPixelimage& CPixelCameraSimulator::GetImage()
{
  return TestImage;
}
