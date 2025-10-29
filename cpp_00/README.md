# CPP Module 00 — Documentação de Estudos

## Exercícios implementados: ex00 (Megaphone) e ex01 (PhoneBook)
## Padrão: C++98 (-std=c++98)
## Compilação recomendada: c++ -Wall -Wextra -Werror -std=c++98

# 1) Visão Geral do que foi usado

- Headers padrão

		<iostream>: entrada/saída com std::cout, std::cin, std::endl.

		<string>: manipulação de texto com std::string.

		<iomanip>: formatação de saída (ex.: std::setw, alinhamento e largura fixa de colunas).

		<sstream>: parsing de strings como stream (std::istringstream) para converter texto em número no C++98.

		<ctype.h>: utilitários de caractere (toupper) usados no ex00.

		(quando necessário) <limits>: utilitários como std::numeric_limits (útil ao combinar >> e getline).

## Conceitos de C++

	Classes, encapsulamento e métodos: Contact e PhoneBook separam responsabilidades e protegem dados.

	Array fixo de objetos: armazenamento de até 8 contatos sem alocação dinâmica.

	I/O com streams: std::cin/std::cout + std::getline para entradas completas com espaços.

	Formatação tabular: std::setw e alinhamento para colunas de 10 caracteres.

	Parsing seguro em C++98: std::istringstream para ler um inteiro a partir de uma linha.

	Validação de entrada: checagem de vazio, conversão bem-sucedida, e faixas/índices válidos.

# 2) Arquivos e responsabilidades
##	megaphone.cpp

	O que faz: lê os argumentos de linha de comando e imprime em MAIÚSCULAS; sem argumentos, mostra uma mensagem padrão.

	Por que <iostream> e <ctype.h>:

	std::cout para imprimir;

	toupper para converter cada caractere para maiúsculo em estilo C compatível com C++98.

##	Contact.hpp / Contact.cpp

	O que faz: representa um contato.

	Por que classe: encapsular dados (nome, sobrenome, apelido, telefone, segredo) e expor apenas getters/métodos necessários.

	Construtores: inicializam o objeto de forma consistente.

	Getters: padronizam o acesso e preservam encapsulamento.

##	PhoneBook.hpp / PhoneBook.cpp

	O que faz: gerencia um conjunto de até 8 contatos, com:

	inserção circular (substitui o mais antigo ao passar de 8),

	listagem com tabela (colunas de largura fixa),

	exibição detalhada por índice.

	Por que array fixo: é o que o módulo pede (sem alocação dinâmica e sem STL de containers).

	Por que <iomanip>: formatar colunas com largura 10 e alinhamento à direita, fazendo truncagem manual (9 chars + ponto).

##	main.cpp

	O que faz: loop de comandos ADD | SEARCH | EXIT interativo.

	Por que <sstream>: converter a entrada textual do índice em inteiro com C++98, sem std::stoi (C++11).

	Por que std::getline: ler linhas completas, inclusive com espaços (ex.: nomes compostos).

# 3) Decisões de Design (e “por quês”)
##	3.1. Encapsulamento (classes Contact e PhoneBook)

		Por quê: separar o modelo (dados do contato) da lógica de gerenciamento (agenda), evitando acesso direto e desordenado aos campos e facilitando manutenção/testes.

##	3.2. Array fixo de 8 contatos

		Por quê: requisito do módulo; evita alocação dinâmica neste estágio e simplifica a política de substituição (índice % 8).

##	3.3. Inserção circular com index % 8

		Por quê: quando passar de 8, o próximo contato substitui o mais antigo; simples e constante em tempo/memória.

##	3.4. Saída tabular com largura fixa

		Por quê: requisito didático de formatação: cada coluna com 10 caracteres, texto alinhado e truncagem quando exceder:

		Regra prática: se size() > 10, imprimir 9 caracteres + "." para sinalizar corte.

	std::setw(10): garante a largura mínima;

	alinhamento: std::right (números e rótulos), mantendo consistência visual.

