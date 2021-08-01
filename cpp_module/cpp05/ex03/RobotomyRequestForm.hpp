#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>
# include "Form.hpp"

class RobotomyRequestForm : public Form
{
	private:
		std::string	_target;
		RobotomyRequestForm();
	public:
		RobotomyRequestForm(std::string const&);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const&);
		RobotomyRequestForm& operator=(RobotomyRequestForm const&);

		void execute(Bureaucrat const& executor) const;
};

#endif
