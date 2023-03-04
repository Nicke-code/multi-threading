# multi-threading
A thread safe and synchronized vehicle manufacturer and multiple vehicle dealers program.

Program consist of:
 - Multiple vehicle dealers
 - A warehouse
 - A manufaucurer

Program consist of:
Multiple vehicle dealers
A warehouse
A manufacturer

Vehicle dealers:
Every vehicle dealer is a thread and when a dealer gets a vehicle, it shall print its properties to the terminal. Number of dealers shall at least be 2 and specified at start of program.
A dealer gets 1 vehicle at a time and when the warehouse is empty, all dealer threads shall sleep.

Warehouse
The manufacturer store vehicles in the warehouse and then dealers receive vehicles from the warehouse.
The warehouse shall be a circular buffer template class

Manufacturer
The manufacturer is 1 thread and create random vehicles.
When the warehouse is full the manufacturer thread is sleeping.

The manufacturer and vehicle dealers operate at different rate/speed which can change over time.

The circular buffer shall be uncopiable, unassignable, and unmoveable template class.
The warehouse template class shall be tested and have 100% test coverage.
