#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "===== DOG: COPY CONSTRUCTOR =====" << std::endl;
    {
        Dog original;
        original.getBrain().setIdea("Eu sou o Dog original", 0);

        Dog copy(original); // chama construtor de cópia

        // Muda só o original
        original.getBrain().setIdea("Ideia mudada no original", 0);

        std::cout << "Original[0]: " << original.getBrain().getIdea(0) << std::endl;
        std::cout << "Copy    [0]: " << copy.getBrain().getIdea(0) << std::endl;
        // Se for DEEP COPY certo:
        //  - Original[0] -> "Ideia mudada no original"
        //  - Copy[0]     -> "Eu sou o Dog original"
    }

    std::cout << "\n===== DOG: OPERATOR= =====" << std::endl;
    {
        Dog a;
        Dog b;

        a.getBrain().setIdea("Ideia do A", 1);
        b.getBrain().setIdea("Ideia do B", 1);

        b = a; // usa operator=

        // Muda só A depois da atribuição
        a.getBrain().setIdea("Ideia mudada no A", 1);

        std::cout << "A[1]: " << a.getBrain().getIdea(1) << std::endl;
        std::cout << "B[1]: " << b.getBrain().getIdea(1) << std::endl;
        // Se for DEEP COPY:
        //  - B[1] continua com "Ideia do A" (cópia antiga), não muda junto com A
    }

    std::cout << "\n===== CAT: COPY CONSTRUCTOR =====" << std::endl;
    {
        Cat original;
        original.getBrain().setIdea("Miau original", 2);

        Cat copy(original);

        original.getBrain().setIdea("Miau alterado no original", 2);

        std::cout << "Original[2]: " << original.getBrain().getIdea(2) << std::endl;
        std::cout << "Copy    [2]: " << copy.getBrain().getIdea(2) << std::endl;
    }

    std::cout << "\n===== CAT: OPERATOR= =====" << std::endl;
    {
        Cat a;
        Cat b;

        a.getBrain().setIdea("Ideia A cat", 3);
        b.getBrain().setIdea("Ideia B cat", 3);

        b = a;

        a.getBrain().setIdea("Ideia A cat alterada", 3);

        std::cout << "A[3]: " << a.getBrain().getIdea(3) << std::endl;
        std::cout << "B[3]: " << b.getBrain().getIdea(3) << std::endl;
    }

    return 0;
}
