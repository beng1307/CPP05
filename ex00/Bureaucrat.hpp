#ifndef BUREAUCRAT_HPP
# define BURAUCRAT_HPP

#include <string>

class	Bureaucrat
{
	private:

		const std::string	name;
		unsigned int		grade;
	
	public:

		Bureaucrat();
		Bureaucrat(const std::string name, unsigned int grade);
		~Bureaucrat();

		class	GradeTooLowException;
		class	GradeTooHighException;

		const std::string	getName() const;
		unsigned int		getGrade() const;
};

#endif