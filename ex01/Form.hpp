#ifndef FORM_HPP
#define	FORM_HPP

#include <string>

class	Bureaucrat;

class	Form
{
	private:

		const std::string	name;
		bool				is_signed;
		const unsigned		signing_grade;
		const unsigned		executing_grade;

		Form();

	public:
		
		Form(const std::string &name, unsigned signing_grade, unsigned executing_grade);
		Form	&operator=(Form &other);
		Form(Form &other);
		~Form();

		class	GradeTooLowException: public std::exception
		{
			public:

				virtual const char *what() const throw();
		};

		class	GradeTooHighException: public std::exception
		{
			public:

				virtual const char *what() const throw();
		};

		void	beSigned(Bureaucrat &bureaucrat);

		const std::string	get_name() const;
		bool				get_is_signed() const;
		unsigned			get_signing_grade() const;
		unsigned			get_executing_grade() const;
		
	};
	
	std::ostream &operator<<(std::ostream &output, const Form &form);

#endif