#pragma once

class PricingStrategy {
public:
    virtual ~PricingStrategy() = default;

    virtual double calculateFee(double durationHours) = 0;
};
