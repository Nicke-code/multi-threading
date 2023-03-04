#include "truck.h"


Truck::Truck(const char* _model, const char* _type, const int _max_weight_load)
	:Vehicle{ _model, _type }, max_weight_load{ _max_weight_load } {
}


int Truck::get_id() const
{
	return Vehicle::id;
}

const char* Truck::get_model() const
{
	return Vehicle::model;
}

const char* Truck::get_type() const
{
	return Vehicle::type;
}


int Truck::get_max_weight_load() const
{
	return max_weight_load;
}