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
  TestImage.ImageInfo.ImageIsColor = Color;
  TestImage.ImageInfo.Width = Width;
  TestImage.ImageInfo.Height = Height;
  TestImage.ImageInfo.BytesPerPixel = Color ? 3 : 1;
  TestImage.ImageInfo.Pitch = Width * TestImage.ImageInfo.BytesPerPixel;

  TestImage.EnsureAllocation();
  memset(TestImage.ImageBuffer.Buffer, 0, TestImage.ImageBuffer.BytesAllocated);
}

const CPixelimage& CPixelCameraSimulator::GetImage()
{
  return TestImage;
}
