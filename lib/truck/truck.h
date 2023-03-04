#ifndef TRUCK_H
#define TRUCK_H
#include "vehicle.h"

/// @brief This is a derived class from parent class vehicle. It hold the properties for a Truck class
class Truck : public Vehicle
{
	/// @brief This variable describe the Trucks property max_weight_load
	const int max_weight_load;

public:
	/// @brief This function is the truck constructor
	/// @param _model parameter that descripe the truck property model
	/// @param _type parameter that descripe the truck property type
	/// @param _max_weight_load parameter that descripe the truck property max_weight_load
	Truck(const char* _model, const char* _type, const int _max_weight_load);

	/// @brief This function is a virtual destructor
	virtual ~Truck() = default;

	/// @brief This function return the truck id. It overrid the base class vehicle function
	/// @return truck id
	int get_id() const override;

	/// @brief This function return the truck model. It overrid the base class vehicle function
	/// @return truck model
	const char* get_model() const override;

	/// @brief This function return the truck type. It overrid the base class vehicle function
	/// @return truck type
	const char* get_type() const override;

	/// @brief This function return the truck max_weight_load. It overrid the base class vehicle function
	/// @return truck max_weight_load
	int get_max_weight_load() const override;
};
#endif