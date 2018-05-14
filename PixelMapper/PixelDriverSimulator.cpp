//
#include "stdafx.h"

#include "PixelDriverSimulator.h"

CPixelDriverSimulator::CPixelDriverSimulator(CPixelCameraSimulator& NewCameraSimulator)
  : CameraSimulator(NewCameraSimulator)
{
  NrOfPixels = NROFPIXELS;

  CameraSimulator.TestImage.ImageInfo.Width = 100;
  CameraSimulator.TestImage.ImageInfo.Height = 100;
  CameraSimulator.TestImage.ImageInfo.Pitch = 100;
  CameraSimulator.TestImage.ImageInfo.ImageIsColor = false;
  CameraSimulator.TestImage.ImageInfo.BytesPerPixel = 1;
  CameraSimulator.TestImage.EnsureAllocation();
  memset(CameraSimulator.TestImage.ImageBuffer.Buffer, 127, CameraSimulator.TestImage.ImageBuffer.BytesAllocated);

  srand((uint32_t) time(NULL));

  for (uint32_t i = 0; i < NrOfPixels - 4; i++)
  {
    PosToImageXY[i].x = rand() % 100;
    PosToImageXY[i].y = rand() % 100;
  }

  //for testing: duplicate position of first to last
  PosToImageXY[NrOfPixels - 1].x = PosToImageXY[0].x;
  PosToImageXY[NrOfPixels - 1].y = PosToImageXY[0].y;

  //for testing: One pixel shifted
  if (PosToImageXY[1].x < CameraSimulator.TestImage.ImageInfo.Width/2)
    PosToImageXY[NrOfPixels - 2].x = PosToImageXY[1].x + 1;
  else
    PosToImageXY[NrOfPixels - 2].x = PosToImageXY[1].x - 1;
  PosToImageXY[NrOfPixels - 2].y = PosToImageXY[1].y;

  //for testing: pixel in corner
  PosToImageXY[NrOfPixels - 3].x = 0;
  PosToImageXY[NrOfPixels - 3].y = 0;

  //for testing: pixel in corner
  PosToImageXY[NrOfPixels - 4].x = CameraSimulator.TestImage.ImageInfo.Width - 1;
  PosToImageXY[NrOfPixels - 4].y = CameraSimulator.TestImage.ImageInfo.Height - 1;
}

CPixelDriverSimulator::~CPixelDriverSimulator()
{
}

void CPixelDriverSimulator::SetPixelGray(int32_t Pos, uint8_t Value)
{
  int32_t BytePos = PosToImageXY[Pos].y * CameraSimulator.TestImage.ImageInfo.Pitch;
  BytePos += PosToImageXY[Pos].x * CameraSimulator.TestImage.ImageInfo.BytesPerPixel;
  *(CameraSimulator.TestImage.ImageBuffer.Buffer + BytePos) = Value;
}

void CPixelDriverSimulator::SetPixelColor(int32_t Pos, uint64_t Value)
{

}
