#pragma once

#include "PricingStrategy.h"

class CarPricing : public PricingStrategy {
public:
    double calculateFee(double durationHours) override;

private:
    static constexpr double kRatePerHour = 50.0;
    static constexpr double kDailyCap = 500.0;
};
