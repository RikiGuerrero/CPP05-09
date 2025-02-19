#include "../inc/Form.hpp"

Form::Form(const std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute){}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		this->_signed = other.getSigned();
	return (*this);
}

Form::~Form(){}

std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getSigned() const
{
	return (this->_signed);
}

int Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw GradeTooHighException();
	this->_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("form grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("form grade is too low");
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Form: " << form.getName() << ", Signed: " << (form.getSigned() ? "Yes" : "No") 
		<< ", Grade to sign: " << form.getGradeToSign() 
		<< ", Grade to execute: " << form.getGradeToExecute();
	return (out);
}