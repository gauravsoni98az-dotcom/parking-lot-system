#pragma once

#include "PricingStrategy.h"

class TruckPricing : public PricingStrategy {
public:
    double calculateFee(double durationHours) override;

private:
    static constexpr double kRatePerHour = 100.0;
    static constexpr double kDailyCap = 1000.0;
};
