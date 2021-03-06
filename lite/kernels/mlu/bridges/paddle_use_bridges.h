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

USE_SUBGRAPH_BRIDGE(relu, kMLU);
USE_SUBGRAPH_BRIDGE(conv2d, kMLU);
USE_SUBGRAPH_BRIDGE(depthwise_conv2d, kMLU);
USE_SUBGRAPH_BRIDGE(elementwise_add, kMLU);
USE_SUBGRAPH_BRIDGE(pool2d, kMLU);
USE_SUBGRAPH_BRIDGE(softmax, kMLU);
USE_SUBGRAPH_BRIDGE(batch_norm, kMLU);
USE_SUBGRAPH_BRIDGE(fc, kMLU);
USE_SUBGRAPH_BRIDGE(nearest_interp, kMLU);
USE_SUBGRAPH_BRIDGE(leaky_relu, kMLU);
USE_SUBGRAPH_BRIDGE(transpose, kMLU);
USE_SUBGRAPH_BRIDGE(transpose2, kMLU);
USE_SUBGRAPH_BRIDGE(concat, kMLU);
USE_SUBGRAPH_BRIDGE(scale, kMLU);
USE_SUBGRAPH_BRIDGE(sigmoid, kMLU);
USE_SUBGRAPH_BRIDGE(elementwise_mul, kMLU);
USE_SUBGRAPH_BRIDGE(dropout, kMLU);
