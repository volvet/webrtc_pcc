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

#include "api/units/timestamp.h"


namespace webrtc {
std::string ToString(Timestamp value) {
  std::stringstream ss;
  if (value.IsInfinite()) {
    ss << "inf ms";
  } else {
    if (value.ms() % 1000 == 0)
      ss << value.seconds() << " s";
    else
      ss << value.ms() << " ms";
  }
  return ss.str();
}
}  // namespace webrtc
