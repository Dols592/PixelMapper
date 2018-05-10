#include "pch.h"

#include "..\PixelMapper\Pixelimage.h"
#include "MemLeakCheck.h"

TEST(ImageCreation, MemoryLeak)
{
  CrtCheckMemory MemCheck;

  CPixelimage* TestImage = new CPixelimage();
  TestImage->EnsureAllocation(10);
  TestImage->EnsureAllocation(100);
  EXPECT_EQ(1, MemCheck.IsDifferent());
  delete TestImage;
  EXPECT_EQ(0, MemCheck.IsDifferent());
}
TEST(ImageCreation, Empty)
{
  CPixelimage TestImage;

  EXPECT_EQ(0, TestImage.ImageBuffer.BytesAllocated);
  //EXPECT_TRUE(true);
}

TEST(ImageCreation, Reset)
{
  CPixelimage TestImage;
  TestImage.Reset();

  EXPECT_EQ(0, TestImage.ImageBuffer.BytesAllocated);
  //EXPECT_TRUE(true);
}

TEST(ImageCreation, Allocate)
{
  CPixelimage TestImage;
  EXPECT_EQ(0, TestImage.ImageBuffer.BytesAllocated);
  TestImage.EnsureAllocation(10);
  EXPECT_EQ(10, TestImage.ImageBuffer.BytesAllocated);
  TestImage.EnsureAllocation(1000);
  EXPECT_EQ(1000, TestImage.ImageBuffer.BytesAllocated);
  //EXPECT_TRUE(true);
}

TEST(ImageCopy, SimpleCopy)
{
  CPixelimage TestImage1;
  TestImage1.EnsureAllocation(1000);

  CPixelimage TestImage2;
  TestImage2.CopyFrom(TestImage1);

  EXPECT_EQ(TestImage1.ImageBuffer.BytesAllocated, TestImage2.ImageBuffer.BytesAllocated);
  EXPECT_EQ(0, memcmp(&TestImage1.ImageInfo, &TestImage2.ImageInfo, sizeof(TestImage1.ImageInfo)));
  EXPECT_EQ(0, memcmp(TestImage1.ImageBuffer.Buffer, TestImage2.ImageBuffer.Buffer, sizeof(TestImage1.ImageBuffer.BytesAllocated)));
}