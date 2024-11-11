#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        // Bürokrat oluşturma
        Bureaucrat highRank("Alice", 1);    // Derece 1 (en yüksek)
        Bureaucrat lowRank("Bob", 150);     // Derece 150 (en düşük)

        // Formları oluşturma
        ShrubberyCreationForm shrubbery("Home");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm pardon("Zaphod");

        // Form bilgilerini görüntüleme
        std::cout << shrubbery << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << pardon << std::endl;

        // Formları imzalama girişimi
        std::cout << "\n-- Formları İmzalama --" << std::endl;
        lowRank.signForm(shrubbery); // Yetersiz dereceli bürokrat
        highRank.signForm(shrubbery); // Başarılı imzalama
        highRank.signForm(robotomy); // Başarılı imzalama
        highRank.signForm(pardon); // Başarılı imzalama

        // Formları yürütme girişimi
        std::cout << "\n-- Formları Yürütme --" << std::endl;
        lowRank.executeForm(shrubbery); // Yetersiz derece ile yürütme
        highRank.executeForm(shrubbery); // Başarılı yürütme
        highRank.executeForm(robotomy); // Başarılı yürütme (rastgele sonuç)
        highRank.executeForm(pardon); // Başarılı yürütme

    } catch (const std::exception &e) {
        std::cerr << "Hata: " << e.what() << std::endl;
    }

    return 0;
}
