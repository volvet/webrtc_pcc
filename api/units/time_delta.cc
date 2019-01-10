/*
 *  Copyright (c) 2018 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#include <sstream>

#include "api/units/time_delta.h"

namespace webrtc {

std::string ToString(TimeDelta value) {
  std::stringstream ss;
  if (value.IsPlusInfinity()) {
    ss << "+inf ms";
  } else if (value.IsMinusInfinity()) {
    ss << "-inf ms";
  } else {
    if (value.us() == 0 || (value.us() % 1000) != 0)
      ss << value.us() << " us";
    else if (value.ms() % 1000 != 0)
      ss << value.ms() << " ms";
    else
      ss << value.seconds() << " s";
  }
  return ss.str();
}
}  // namespace webrtc
