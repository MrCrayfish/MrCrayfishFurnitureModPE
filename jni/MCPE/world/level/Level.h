#pragma once

#include <string>

class Level {
public:
	virtual void playSound(float,float,float,std::string const&,float,float);
};
