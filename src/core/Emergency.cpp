#include "ems/core/Emergency.hpp"

namespace ems::core {

Emergency::Emergency(const std::string& type, const std::string& location, int severity)
    : type_(type), location_(location), severity_(severity), timeReported_(std::chrono::system_clock::now()) {}

std::string Emergency::getType() const {
    return type_;
}

std::string Emergency::getLocation() const {
    return location_;
}

int Emergency::getSeverity() const {
    return severity_;
}

std::chrono::system_clock::time_point Emergency::getTimeReported() const {
    return timeReported_;
}

void Emergency::updateSeverity(int newSeverity) {
    severity_ = newSeverity;
}

} // namespace ems::core