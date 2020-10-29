/*
 * Copyright 2019 xilinx Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once
#include "vitis/ai/yolov2.hpp"
#include <vitis/ai/configurable_dpu_task.hpp>

using std::shared_ptr;
using std::vector;

namespace vitis {
namespace ai {

class YOLOv2Imp : public vitis::ai::TConfigurableDpuTask<YOLOv2> {
public:
  YOLOv2Imp(const std::string &model_name, bool need_preprocess = true);
  virtual ~YOLOv2Imp();

private:
  virtual YOLOv2Result run(const cv::Mat &image) override;
  virtual std::vector<YOLOv2Result> run(const std::vector<cv::Mat> &image) override;
};
} // namespace ai
} // namespace vitis
