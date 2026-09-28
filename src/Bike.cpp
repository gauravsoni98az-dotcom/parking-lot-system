#include "Bike.h"

#include <utility>

Bike::Bike(std::string licensePlate)
    : Vehicle(std::move(licensePlate)) {}

VehicleSize Bike::getSize() const {
    return VehicleSize::SMALL;
}
