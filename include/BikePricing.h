#pragma once

#include "PricingStrategy.h"

class BikePricing : public PricingStrategy {
public:
    double calculateFee(double durationHours) override;

private:
    static constexpr double kRatePerHour = 20.0;
    static constexpr double kDailyCap = 200.0;
};
