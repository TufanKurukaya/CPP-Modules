#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        // Geçerli bir Bürokrat oluşturma
        Bureaucrat bob("Bob", 2);
        cout << bob << endl;

        // Dereceyi artırma (bu işlem başarıyla tamamlanır)
        bob.incrementGrade();
        cout << "After increment: " << bob << endl;

        // Dereceyi tekrar artırma (bu işlem bir istisna fırlatır çünkü derece 1'den düşük olamaz)
        bob.incrementGrade();  // Bu işlem istisna fırlatacak
    } catch (const std::exception &e) {
        cerr << "Caught an exception: " << e.what() << endl;
    }

    cout << endl;

    try {
        // Geçersiz bir derece ile Bürokrat yaratmaya çalışma (istisna fırlatılır)
        Bureaucrat jim("Jim", 151);
        cout << jim << endl;  // Bu satır çalışmaz
    } catch (const std::exception &e) {
        cerr << "Caught an exception while creating Jim: " << e.what() << endl;
    }

    cout << endl;

    try {
        // Geçerli bir Bürokrat oluşturma ve derecesini azaltma (başarıyla tamamlanır)
        Bureaucrat alice("Alice", 149);
        cout << alice << endl;

        // Dereceyi azaltma (150'ye kadar izin verilir)
        alice.decrementGrade();
        cout << "After decrement: " << alice << endl;

        // Dereceyi tekrar azaltma (bu işlem bir istisna fırlatır çünkü derece 150'den fazla olamaz)
        alice.decrementGrade();  // Bu işlem istisna fırlatacak
    } catch (const std::exception &e) {
        cerr << "Caught an exception: " << e.what() << endl;
    }

    return 0;
}
