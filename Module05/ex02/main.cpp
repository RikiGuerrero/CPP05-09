#include "inc/Bureaucrat.hpp"
#include "inc/AForm.hpp"
#include "inc/ShrubberyCreationForm.hpp"
#include "inc/RobotomyRequestForm.hpp"
#include "inc/PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat b1("Bureaucrat1", 1);
	ShrubberyCreationForm f1("ShrubberyCreationForm1");
	RobotomyRequestForm f2("RobotomyRequestForm1");
	PresidentialPardonForm f3("PresidentialPardonForm1");

	b1.signForm(f1);
	b1.signForm(f2);
	b1.signForm(f3);

	b1.executeForm(f1);
	b1.executeForm(f2);
	b1.executeForm(f3);

	return 0;
}