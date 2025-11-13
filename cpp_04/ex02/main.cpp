#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "===== DOG: COPY CONSTRUCTOR =====" << std::endl;
    {
        Dog original;
        original.getBrain().setIdea("I'm the original Dog", 0);

        Dog copy(original); // chama construtor de cópia

        // Muda só o original
        original.getBrain().setIdea("I'm the ideia changed in the original", 0);

        std::cout << "Original[0]: " << original.getBrain().getIdea(0) << std::endl;
        std::cout << "Copy    [0]: " << copy.getBrain().getIdea(0) << std::endl;
    }

    std::cout << "\n===== DOG: OPERATOR= =====" << std::endl;
    {
        Dog a;
        Dog b;

        a.getBrain().setIdea("Idea from A", 1);
        b.getBrain().setIdea("Idea from B", 1);

        b = a;


        a.getBrain().setIdea("Idea changed on A", 1);

        std::cout << "A[1]: " << a.getBrain().getIdea(1) << std::endl;
        std::cout << "B[1]: " << b.getBrain().getIdea(1) << std::endl;
    }

    std::cout << "\n===== CAT: COPY CONSTRUCTOR =====" << std::endl;
    {
        Cat original;
        original.getBrain().setIdea("Miau original", 2);

        Cat copy(original);

        original.getBrain().setIdea("Miau changed on original", 2);

        std::cout << "Original[2]: " << original.getBrain().getIdea(2) << std::endl;
        std::cout << "Copy    [2]: " << copy.getBrain().getIdea(2) << std::endl;
    }

    std::cout << "\n===== CAT: OPERATOR= =====" << std::endl;
    {
        Cat a;
        Cat b;

        a.getBrain().setIdea("Idea A cat", 3);
        b.getBrain().setIdea("Idea B cat", 3);

        b = a;

        a.getBrain().setIdea("Ideia A cat changed", 3);

        std::cout << "A[3]: " << a.getBrain().getIdea(3) << std::endl;
        std::cout << "B[3]: " << b.getBrain().getIdea(3) << std::endl;
    }

    return 0;
}
