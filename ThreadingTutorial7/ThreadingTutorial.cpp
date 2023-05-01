// ThreadingTutorial.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

void print(int i)
{
	static std::mutex myMutex;
	std::lock_guard<std::mutex> guard(myMutex);
	std::cout << "Hello Thread " << i << "\n";
	std::cout << "I'm here squared..." << i*i << "\n";
	std::cout << "...not there cubed " << i*i*i << ".\n";
}

int main()
{
	std::cout << "Threading Tutorial\n\n";
	std::cout << ">>> Multiple Threads\n";
	std::cout << "    using a lambda with no parameters\n";
	std::cout << "    using a lambda that can access myMutex\n";

	std::vector<std::thread> threads;
	std::mutex myMutex;

	for (int i = 0; i < 5; i++) {
		threads.push_back(std::thread(
			// defining a lambda that can access myMutex
			[&myMutex]() {
				std::lock_guard<std::mutex> guard(myMutex);
				std::cout << "Hello Thread\n";
				std::cout << "I'm here...\n";
				std::cout << "...not there.\n";
			}
		));
	}

	for (auto& thread : threads)
	{
		thread.join();
	}

	std::cout << "\n====================\n";

	return 0;
}


// Wondering about syntax:
// void print(int i)
// 		threads.push_back(std::thread(print, i));
/* https://cplusplus.com/reference/thread/thread/
// thread example
#include <iostream>       // std::cout
#include <thread>         // std::thread

void foo()
{
	// do stuff...
}

void bar(int x)
{
	// do stuff...
}

int main()
{
	std::thread first(foo);     // spawn new thread that calls foo()
// thread(  ,  )
	std::thread second(bar, 0);  // spawn new thread that calls bar(0)

	std::cout << "main, foo and bar now execute concurrently...\n";

	// synchronize threads:
	first.join();                // pauses until first finishes
	second.join();               // pauses until second finishes

	std::cout << "foo and bar completed.\n";

	return 0;
}
*/