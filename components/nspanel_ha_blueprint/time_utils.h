// time_utils.h

#pragma once
#include <string>
#include <time.h>

namespace nspanel_ha_blueprint {
    std::string strftime_ex(std::string format, const ESPTime& time, const std::string& am = "", const std::string& pm = "");
}  // namespace nspanel_ha_blueprint