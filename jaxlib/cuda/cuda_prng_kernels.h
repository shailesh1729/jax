/* Copyright 2019 The JAX Authors.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef JAXLIB_CUDA_PRNG_KERNELS_H_
#define JAXLIB_CUDA_PRNG_KERNELS_H_

#include <cstddef>
#include <string>

#include "third_party/gpus/cuda/include/cuda_runtime_api.h"
#include "tensorflow/compiler/xla/service/custom_call_status.h"

namespace jax {

struct ThreeFry2x32Descriptor {
  std::int64_t n;
};

void LaunchThreeFry2x32Kernel(cudaStream_t stream, void** buffers,
                              ThreeFry2x32Descriptor descriptor);

void CudaThreeFry2x32(cudaStream_t stream, void** buffers, const char* opaque,
                      size_t opaque_len, XlaCustomCallStatus* status);

}  // namespace jax

#endif  // JAXLIB_CUDA_PRNG_KERNELS_H_
