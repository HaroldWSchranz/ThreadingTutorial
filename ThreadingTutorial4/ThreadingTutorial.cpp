// ThreadingTutorial.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

void print()
{
	static std::mutex myMutex;
	std::lock_guard<std::mutex> guard(myMutex);
	std::cout << "Hello Thread\n";
	std::cout << "I'm here...\n";
	std::cout << "...not there.\n";
}

int main()
{
	std::cout << "Threading Tutorial\n\n";

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