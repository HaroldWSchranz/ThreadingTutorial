// ThreadingTutorial.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

void print()
{
	static std::mutex myMutex;
	myMutex.lock();
	std::cout << "Hello Thread\n";
	std::cout << "I'm here...\n";
	std::cout << "...not there.\n";
	myMutex.unlock();
}

int main()
{
	std::cout << "Threading Tutorial 3\n\n";

	std::cout << ">>> Single Thread\n";

	// starts a separate thread of execution
	std::thread myThread(print);
	// waits until the thread has ended
	myThread.join();

	std::cout << "\n====================\n";
	std::cout << ">>> Multiple Threads\n";

	std::vector<std::thread> threads;
	for (int i = 0; i < 5; ++i)
	{
		threads.push_back(std::thread(print));
	}
	for (auto& thread : threads)
	{
		thread.join();
	}
	std::cout << "\n====================\n";

	return 0;
}