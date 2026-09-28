#include "Car.h"

#include <utility>

Car::Car(std::string licensePlate)
    : Vehicle(std::move(licensePlate)) {}

VehicleSize Car::getSize() const {
    return VehicleSize::MEDIUM;
}
