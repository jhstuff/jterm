#ifndef JTERMINPUT
#define JTERMINPUT
#include <thread>
#include <mutex>
#include <chrono>
#include <iostream>
#include <deque>
#include <map>

#include "key.h"

namespace jtb
{
struct input
{
	std::deque<key> q;
	std::thread * t; //getter thread
	std::thread * f; //formatter thread
	std::mutex m;
	std::mutex mf;
	std::string keys;
	bool runningT = false,
	     stopT = false,
	     stopF = false,
	     runningF = false,
	     useConfig = false;
	
	keyConfig config;

	key getKey();

	long long peekSize();
	std::string get();
	void stop();
	void run();

	static void formatter(input * i);
	static void getter(input * i);	
};

}
#endif
