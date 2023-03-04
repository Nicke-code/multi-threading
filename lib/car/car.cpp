#include "car.h"


Car::Car(const char* _model, const char* _type, const int _max_passengers)
	:Vehicle{ _model, _type }, max_passengers{_max_passengers} {
}


int Car::get_id() const
{
	return Vehicle::id;
}

const char* Car::get_model() const
{
	return Vehicle::model;
}

const char* Car::get_type() const
{
	return Vehicle::type;
}

int Car::get_max_passengers() const
{
	return max_passengers;
}
