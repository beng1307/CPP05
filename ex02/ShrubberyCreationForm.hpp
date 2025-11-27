#ifndef SHRUBBERYCREATIONFORM_HPP
#define	SHRUBBERYCREATIONFORM_HPP

#include <string>
#include "AForm.hpp"

class	Bureaucrat;

class	ShrubberyCreationForm: public AForm
{
	private:

		std::string	target;

		ShrubberyCreationForm();

	public:
		
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm	&operator=(ShrubberyCreationForm &other);
		ShrubberyCreationForm(ShrubberyCreationForm &other);
		~ShrubberyCreationForm();

		void	executeAction();
};
	
#endif