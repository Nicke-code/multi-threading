#ifndef WAREHOUSE_H
#define WAREHOUSE_H
#include "vehicle.h"
#include <gtest/gtest.h>

/// @brief The BUFFER_SIZE is the size of the buffer and is set through a compile parameter, CIRCULAR_BUFFER_SIZE in the CMakeLists.txt placed in root directory
///					if the size isn't set of if it's less than 8, the compilation will fail
#ifndef BUFFER_SIZE
#error "Buffer size not set"
#elif (BUFFER_SIZE < 8)
#error "Buffer size if smaller than min, 8"
#endif


/// @brief This is the template class of the warehouse. It's main purpose is to manage a circular buffer to read and write Vehicles into/from
/// @tparam T this is a generalised type that will set the type of the circular buffer, which is implemented as an array
template <class T>
class Ware_house
{
public:
	/// @brief Constuctor for the class and circular buffer. If buffer can't be initiated the program will terminate.
	Ware_house()
	{
		if (!buffer)
		{
#if 0
			 // client to decide what shall happen if buffer can't be initialized.
#endif
		}
	}

	/// @brief This function is the default destructor
	~Ware_house() = default;

	/// @brief This function is a copy constructor and its made unaviliable through the delete
	/// @param ware_h Not applicable as constructor is deleted
	Ware_house(const Ware_house& ware_h) = delete;
	
	/// @brief This function is a move constructor and its made unaviliable through the delete
	/// @param ware_h Not applicable as constructor is deleted
	Ware_house(Ware_house&& ware_h) = delete;
	
	
	/// @brief This function is operloaded assignment operator and its made unaviliable through the delete
	/// @param ware_h Not applicable as constructor is deleted
	/// @return Not applicable as constructor is deleted
	Ware_house& operator=(Ware_house& ware_h) = delete;
	
	/// @brief This function is operloaded assignment operator and its made unaviliable through the delete
	/// @param ware_h Not applicable as constructor is deleted
	/// @return Not applicable as constructor is deleted
	Ware_house& operator=(Ware_house&& ware_h) = delete;

	/// @brief This function return int head
	/// @return Return head
	int get_head() { return head; }

	/// @brief This function return int tail
	/// @return Return tail
	int get_tail() { return tail; }
	
	/// @brief This function return int counter
	/// @return Return counter
	int get_counter() { return counter; }

	/// @brief This function set the head variable. Each time a vehicle is removed from the buffer, head is increased by 1. Head is reset to 0 when it reach BUFFER_SIZE
	///					it also decrease the counter by 1 as 1 vehicle is removed
	void set_head()//vehicle leaveing warehouse
	{
		counter--;
		if (head < BUFFER_SIZE - 1)
			head++;
		else
			head = 0;
	}

	/// @brief This function set the tail variable. Each time a vehicle is added to the buffer, tail is increased by 1. Tail is reset to 0 when it reach BUFFER_SIZE
	///					it also increasse the counter by 1 as 1 vehicle is added
	void set_tail() //adding vehicle to warehouse
	{
		counter++;
		if (tail < BUFFER_SIZE - 1)
			tail++;
		else
			tail = 0;
	}
	
	T buffer[BUFFER_SIZE]{};

private:
	/// @brief This variable increase index(itself) when adding a vehicle to warehouse/buffer
	int tail{0};
	
	/// @brief This variable increase index(itself) when removing a vehicle from warehouse/buffer
	int head{0};
	
	/// @brief This variable track how many vehicles it currently is in the buffer
	int counter{0};
};
#endif