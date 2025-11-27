#ifndef SHRUBBERYCREATIONFORM_HPP
#define	SHRUBBERYCREATIONFORM_HPP

#include <string>
#include "AForm.hpp"

class	Bureaucrat;

class	RobotomyRequestForm: public AForm
{
	private:

		std::string	target;

		RobotomyRequestForm();

	public:
		
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm	&operator=(RobotomyRequestForm &other);
		RobotomyRequestForm(RobotomyRequestForm &other);
		~RobotomyRequestForm();

		void	executeAction();
};
	
#endif