#include <iostream>

class Student {
private:
    int admno;
    std::string name;
    double eng, math, science;
    double total;

    double calculateTotal() {
        return total = eng + math + science;
    }

public:
    void takeData(int madmno, std::string msname, double meng, double mmath, double mscience) {
        admno = madmno;
        name = msname;
        eng = meng;
        math = mmath;
        science = mscience;
        calculateTotal();
    }

    void showData() {
        std::cout << "admno: " << admno << "\n";
        std::cout << "sname: " << name << "\n";
        std::cout << "eng: " << eng << "\n";
        std::cout << "math: " << math << "\n";
        std::cout << "science: " << science << "\n";
        std::cout << "total: " << total << "\n";
    }

    Student() { std::cout << "Constructed Student\n"; }
    ~Student() { std::cout << "Destructed Student\n"; }
};


int main()
{
    Student student1;
    student1.takeData(12345, "Ann Baker", 1.3, 2.5, 3.0);
    student1.showData();
    return 0;
}