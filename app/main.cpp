#if 0
/**
 * @file main.cpp
 * @author Nicke-code
 * @brief This is a program that simulate a vehicle manufacturer, warehouse and delares.
 * 					The manufacturer create vehicles which is either cars or trucks. They are created randomly.
 * 						1 thread will go in an infinity loop creating new vehicles.
 * 					Directly after creation, the vechicles are moved into a warehouse. If the warehouse is full the manufacturer thread will sleep.
 * 					The vehicles will be moved from the warehouse to dealers and the vehicles properties will be printed out in the terminal. If the warehouse is empty the dealer thread will sleep
 * 						x number of dealer thread will go in an infinity loop.
 * 
 * 					The circular buffer size is set by a macro which is defined in warehouse.h. It's set in CMakeLists.txt in root directory by parameter: CIRCULAR_BUFFER_SIZE
 * 					Now its set to 10. To change it a re-compilation need to be done. Minimum required size is 8. Less than that the program will not compile.
 * 
 * 					The number of dealer threads are set when starting the program by giving in parameter to the main function. Minimum 2 dealer threads must be set.
 * 					
 * 					IMPORTANT!
 * 					Start the program by typing in terminal: ./app/main x			there x is the number of dealer threads.
 * 					Test coverage is given in terminal by typing: "gcovr -r ../ ."		after the program have ended with tests performed.
 * 					(assumption is done that location is in build folder when typing in terminal)
 * 					Variable: constexpr int NUM_OF_LOOP_ITERATIONS {x}; decide how many loopts that manufacturer and each dealer thread will run.
 * 
 * @version 0.1
 * @date 2023-02-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#endif

#include <iostream>
#include <memory>
#include <thread>
#include <condition_variable>
#include <chrono>
#include <vector>
#include <cstring>
#include "vehicle.h"
#include "car.h"
#include "truck.h"
#include "warehouse.h"


Ware_house<std::unique_ptr<Vehicle>>  warehouse;
std::mutex mtxLock;
std::condition_variable warehouse_full_cv;
bool warehouse_is_full{ false };
std::condition_variable warehouse_empty_cv;
bool warehouse_is_empty{ false };

#if 0
/// @brief This is the number of loops each dealer thread will run.
///					manufacturer will run this number * num_of_dealers
#endif
constexpr int NUM_OF_LOOP_ITERATIONS {70};

#if 0
/// @brief This function check so that the vehicle ptr is initialized each time a pointer is created
/// @tparam R This is a generalised type and will be of type vehicle
/// @param ptr This is the pointer that is passed into the function
#endif
template<typename R>
void check_vehicle_ptr(const R& ptr)
{
	if (!ptr)
	{
#if 0
		// customer to decide what shall happen if pointer to vehicle object can't be initialized.
#endif	
	}
}

#if 0
/// @brief This function display the vehicle(car and truck) each time its passed from the warehouse/buffer to the dealer
/// @tparam PTR This is a generalised type and will be of type vehicle
/// @param ptr This is the pointer that is passed into the function
#endif
template<typename PTR>
void display_vehicle(PTR &ptr)
{
	std::cout << "id: " << ptr->get_id() << std::endl;
	std::cout << "model: " << ptr->get_model() << std::endl;
	std::cout << "type: " << ptr->get_type() << std::endl;
	if (strcmp(ptr->get_type(), "V60") == 0)
	{
		std::cout << "max passangers: " << ptr->get_max_passengers() << std::endl;
	}
	else
	{
		std::cout << "max weigt load: " << ptr->get_max_weight_load() << std::endl;
	}

	std::cout << std::endl;
}

#if 0
/// @brief This function create vehicles. Car and Trucks are created randomly and after creation its moved into the warehouse/buffer. 
///					if the warehouse is full this function will sleep untill there are empty space in the warehouse
/// @param  This variable is void
/// @return If the manufaturer hasn't planed any stop, this function will loop infinitly and therefore nothing will be returned. Return true if function have succeded with creating a fixed number of vehicle.
#endif
bool create_vehicle(int numOfLoops)
{
	int vehicle_cat{0};
	bool status{false};
	int i{0};
	while(i < numOfLoops)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		warehouse_is_full = false;
		vehicle_cat = rand() % 2;

		if (warehouse.get_counter() < BUFFER_SIZE)
		{
			std::unique_ptr<Vehicle> vehicle_ptr;
			if (vehicle_cat == 0)
			{
				vehicle_ptr = std::make_unique<Car>("Volvo", "V60", 5);
			}
			else
			{
				vehicle_ptr = std::make_unique<Truck>("Big truck", "Model big", 10500);
			}
			check_vehicle_ptr(vehicle_ptr);
			
			std::unique_lock<std::mutex> ul(mtxLock);
			warehouse.buffer[warehouse.get_tail()] = std::move(vehicle_ptr);
			check_vehicle_ptr(warehouse.buffer[warehouse.get_tail()]);
#if 0
			std::cout << "manufacture, id:" << warehouse.buffer[warehouse.get_tail()]->get_id() << std::endl;
#endif		
			warehouse.set_tail();
			
			i++;
			warehouse_is_empty = true;
			ul.unlock();
			warehouse_empty_cv.notify_one();
		}
		else 
		{
			std::unique_lock<std::mutex> ul(mtxLock);
#if 0
			std::cout << "\nwarehouse full, sleeping\n" << std::endl;
#endif			
			warehouse_full_cv.wait(ul, []() {return warehouse_is_full == true; });			
		}
		status = true;
	}
	return status;
}

#if 0
/// @brief This function move vehicles from the warehouse/buffer to the dealer. It operate after principle FIFO 
///					if the warehouse is empty this function will sleep untill there are vehicles in the warehouse
/// @param  This variable is void
/// @return If the dealer hasn't planed any stop, this function will loop infinitly and therefore nothing will be returned. Return true if function have succeded with moveing a fixed number of vehicle from warehouse to dealer.
#endif
bool ship_to_dealer(int numOfLoops)
{
	bool status{false};
	int i{0};
	while(i < numOfLoops)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		
		std::unique_lock<std::mutex> ul(mtxLock);
		warehouse_is_empty = false;
		if (warehouse.get_counter() <= BUFFER_SIZE && warehouse.get_counter() > 0)
		{
			display_vehicle(warehouse.buffer[warehouse.get_head()]);
			std::unique_ptr<Vehicle> display_and_delete_ptr{ std::move(warehouse.buffer[warehouse.get_head()]) };
			check_vehicle_ptr(display_and_delete_ptr);
			warehouse.set_head();

			i++;
			warehouse_is_full = true;
			ul.unlock();
			warehouse_full_cv.notify_one();
		}
		else
		{
#if 0
			std::cout << "\nwarehouse empty, sleeping\n" << std::endl;
#endif			
			warehouse_empty_cv.wait(ul, []() {return warehouse_is_empty == true; });
		}
		status = true;
	}
	return status;
}

#if 1
/// @brief This is a google test function that verify that writing to buffer work as expected. Function create_vehicle() must be modified to create a fixed number of vehicle for this to work
///        If the loop is infinity in create_vehicle(), this shall be comment out. The tests will be done syncroniusly in 1 thread.
///					Loop same number of times as the buffer size so that a check of reseting variable tail is verified
TEST(testManufacturer, writeToBuffer)
{
	for(int i{0}; i < BUFFER_SIZE; i++)
	{
		EXPECT_EQ(1, create_vehicle(1));
	}

}

/// @brief This is a google test function that verify that reading from buffer work as expected. Function ship_to_dealer() must be modified to move a fixed number of vehicle for this to work
///        If the loop is infinity in ship_to_dealer(), this shall be comment out. The tests will be done syncroniusly in 1 thread.
///					Loop same number of times as the buffer size so that a check of reseting variable head is verified
TEST(testDealer, readFromBuffer)
{
	for(int i{0}; i < BUFFER_SIZE; i++)
	{
	EXPECT_EQ(1, ship_to_dealer(1));
	}
}
#endif


int main(int argc, char **argv)
{
	if(argc < 2 || 2 < argc)
	{
		std::cerr << "A variable with number of dealer threads need to be stated in terminal when starting the program. State: program_name number_of_dealer_threads" << std::endl;
		std::exit(1);
	}

	const int num_of_dealers = std::stoi(argv[1]);
	if(num_of_dealers < 2)
	{
		std::cerr << "Number of dealer threads shall be minimum 2." << std::endl;
		std::exit(1);
	}

	std::vector<std::thread> dealers;
	std::thread manufacturer{ create_vehicle, num_of_dealers * NUM_OF_LOOP_ITERATIONS };

	for (int i{ 0 }; i < num_of_dealers; i++)
	{
		dealers.push_back(std::thread{ ship_to_dealer, NUM_OF_LOOP_ITERATIONS });
	}

	manufacturer.join();
	for (std::thread& dealer : dealers)
	{
		if (dealer.joinable())
		{
			dealer.join();
		}
	}

	testing::InitGoogleTest();

	return RUN_ALL_TESTS();
}