// time_utils.h

#pragma once
#include <string>
#include "esphome/core/time.h"

namespace nspanel_ha_blueprint {
    std::string strftime_ex(std::string format, const esphome::ESPTime& time, const std::string& am = "", const std::string& pm = "");
}  // namespace nspanel_ha_blueprint