##	3.5. std::getline + std::istringstream (C++98)

Por quê:

	std::getline lê a linha inteira (inclui espaços);

	std::istringstream permite parsear a linha com a mesma semântica de std::cin >>, mas a partir de um buffer em memória, o que substitui std::stoi no padrão C++98.

# 4) Padrões de I/O e validação
##	4.1. Diferença entre >> e std::getline

	operator>> (em std::cin) para no primeiro espaço;

	std::getline lê até o \n.

	Se misturar: faça um std::cin.ignore(...) antes da primeira getline para descartar o \n pendente (ou use getline para tudo).

##	4.2. Conversão segura string → int no C++98

	Use std::getline para pegar a linha e depois:

	std::istringstream iss(line);
	int value;
	if (iss >> value) {
    // opcional: iss >> std::ws; checar se não sobrou lixo com iss.peek()
	} else {
    // conversão inválida
	}


Por quê: std::stoi não existe no C++98 e std::atoi não diferencia bem erros; istringstream oferece parsing robusto e idiomático.

##	4.3. Checagens de entrada

Campos vazios: rejeitar com s.empty() (ou checar “só espaços” se quiser ser mais estrito).

Índice: validar faixa antes de acessar o array (ex.: 1..qtd e nunca negativo).

# 5) Formatação de tabela (colunas de 10)

	std::setw(10) afeta apenas o próximo <<.

	Aplique sempre imediatamente antes do campo a imprimir.

	Truncagem manual (regra didática): se o texto excede 10, use 9 + “.”.

	Alinhamento: std::right (padrão) deixa a tabela mais legível em números/índices.

# 6) Erros e armadilhas comuns (e como evitar)


 - “Incomplete type” para std::istringstream

   - Causa: esquecer #include <sstream>.
   - Solução: incluir o header correto no arquivo que usa o tipo.

 - std::setw aplicado no separador

   - Causa: usar std::setw(10) << "|", o padding cai no "|".

   - Solução: aplique setw no dado, e só então imprima o separador.

 - Misturar >> e getline sem limpar buffer

   - Causa: >> deixa \n; a primeira getline lê vazio.

   - Solução: um std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); antes da primeira getline após um >>.

- Truncagem incorreta

   - Causa: cortar para 10 e ainda adicionar “.” (vira 11).

   - Solução: cortar para 9 e adicionar “.”, totalizando 10.

 - Validação fraca do índice

   - Causa: aceitar índices fora da faixa ou negativos.

   - Solução: checar limites antes do acesso.

# 7) Como compilar e executar
## Compilar (exemplo)
	c++ -Wall -Wextra -Werror -std=c++98 megaphone.cpp -o megaphone

	c++ -Wall -Wextra -Werror -std=c++98 Contact.cpp PhoneBook.cpp main.cpp -o phonebook

## Executar
	./megaphone "hello world"
	./phonebook


Ajuste o seu Makefile para refletir alvos, flags e dependências corretas.

# 8) Possíveis melhorias (didáticas, sem alterar requisitos)

 - Sanitização de telefone (apenas dígitos/+, etc.).

 - Repetição de prompt ao encontrar campo inválido (até preencher 5 válidos).

 - Mensagens de erro mais específicas (vazio, formato inválido, fora da faixa).

 - Separação de responsabilidades I/O vs. lógica (ex.: métodos “puros” que não imprimem).

 - Testes manuais (roteiros de entradas para cobrir casos de borda).

# 9) Checklist de revisão rápida

 - Compila com -std=c++98 e sem warnings (-Wall -Wextra -Werror).

 - Não usa std::stoi/STL de containers/algoritmos.

 - Contact e PhoneBook com papéis claros e dados encapsulados.

 - Tabela com colunas de 10, truncagem de strings maiores (9 + “.”).

 - Conversão de índice com std::istringstream e validação de faixa.

 - Sem mistura problemática de >> e getline (ou com ignore correto).

 - Sem alocação dinâmica desnecessária (array fixo de 8 contatos).
