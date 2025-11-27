#ifndef SHRUBBERYCREATIONFORM_HPP
#define	SHRUBBERYCREATIONFORM_HPP

#include <string>
#include "AForm.hpp"

class	Bureaucrat;

class	PresidentialPardonForm: public AForm
{
	private:

		std::string	target;

		PresidentialPardonForm();

	public:
		
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm	&operator=(PresidentialPardonForm &other);
		PresidentialPardonForm(PresidentialPardonForm &other);
		~PresidentialPardonForm();

		void	executeAction();
};
	
#endif