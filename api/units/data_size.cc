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

#include "api/units/data_size.h"

namespace webrtc {

std::string ToString(DataSize value) {
  std::stringstream ss;
  if (value.IsInfinite()) {
    ss << "inf bytes";
  } else {
    ss << value.bytes() << " bytes";
  }
  return ss.str();
}
}  // namespace webrtc
