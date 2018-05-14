#pragma once

class PixelConverter
{
public: //Constructor
  PixelConverter();
  virtual ~PixelConverter();

public: //Interface
  void CreateEmptyMap(int32_t Width, int32_t Height);

protected: //Help functions

protected: //Variables
  int32_t Width;
  int32_t Height;
  uint32_t BytesAllocated;
  uint8_t* Buffer;
};

