#include "metrics.h"

void calculateMetrics(metricConstants constants) {

    int n = constants.n1 + constants.n2;
    int N = constants.N1 + constants.N2;

    // потенциальный объем реализации
    double VV = (2 + constants.eta) * std::log2(2 + constants.eta);         // в битах

    // объём реализации
    double V = N * std::log2(n);                        // в битах

    // уровень программы через потенциальный объем
    double L = VV / V;

    // уровень программы по реализации
    double LL = (static_cast<double>(constants.n1) / constants.N1) * (static_cast<double>(constants.n2) / constants.N2);

    // интеллектуальное содержание программы
    double I = LL * V;

    // прогнозируемое время написания программы, выраженное через потенциальный объем
    double T1 = (V * V) / (constants.S * VV);

    // прогнозируемое время написания программы, выраженное через длину реализации, найденную по Холстеду
    double T2 = (constants.n2 * constants.N2 * (constants.n1 * std::log2(constants.n1) + 
        constants.n2 * std::log2(constants.n2)) * std::log2(n)) / (2 * constants.S * constants.n2);

    // прогнозируемое время написания программы, выраженное через метрические характеристики реализации
    double T3 = (constants.n1 * constants.N2 * N * std::log2(n)) / (2 * constants.S * constants.n2);

    // среднее значение уровня языка программирования
    double l = L * L * V;

    std::cout << "Потенциальный объем реализации (VV): " << VV << std::endl;
    std::cout << "Объём реализации (V): " << V << std::endl;
    std::cout << "Уровень программы через потенциальный объем (L): " << L << std::endl;
    std::cout << "Уровень программы по реализации (LL): " << LL << std::endl;
    std::cout << "Интеллектуальное содержание программы (I): " << I << std::endl;
    std::cout << "Прогнозируемое время написания программы, выраженное через потенциальный объем (T1): " << T1 << std::endl;
    std::cout << "Прогнозируемое время написания программы, выраженное через длину реализации, найденную по Холстеду (T2): " << T2 << std::endl;
    std::cout << "Прогнозируемое время написания программы, выраженное через метрические характеристики реализации (T3): " << T3 << std::endl;
    std::cout << "Среднее значение уровня языка программирования: " << l << std::endl;
}

void one() {
    std::cout << "1.    Отыскать минимальный элемент одномерного массива\n"
        "      целых, его значение и значение его индекса" << std::endl << std::endl;

    metricConstants cs;
    cs.eta = 4;
    cs.n1 = 9;
    cs.n2 = 7;

    cs.N1 = 21;
    cs.N2 = 22;

    cs.S = 15;
    
    calculateMetrics(cs);
}

void two() {
    std::cout << "2.    Сортировка одномерного массива в порядке возрастания\n"
        "      методом пузырька" << std::endl << std::endl;

    metricConstants cs;
    cs.eta = 4;
    cs.n1 = 11;
    cs.n2 = 8;

    cs.N1 = 35;
    cs.N2 = 32;

    cs.S = 15;

    calculateMetrics(cs);
}

void three() {
    std::cout << "3.    Бинарный поиск элемента в упорядоченном одномерном\n"
        "      массиве" << std::endl << std::endl;

    metricConstants cs;
    cs.eta = 7;
    cs.n1 = 16;
    cs.n2 = 12;

    cs.N1 = 31;
    cs.N2 = 28;

    cs.S = 15;

    calculateMetrics(cs);
}

void four() {
    std::cout << "4.    Отыскать минимальный элемент двумерного массива\n"
        "      целых, его значение и значение его индексов" << std::endl << std::endl;

    metricConstants cs;
    cs.eta = 7;
    cs.n1 = 14;
    cs.n2 = 15;

    cs.N1 = 36;
    cs.N2 = 37;

    cs.S = 15;

    calculateMetrics(cs);
}

void five() {
    std::cout << "5.    Осуществить перестановку значений элементов\n"
        "      одномерного массива в обратном порядке" << std::endl << std::endl;

    metricConstants cs;
    cs.eta = 5;
    cs.n1 = 9;
    cs.n2 = 7;

    cs.N1 = 16;
    cs.N2 = 21;

    cs.S = 15;

    calculateMetrics(cs);
}

void six() {
    std::cout << "6.    Осуществлять циклический сдвиг элементов\n"
        "      одномерного массива на заданное число позиций влево" << std::endl << std::endl;

    metricConstants cs;
    cs.eta = 5;
    cs.n1 = 14;
    cs.n2 = 14;

    cs.N1 = 33;
    cs.N2 = 35;

    cs.S = 15;

    calculateMetrics(cs);
}

void seven() {
    std::cout << "7.    Заменить все вхождения целочисленного значения в\n"
        "      целочисленный массив" << std::endl << std::endl;

    metricConstants cs;
    cs.eta = 4;
    cs.n1 = 9;
    cs.n2 = 6;

    cs.N1 = 13;
    cs.N2 = 15;

    cs.S = 15;

    calculateMetrics(cs);
}