#pragma once

struct SImageBuffer
{
  int32_t BytesAllocated;
  uint8_t* Buffer;
};

struct SImageInfo
{
  int32_t Width;
  int32_t Height;
  int32_t Pitch;
  int32_t BytesPerPixel;
  bool ImageIsColor;
};

class CPixelimage
{
public: //Constructor
	CPixelimage();
	virtual ~CPixelimage();

public: //Interface
  void Reset();
  void EnsureAllocation();
  void EnsureAllocation(uint32_t Size);
  void CopyFrom(const CPixelimage& OrgImage);

protected: //Help functions

public: //Variables
  SImageBuffer ImageBuffer;
  SImageInfo ImageInfo;
};
