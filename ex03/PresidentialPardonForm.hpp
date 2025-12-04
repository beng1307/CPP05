#ifndef PRESIDENTIALPARDONFORM_HPP
#define	PRESIDENTIALPARDONFORM_HPP

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

		void	executeAction() const;
};
	
#endif