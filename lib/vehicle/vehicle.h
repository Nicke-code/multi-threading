#ifndef VEHICLE_H
#define VEHICLE_H
#include <atomic>


/// @brief This is a virtual base class that is used as an interface for all common properties for a vehicle. Car and Truck class public inheriet from Vehicle class
class Vehicle
{
protected:
	/// @brief This variable is a common variable for the whole Vehicle class so that each created vehicle will get a unique id. Its atomic so read and write is syncroniced.
	static std::atomic<int> unique_id;
	
	/// @brief This variable is a property for each vehicle and its unique
	int id;

	/// @brief This variable describe the vehicle property model
	const char* model;

	/// @brief This variable describe the vehicle property type
	const char* type;

public:
	/// @brief This function is the vehicle constructor
	/// @param _model parameter that descripe the vehicle property model
	/// @param _type parameter that descripe the vehicle property type
	Vehicle(const char* _model, const char* _type);

	/// @brief This function is a virtual destructor
	virtual ~Vehicle() = default;

	/// @brief This function is a virtual function that return the vehicles id. Its overriden in derived classes
	/// @return vehicle id
	virtual int get_id() const =0;

	/// @brief This function is a virtual function that return the vehicles model. Its overriden in derived classes
	/// @return vehicle model
	virtual const char* get_model() const = 0;

	/// @brief This function is a virtual function that return the vehicles type. Its overriden in derived classes
	/// @return vehicle type
	virtual const char* get_type() const = 0;

	/// @brief This function is a virtual function that return the vehicles max passengers. Its overriden in Car class
	/// @return Not applicable
	virtual int get_max_passengers() const { return 0; };

	/// @brief This function is a virtual function that return the vehicles max load. Its overriden in Truck class
	/// @return Not applicable
	virtual int get_max_weight_load() const { return 0; };
};
#endif