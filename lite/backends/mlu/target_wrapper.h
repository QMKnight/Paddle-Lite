// Copyright (c) 2019 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once
#include <vector>
#include "lite/backends/mlu/mlu_utils.h"
#include "lite/core/target_wrapper.h"

namespace paddle {
namespace lite {

using TargetWrapperMlu = TargetWrapper<TARGET(kMLU)>;

template <>
class TargetWrapper<TARGET(kMLU)> {
 public:
  using queue_t = cnrtQueue_t;

  static size_t num_devices();
  static size_t maxinum_queue() { return 0; }  // TODO(zhangshijin): fix out it.

  static size_t GetCurDevice() { return 0; }

  static void CreateQueue(queue_t* queue) {}
  static void DestroyQueue(const queue_t& queue) {}

  static void QueueSync(const queue_t& queue) {}

  static void* Malloc(size_t size);
  static void Free(void* ptr);

  static void MemcpySync(void* dst,
                         const void* src,
                         size_t size,
                         IoDirection dir);
  static void SetMLURunMode(lite_api::MLUCoreVersion core_version,
                            int core_number,
                            bool use_first_conv,
                            const std::vector<float>& mean_vec,
                            const std::vector<float>& std_vec,
                            DataLayoutType input_layout);
  static cnmlCoreVersion_t MLUCoreVersion();
  static int MLUCoreNumber();
  static bool UseFirstConv();
  static const std::vector<float>& MeanVec();
  static const std::vector<float>& StdVec();
  static DataLayoutType InputLayout();
  // static void MemcpyAsync(void* dst,
  //                         const void* src,
  //                         size_t size,
  //                         IoDirection dir,
  //                         const queue_t& queue);
 private:
  static thread_local cnmlCoreVersion_t mlu_core_version_;
  static thread_local int mlu_core_number_;
  static thread_local bool use_first_conv_;
  static thread_local std::vector<float> mean_vec_;
  static thread_local std::vector<float> std_vec_;
  static thread_local DataLayoutType input_layout_;
};

}  // namespace lite
}  // namespace paddle
