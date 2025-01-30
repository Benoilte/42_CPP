#include "ShrubberyCreationForm.hpp"

int	ShrubberyCreationForm::m_signatureGrade = 145;
int	ShrubberyCreationForm::m_executionGrade = 137;

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("Shrubbery_Creation", m_signatureGrade, m_executionGrade),
	m_target("noTarget"),
	m_fileName("noTarget_shrubbery")
{
    /*Constructor*/
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &t_src) :
	AForm(t_src),
	m_target(t_src.m_target),
	m_fileName(t_src.m_fileName)
{
	/* Copy Constructor*/
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string t_target) :
	AForm("Shrubbery_Creation", m_signatureGrade, m_executionGrade),
	m_target(t_target),
	m_fileName(m_target + "_shrubbery")
{
	/* Parametrized Constructor*/
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	/*Destructor*/
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &t_rhs)
{
	if (this != &t_rhs)
		AForm::operator=(t_rhs);

	return *this;
}

const std::string ShrubberyCreationForm::getTarget(void) const
{
	return m_target;
}

void ShrubberyCreationForm::execute(Bureaucrat &t_executor) const
{
	std::ofstream		out;

	beExectuted(t_executor, *this);
	out.open(m_fileName.c_str());
	if (!out.is_open())
	{
		throw ShrubberyCreationForm::FileNotOpen();
	}
	out <<
	"          .     .  .      +     .      .          .\n"
	"     .       .      .     #       .           .\n"
	"        .      .         ###            .      .      .\n"
	"      .      .   *#:. .:##*##:. .:#*  .      .\n"
	"          .      . *####*###*####*  .\n"
	"       .     *#:.    .:#*###*#:.    .:#*  .        .       .\n"
	"  .             *#########*#########*        .        .\n"
	"        .    *#:.  *####*###*####*  .:#*   .       .\n"
	"     .     .  *#######**##*##**#######*                  .\n"
	"                .*##*#####*#####*##*           .      .\n"
	"    .   *#:. ...  .:##*###*###*##:.  ... .:#*     .\n"
	"      .     *#######*##*#####*##*#######*      .     .\n"
	"    .    .     *#####**#######**#####*    .      .\n"
	"            .     *      000      *    .     .\n"
	"       .         .   .   000     .        .       .\n"
	".. .. ..................O000O........................ ...... ..." << std::endl;
	out.close();
	std::cout << "A tree is created in file: " << m_fileName << std::endl;
}

const char	*ShrubberyCreationForm::FileNotOpen::what() const throw()
{
	return "Error: Shrubbery file cannot be created";
}

// std::ostream& operator<<(std::ostream &t_out, ShrubberyCreationForm const &t_rhs)
// {
// 	t_out << t_rhs.getFoo();
// 	return t_out;
// }
