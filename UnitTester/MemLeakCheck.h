#pragma once

#include <crtdbg.h>
#include "gtest/gtest.h"

/*
Note, when google test has a failing test it allocates some memory. 
So after one fail, the IsDifferent will always be TRUE.
*/
struct CrtCheckMemory
{
  _CrtMemState state1;
  _CrtMemState state2;
  _CrtMemState state3;
  CrtCheckMemory()
  {
    _CrtMemCheckpoint(&state1);
  }
  ~CrtCheckMemory()
  {
/*
    // using google test you can just do this.
    EXPECT_EQ(0, _CrtMemDifference(&state3, &state1, &state2));
    // else just do this to dump the leaked blocks to stdout.
    if (_CrtMemDifference(&state3, &state1, &state2))
      _CrtMemDumpStatistics(&state3);
*/
  }
  
  int IsDifferent()
  {
    _CrtMemCheckpoint(&state2);
    return _CrtMemDifference(&state3, &state1, &state2);
  }

};

