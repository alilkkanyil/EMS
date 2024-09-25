#pragma once

#include <string>

namespace ems::core {

    enum class UnitStatus {
        Available,
        Responding,
        Busy
    };

    class EmergencyUnit {
        public:
            EmergencyUnit(const std::string& type, const std::string& location);

            std::string getType() const;
            std::string getLocation() const;
            UnitStatus getStatus() const;

            void updateLocation(const std::string& newLocation);
            void updateStatus(UnitStatus newStatus);

        private:
            std::string type_;
            std::string location_;
            UnitStatus status_;
    };
}