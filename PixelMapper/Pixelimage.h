#pragma once

struct SImageBuffer
{
  uint32_t BytesAllocated;
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


struct SImageXY
{
  int32_t x;
  int32_t y;
  SImageXY()
  {
    x = -1;
    y = -1;
  }
};

class CPixelimage
{
public: //Constructor
	CPixelimage();
	virtual ~CPixelimage();

public: //Operators
  //CPixelimage & operator= (const CPixelimage& other);
  bool SameDimension(const CPixelimage& Other);

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
