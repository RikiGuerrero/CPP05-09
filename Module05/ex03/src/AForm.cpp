#include "../inc/AForm.hpp"

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute){}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->_signed = other.getSigned();
	return (*this);
}

AForm::~AForm(){}

std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::getSigned() const
{
	return (this->_signed);
}

int AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw GradeTooHighException();
	this->_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("form grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("form grade is too low");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("form is not signed");
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << "Form: " << form.getName() << ", Signed: " << (form.getSigned() ? "Yes" : "No") 
		<< ", Grade to sign: " << form.getGradeToSign() 
		<< ", Grade to execute: " << form.getGradeToExecute();
	return (out);
}