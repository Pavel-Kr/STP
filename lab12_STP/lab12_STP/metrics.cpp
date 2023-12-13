#include "metrics.h"

void calculateMetrics(metricConstants constants) {

    int n = constants.n1 + constants.n2;
    int N = constants.N1 + constants.N2;

    // ������������� ����� ����������
    double VV = (2 + constants.eta) * std::log2(2 + constants.eta);         // � �����

    // ����� ����������
    double V = N * std::log2(n);                        // � �����

    // ������� ��������� ����� ������������� �����
    double L = VV / V;

    // ������� ��������� �� ����������
    double LL = (static_cast<double>(constants.n1) / constants.N1) * (static_cast<double>(constants.n2) / constants.N2);

    // ���������������� ���������� ���������
    double I = LL * V;

    // �������������� ����� ��������� ���������, ���������� ����� ������������� �����
    double T1 = (V * V) / (constants.S * VV);

    // �������������� ����� ��������� ���������, ���������� ����� ����� ����������, ��������� �� ��������
    double T2 = (constants.n2 * constants.N2 * (constants.n1 * std::log2(constants.n1) + 
        constants.n2 * std::log2(constants.n2)) * std::log2(n)) / (2 * constants.S * constants.n2);

    // �������������� ����� ��������� ���������, ���������� ����� ����������� �������������� ����������
    double T3 = (constants.n1 * constants.N2 * N * std::log2(n)) / (2 * constants.S * constants.n2);

    // ������� �������� ������ ����� ����������������
    double l = L * L * V;

    std::cout << "������������� ����� ���������� (VV): " << VV << std::endl;
    std::cout << "����� ���������� (V): " << V << std::endl;
    std::cout << "������� ��������� ����� ������������� ����� (L): " << L << std::endl;
    std::cout << "������� ��������� �� ���������� (LL): " << LL << std::endl;
    std::cout << "���������������� ���������� ��������� (I): " << I << std::endl;
    std::cout << "�������������� ����� ��������� ���������, ���������� ����� ������������� ����� (T1): " << T1 << std::endl;
    std::cout << "�������������� ����� ��������� ���������, ���������� ����� ����� ����������, ��������� �� �������� (T2): " << T2 << std::endl;
    std::cout << "�������������� ����� ��������� ���������, ���������� ����� ����������� �������������� ���������� (T3): " << T3 << std::endl;
    std::cout << "������� �������� ������ ����� ����������������: " << l << std::endl;
}

void one() {
    std::cout << "1.    �������� ����������� ������� ����������� �������\n"
        "      �����, ��� �������� � �������� ��� �������" << std::endl << std::endl;

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
    std::cout << "2.    ���������� ����������� ������� � ������� �����������\n"
        "      ������� ��������" << std::endl << std::endl;

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
    std::cout << "3.    �������� ����� �������� � ������������� ����������\n"
        "      �������" << std::endl << std::endl;

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
    std::cout << "4.    �������� ����������� ������� ���������� �������\n"
        "      �����, ��� �������� � �������� ��� ��������" << std::endl << std::endl;

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
    std::cout << "5.    ����������� ������������ �������� ���������\n"
        "      ����������� ������� � �������� �������" << std::endl << std::endl;

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
    std::cout << "6.    ������������ ����������� ����� ���������\n"
        "      ����������� ������� �� �������� ����� ������� �����" << std::endl << std::endl;

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
    std::cout << "7.    �������� ��� ��������� �������������� �������� �\n"
        "      ������������� ������" << std::endl << std::endl;

    metricConstants cs;
    cs.eta = 4;
    cs.n1 = 9;
    cs.n2 = 6;

    cs.N1 = 13;
    cs.N2 = 15;

    cs.S = 15;

    calculateMetrics(cs);
}