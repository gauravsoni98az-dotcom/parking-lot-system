#pragma once

#include <memory>

#include "PricingStrategy.h"
#include "Vehicle.h"

class PricingFactory {
public:
    static std::unique_ptr<PricingStrategy> create(VehicleSize size);
};
