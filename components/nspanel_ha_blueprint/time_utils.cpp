#include "time_utils.h"


namespace nspanel_ha_blueprint {
    std::string strftime_ex(std::string format, const ESPTime& time, const std::string& am, const std::string& pm)
    {
        if (format.find("%-H") != std::string::npos) {
            format = format.replace(format.find("%-H"), sizeof("%-H")-1,
                                    std::to_string((int)(time.hour)));
        }
        if (format.find("%-I") != std::string::npos) {
            if (time.hour>12) {
                format = format.replace(format.find("%-I"), sizeof("%-I")-1,
                                        std::to_string((int)(time.hour-12)));
            } else if (time.hour==0) {
                format = format.replace(format.find("%-I"), sizeof("%-I")-1, "12");
            } else {
                format = format.replace(format.find("%-I"), sizeof("%-I")-1,
                                        std::to_string((int)(time.hour)));
            }
        }
        if (am != "" || pm != "") {
            if (format.find("%p") != std::string::npos) {
                format = format.replace(format.find("%p"), sizeof("%p")-1,
                                        (time.hour < 12) ? am : pm);
            }
        }

        return time.strftime(format);
    }
}