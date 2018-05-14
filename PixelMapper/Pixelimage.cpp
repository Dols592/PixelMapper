//
#include "stdafx.h"

#include "Pixelimage.h"

CPixelimage::CPixelimage()
{
  ImageBuffer.Buffer = NULL;
  ImageBuffer.BytesAllocated = 0;
  Reset();
}

CPixelimage::~CPixelimage()
{
  if (ImageBuffer.Buffer)
    free(ImageBuffer.Buffer);
}

void CPixelimage::Reset()
{
  ImageInfo.Width = 0;
  ImageInfo.Height = 0;
  ImageInfo.Pitch = 0;
  ImageInfo.BytesPerPixel = 0;
  ImageInfo.ImageIsColor = false;
}

void CPixelimage::EnsureAllocation()
{
  uint32_t ImageSize = ImageInfo.Height * ImageInfo.Pitch;
  EnsureAllocation(ImageSize);
}

void CPixelimage::EnsureAllocation(uint32_t Size)
{
  if (ImageBuffer.BytesAllocated < Size)
  {
    ImageBuffer.Buffer = (uint8_t*) realloc(ImageBuffer.Buffer, Size);
    ImageBuffer.BytesAllocated = Size;
  }
}

void CPixelimage::CopyFrom(const CPixelimage& OrgImage)
{
  EnsureAllocation(OrgImage.ImageBuffer.BytesAllocated);
  memcpy_s(ImageBuffer.Buffer, ImageBuffer.BytesAllocated, OrgImage.ImageBuffer.Buffer, OrgImage.ImageBuffer.BytesAllocated);
  
  ImageInfo = OrgImage.ImageInfo;
}

bool CPixelimage::SameDimension(const CPixelimage& Other)
{
  if (ImageInfo.Width != Other.ImageInfo.Width) return false;
  if (ImageInfo.Height != Other.ImageInfo.Height) return false;
  if (ImageInfo.Pitch != Other.ImageInfo.Pitch) return false;
  if (ImageInfo.ImageIsColor != Other.ImageInfo.ImageIsColor) return false;
  if (ImageInfo.ImageIsColor != Other.ImageInfo.ImageIsColor) return false;

  return true;
}