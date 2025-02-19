#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : AForm(other), _target(other._target){}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	std::ofstream file((_target + "_shrubbery").c_str());
	file << "         *         " << std::endl;
	file << "        ***        " << std::endl;
	file << "       *****       " << std::endl;
	file << "      *******      " << std::endl;
	file << "     *********     " << std::endl;
	file << "    ***********    " << std::endl;
	file << "   *************   " << std::endl;
	file << "  ***************  " << std::endl;
	file << " ***************** " << std::endl;
	file << "        |||        " << std::endl;
	file << "        |||        " << std::endl;
	file << "        |||        " << std::endl;
	file.close();
}