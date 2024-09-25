// File: tests/unit/core/EmergencyTests.cpp

#include <gtest/gtest.h>
#include "ems/core/Emergency.hpp"

using namespace ems::core;

TEST(EmergencyTests, ConstructorAndGetters) {
    Emergency e("Fire", "123 Main St", 3);
    
    EXPECT_EQ(e.getType(), "Fire");
    EXPECT_EQ(e.getLocation(), "123 Main St");
    EXPECT_EQ(e.getSeverity(), 3);
    EXPECT_NE(e.getTimeReported(), std::chrono::system_clock::time_point());
}

TEST(EmergencyTests, UpdateSeverity) {
    Emergency e("Flood", "456 River Rd", 2);
    
    e.updateSeverity(4);
    EXPECT_EQ(e.getSeverity(), 4);
}