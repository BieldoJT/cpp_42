#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const name, int const note)
	: _name(name), _grade(note)
{
	try
	{
		if (note < 1)
			throw GradeTooHighException();
		if (note > 150)
			throw GradeTooLowException();
		std::cout << "created" << std::endl;
	}
	catch (std::exception &e) {
        std::cout << "Erro ao criar objeto: " << e.what() << std::endl;
        throw; // <= re-lança a MESMA exceção pra fora
    }
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destroyed" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

/*
// 1. Opcional: Criar uma classe de exceção personalizada herdando de std::exception
class ErroDeValidacao : public std::exception {
public:
    const char* what() const noexcept override {
        return "Erro de validacao: O valor deve ser positivo.";
    }
};

// 2. Método (função) que pode lançar uma exceção
void processar_valor(int valor) {
    if (valor <= 0) {
        // Lança a exceção se a condição de erro for detectada
        throw ErroDeValidacao();
    }
    // Lógica de processamento se o valor for válido
    std::cout << "Valor processado com sucesso: " << valor << std::endl;

	TENTAR FAZER ISSOO !!!!!!!!!!!!!!!!!!!

} */
