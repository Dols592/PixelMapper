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

void CPixelimage::EnsureAllocation(uint32_t Size)
{
  if (ImageBuffer.BytesAllocated < Size)
  {
    ImageBuffer.Buffer = (char*) realloc(ImageBuffer.Buffer, Size);
    ImageBuffer.BytesAllocated = Size;
  }
}

void CPixelimage::CopyFrom(const CPixelimage& OrgImage)
{
  EnsureAllocation(OrgImage.ImageBuffer.BytesAllocated);
  memcpy_s(ImageBuffer.Buffer, ImageBuffer.BytesAllocated, OrgImage.ImageBuffer.Buffer, OrgImage.ImageBuffer.BytesAllocated);
  
  ImageInfo = OrgImage.ImageInfo;
}