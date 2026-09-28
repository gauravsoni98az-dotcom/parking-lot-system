#include "PricingFactory.h"

#include <stdexcept>

#include "BikePricing.h"
#include "CarPricing.h"
#include "TruckPricing.h"

std::unique_ptr<PricingStrategy> PricingFactory::create(VehicleSize size) {
    switch (size) {
        case VehicleSize::SMALL:
            return std::make_unique<BikePricing>();
        case VehicleSize::MEDIUM:
            return std::make_unique<CarPricing>();
        case VehicleSize::LARGE:
            return std::make_unique<TruckPricing>();
        default:
            throw std::invalid_argument("Unknown vehicle size");
    }
}
