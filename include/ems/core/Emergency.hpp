#pragma once

#include <string>
#include <chrono>

namespace ems::core {

class Emergency {
public:
    Emergency(const std::string& type, const std::string& location, int severity);

    std::string getType() const;
    std::string getLocation() const;
    int getSeverity() const;
    std::chrono::system_clock::time_point getTimeReported() const;

    void updateSeverity(int newSeverity);

private:
    std::string type_;
    std::string location_;
    int severity_;
    std::chrono::system_clock::time_point timeReported_;
};

} // namespace ems::core