#include "stdafx.h"

#include "PixelConverter.h"

PixelConverter::PixelConverter()
  : Width(0)
  , Height(0)
  , BytesAllocated(0)
  , Buffer(NULL)
{
  int32_t Width;
  int32_t Height;
  uint32_t BytesAllocated;
  uint8_t* Buffer;
}


PixelConverter::~PixelConverter()
{
}


void PixelConverter::CreateEmptyMap(int32_t Width, int32_t Height)
{

}