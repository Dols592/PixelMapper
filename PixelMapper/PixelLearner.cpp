//
#include "stdafx.h"

#include "PixelLearner.h"

CPixelLearner::CPixelLearner(CPixelCameraBase& NewCamera, CPixelDriverBase& NewDriver)
  : Camera(NewCamera)
  , Driver(NewDriver)
{
  BackgroundImage.Reset();
}

CPixelLearner::~CPixelLearner()
{

}

void CPixelLearner::SetBackground()
{
  BackgroundImage.CopyFrom(Camera.GetImage());
}

void CPixelLearner::FindAllPixels()
{
  uint32_t NrOfPixels = Driver.GetNrOfPixels();
  SImageXY* PixelPos = new SImageXY[NrOfPixels];

  for (uint32_t i = 0; i < NrOfPixels; i++)
  {
    Driver.SetPixelGray(i, 255);
    PixelPos[i] = FindPixelPos();    
    Driver.SetPixelGray(i, 0);
  }
}


SImageXY CPixelLearner::FindPixelPos()
{
  SImageXY ReturnPos;

  const CPixelimage& PixelImage = Camera.GetImage();

  if (!BackgroundImage.SameDimension(PixelImage))
    return ReturnPos;

  int32_t HighestValue = 10;
  for (int32_t y = 0; y < PixelImage.ImageInfo.Height; y++)
  {
    uint8_t* BufferAtPixelImage = PixelImage.ImageBuffer.Buffer;
    BufferAtPixelImage += y * PixelImage.ImageInfo.Pitch;

    uint8_t* BufferAtPixelBackground = BackgroundImage.ImageBuffer.Buffer;
    BufferAtPixelBackground += y * PixelImage.ImageInfo.Pitch;

    for (int32_t x = 0; x < PixelImage.ImageInfo.Width; x++)
    {
      int32_t Value = *(BufferAtPixelImage + x) - *(BufferAtPixelBackground + x);
      if (Value > HighestValue)
      {
        HighestValue = Value;
        ReturnPos.x = x;
        ReturnPos.y = y;
      }
    }
  }

  return ReturnPos;
}