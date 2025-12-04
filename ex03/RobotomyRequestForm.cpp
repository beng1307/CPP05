#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"
#include <string>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):
	AForm("RobotomyRequestForm", 72, 45), target(target)
{
	return ;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &other):
	AForm(other), target(other.target)
{
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return ;
}

void	RobotomyRequestForm::executeAction() const
{
	static bool already_seeded = false;
    if (!already_seeded)
    {
        srand(time(NULL));
        already_seeded = true;
    }
	
	bool	CoinThrow = rand() % 2;

	if (CoinThrow)
		std::cout << target << " has been robotomized!" << std::endl;
	else
		std::cout << "Robotomy failed!" << std::endl;
}
