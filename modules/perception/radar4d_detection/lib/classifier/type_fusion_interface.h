/******************************************************************************
 * Copyright 2023 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#pragma once

#include <memory>
#include <string>

#include "modules/perception/common/base/object.h"
#include "modules/perception/common/lib/interface/base_init_options.h"
#include "modules/perception/common/lib/registerer/registerer.h"
#include "modules/perception/common/radar/common/object_sequence.h"

namespace apollo {
namespace perception {
namespace radar4d {

using apollo::perception::BaseInitOptions;

struct TypeFusionInitOption : public BaseInitOptions {};

struct TypeFusionOption {};

class BaseOneShotTypeFusion {
 public:
  /**
   * @brief Init type fusion
   *
   * @param option
   * @return true
   * @return false
   */
  virtual bool Init(const TypeFusionInitOption& option) = 0;
  /**
   * @brief Type fusion
   *
   * @param option
   * @param object update type of the object
   * @return true
   * @return false
   */
  virtual bool TypeFusion(const TypeFusionOption& option,
                          std::shared_ptr<perception::base::Object> object) = 0;
  /**
   * @brief Get class name
   *
   * @return std::string
   */
  virtual std::string Name() const = 0;
};

PERCEPTION_REGISTER_REGISTERER(BaseOneShotTypeFusion);
#define PERCEPTION_REGISTER_ONESHOTTYPEFUSION(name) \
  PERCEPTION_REGISTER_CLASS(BaseOneShotTypeFusion, name)

class BaseSequenceTypeFusion {
 public:
  typedef ObjectSequence::TrackedObjects TrackedObjects;

 public:
  /**
   * @brief Init type fusion
   *
   * @param option
   * @return true
   * @return false
   */
  virtual bool Init(const TypeFusionInitOption& option) = 0;
  /**
   * @brief Type fusion
   *
   * @param option
   * @param tracked_objects update type of the tracked object
   * @return true
   * @return false
   */
  virtual bool TypeFusion(const TypeFusionOption& option,
                          TrackedObjects* tracked_objects) = 0;
  /**
   * @brief Get class name
   *
   * @return std::string
   */
  virtual std::string Name() const = 0;
};

PERCEPTION_REGISTER_REGISTERER(BaseSequenceTypeFusion);
#define PERCEPTION_REGISTER_SEQUENCETYPEFUSION(name) \
  PERCEPTION_REGISTER_CLASS(BaseSequenceTypeFusion, name)

}  // namespace radar4d
}  // namespace perception
}  // namespace apollo
