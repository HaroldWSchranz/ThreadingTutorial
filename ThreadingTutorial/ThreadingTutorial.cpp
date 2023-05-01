// ThreadingTutorial.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <thread>
#include <iostream>

void print()
{
	std::cout << "Hello Thread\n";
}

int main()
{
	std::cout << "Threading Tutorial 1\n\n";

	std::cout << ">>> Single Thread\n";

	// starts a separate thread of execution
	std::thread myThread(print);
	// waits until the thread has ended
	myThread.join();
	return 0;
}