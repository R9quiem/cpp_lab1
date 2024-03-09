#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

std::string solveEquation(const std::string& equationFile) {
    std::ifstream inFile(equationFile);

    if (!inFile.is_open()) {
        std::cerr << "Ошибка. Не получается открыть файл с уравнением\n\n";
        return "";
    }

    double a, b, c;

    if (!(inFile >> a >> b >> c)) {
        std::cerr << "Ошибка. Некорректные данные в файле.\n\n";
        return "";
    }

    std::cout << "Данные успешно считаны с файла.\n\n";

    if (a == 0) {
        std::cerr << "Ошибка. В квадратном уравнении коэффициент 'a' не может быть равен 0.\n\n";
        return "";
    }
    double D = b * b - 4 * a * c;

    if (D < 0) {
        std::cout << "Квадратное уравнение успешно решено.\n\n";
        return "0 корней";
    }
    else if (D == 0) {
        double root = -b / (2 * a);
        std::cout << "Квадратное уравнение успешно решено.\n\n";
        return "Один корень: " + std::to_string(root);
    }
    else {
        double root1 = (-b + std::sqrt(D)) / (2 * a);
        double root2 = (-b - std::sqrt(D)) / (2 * a);
        std::cout << "Квадратное уравнение успешно решено.\n\n";
        return "Два корня: " + std::to_string(root1) + ", " + std::to_string(root2);
    }

    std::cout << "Квадратное уравнение успешно решено.\n\n";
}
void writeAnswer(const std::string& resultFile, const std::string& roots) {
    std::ofstream outFile(resultFile);

    if (!outFile.is_open()) {
        std::cerr << "Ошибка. Не получается открыть файл для записи результатов\n\n";
        return;
    }

    outFile << roots;
    outFile.close();
    std::cout << "Результаты записаны в файл " << resultFile << " .\n\n";
}

int main()
{
    setlocale(LC_ALL, "RU");
    std::string equationFile = "equation.txt";
    std::string resultFile = "result.txt";

    std::string answer = solveEquation(equationFile);

    writeAnswer(resultFile, answer);

    return 0;
}