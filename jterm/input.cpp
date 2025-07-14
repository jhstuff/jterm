#include "input.h"

namespace jtb
{

key input::getKey()
{
	if(!q.size())
		return {"",(unsigned long long)-1,"No key"};
	mf.lock();		//----
	key temp = q.front();	//Locked
	q.pop_front();		//
	mf.unlock();		//----
	return temp;
}

long long input::peekSize()
{
	m.lock();
	long long temp = keys.size();
	m.unlock();
	return temp;
}
std::string input::get()
{
	m.lock();
	std::string temp = keys;
	keys = "";
	m.unlock();
	return temp;
}

void input::run()
{
	if(runningT || runningF)
		return;
	stopT = false;
	runningT = true;
	stopF = false;
	runningF = true;
	t = new std::thread(getter,this);
	f = new std::thread(formatter,this);
}
void input::stop()
{
	if(runningT)
	{
		stopT = true;
		t->detach();
		delete t;
		runningT = false;
		stopT = false;
	}
	if(runningF)
	{
		stopF = true;
		f->detach();
		delete f;
		runningF = false;
		stopF = false;
	}
}
void input::getter(input * i)
{
	std::string c;
	while(!i->stopT)
	{
		c = std::cin.get();
		if(i->stopT)
			break;
		i->m.lock();
		i->keys += c;
		i->m.unlock();
	}
	i->stopT = false;
}
void input::formatter(input * i)
{
	std::string in;
	key k;
	int iCounter = 0;
	while(!i->stopF)
	{
		if(!i->peekSize())
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
			continue;
		}
		while(i->peekSize() > iCounter)
		{
			iCounter++;
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}
		in = i->get();
		iCounter = 0;
		if(i->useConfig)
		{
			k = i->config.config.at(keycodeToBits(in));
		}
		else
		{
			k.key = keycodeToKey(in);
			if(in.size()>8)
				k.bits = 0;
			else
				k.bits = keycodeToBits(in);		
			k.keycode = in;
		}
		i->mf.lock();
		i->q.push_back(k);
		i->mf.unlock();
		in = "";
	}
	i->stopF = false;

}


}
