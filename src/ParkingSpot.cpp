#include "ParkingSpot.h"

ParkingSpot::ParkingSpot(int spotId, int floor, VehicleSize size)
    : spotId(spotId), floor(floor), size(size), occupied(false) {}

int ParkingSpot::getSpotId() const {
    return spotId;
}

int ParkingSpot::getFloor() const {
    return floor;
}

VehicleSize ParkingSpot::getSize() const {
    return size;
}

bool ParkingSpot::isOccupied() const {
    return occupied;
}

void ParkingSpot::setOccupied(bool occupied) {
    this->occupied = occupied;
}
