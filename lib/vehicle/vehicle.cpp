#include "vehicle.h"

std::atomic<int> Vehicle::unique_id{ 1001 };

Vehicle::Vehicle(const char* _model, const char* _type)
	:model{ _model }, type{ _type } {
	id = unique_id;
	unique_id++;
}


int Vehicle::get_id() const
{
	return id;
}

const char* Vehicle::get_model() const
{
	return model;
}

const char* Vehicle::get_type() const
{
	return type;
}
