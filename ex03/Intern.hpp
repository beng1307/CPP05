#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>

class AForm;

class	Intern
{
	public:

		Intern();
		Intern	&operator=(Intern &other);
		Intern(Intern &other);
		~Intern();

		class	NotExistingForm : public std::exception
		{
			public:

				virtual char *what() const throw();
		};

		static AForm	*createShrubberyForm(const std::string &target);
		static AForm	*createPresidentialForm(const std::string &target);
		static AForm	*createRobotomyForm(const std::string &target);

		AForm	*makeForm(std::string name, std::string target);

};

#endif