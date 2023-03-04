#ifndef CAR_H
#define CAR_H
#include "vehicle.h"


/// @brief This is a derived class from parent class vehicle. It hold the properties for a Car class
class Car : public Vehicle
{
	/// @brief This variable describe the Cars property max_passengers
	const int max_passengers;

public:
	/// @brief This function is the car constructor
	/// @param _model parameter that descripe the car property model
	/// @param _type parameter that descripe the car property type
	/// @param _max_passengers parameter that descripe the car property max_passengers
	Car(const char* _model, const char* _type, const int _max_passengers);

	/// @brief This function is a virtual destructor
	virtual ~Car() = default;

	/// @brief This function return the car id. It overrid the base class vehicle function
	/// @return car id
	int get_id() const override;

	/// @brief This function return the car model. It overrid the base class vehicle function
	/// @return car model
	const char* get_model() const override;

	/// @brief This function return the car type. It overrid the base class vehicle function
	/// @return car type
	const char* get_type() const override;

	/// @brief This function return the car max passengers. It overrid the base class vehicle function
	/// @return car max passengers
	int get_max_passengers() const override;
};
#endif