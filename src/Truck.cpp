#include "Truck.h"

#include <utility>

Truck::Truck(std::string licensePlate)
    : Vehicle(std::move(licensePlate)) {}

VehicleSize Truck::getSize() const {
    return VehicleSize::LARGE;
}
