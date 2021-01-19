#include <string>
#pragma once

class Technologies {
protected:
	std::string name_;
	bool is_learned_;
	bool can_be_buildable_;
public:
	Technologies(std::string name, bool is_learned, bool can_be_buildable);
	virtual ~Technologies();
	virtual std::string get_name();
	virtual bool get_is_learned();
	virtual bool get_can_be_buildable();
	void learn();
};
