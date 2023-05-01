// ThreadingTutorial.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
//#include <glm/glm.hpp>

void print(int i)
{
	static std::mutex myMutex;
	std::lock_guard<std::mutex> guard(myMutex);
	std::cout << "Hello Thread " << i << "\n";
	std::cout << "I'm here squared..." << i * i << "\n";
	std::cout << "...not there cubed " << i * i * i << ".\n";
}

int main()
{
	std::cout << "Threading Tutorial\n\n";
	std::cout << ">>> Multiple Threads\n";
	std::cout << "    using a lambda with parameters\n";

	std::vector<std::thread> threads;
	vec4 myVectors[50] = {};

	for (int i = 0; i < 50; i++) {
		threads.push_back(std::thread(
			// defining a lambda that can access main scope with &
			[&](int i) {
				myVectors[i] = normalize(myVectors[i]);
			}, i
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

vec4 version of this?
Or glm::normalize?

vec3 normalize(const vec3 &v)
{
   float length_of_v = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
   return vec3(v.x / length_of_v, v.y / length_of_v, v.z / length_of_v);
}


*/