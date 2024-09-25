#include "ems/core/EmergencyUnit.hpp"

namespace ems::core {
    EmergencyUnit::EmergencyUnit(const std::string& type, const std::string& location)
        : type_(type), location_(location), status_(UnitStatus::Available) {}

    std::string EmergencyUnit::getType() const {
        return type_;
    }

    std::string EmergencyUnit::getLocation() const {
        return location_;
    }

    UnitStatus EmergencyUnit::getStatus() const {
        return status_;
    }

    void EmergencyUnit::updateLocation(const std::string& newLocation) {
        location_ = newLocation;
    }

    void EmergencyUnit::updateStatus(UnitStatus newStatus) {
        status_ = newStatus;
    }
} // namespace ems::core