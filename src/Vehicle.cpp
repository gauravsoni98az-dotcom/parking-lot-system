#include "Vehicle.h"

#include <utility>

Vehicle::Vehicle(std::string licensePlate)
    : licensePlate(std::move(licensePlate)) {}

const std::string& Vehicle::getLicensePlate() const {
    return licensePlate;
}
