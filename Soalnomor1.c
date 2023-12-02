#include <stdio.h>

// Fungsi untuk menghitung kapasitansi total
float hitungCtotal(float c1, float c2, float c3, float c4, float c5, float c6, float c7)
{
    float cs1, cp1, cs2, cp2, ctotal;

    // Menghitung cs1 (c6 diserikan dengan c7)
    cs1 = 1 / ((1 / c6) + (1 / c7));
    printf(" total c1=%.2lf\n", cs1);

    // Menghitung cp1 (cs1 di paralel dengan c5)
    cp1 = cs1 + c5;
    printf(" total cp1=%.2lf\n", cp1);

    // Menghitung cs2 (cp1 diserikan dengan c4)
    cs2 = 1 / ((1 / cp1) + (1 / c4));
    printf(" total cs2=%.2lf\n", cs2);

    // Menghitung cp2 (cs2 di paralel dengan c3)
    cp2 = cs2 + c3;
    printf("total cp2 = %.2lf\n", cp2);

    // Menghitung ctotal (c1 diserikan dengan c2 dan cp2)
    ctotal = 1 / ((1 / c1) + (1 / c2) + (1 / cp2));

    return ctotal;
}

int main()
{
    // Nilai-nilai kapasitor
    float c1 = 10, c2 = 20, c3 = 10, c4 = 20, c5 = 10, c6 = 20, c7 = 10;
    float tegangan = 50;

    // Menghitung kapasitansi total
    float hasilCtotal = hitungCtotal(c1, c2, c3, c4, c5, c6, c7);

    // Menghitung Q total (muatan total)
    float qTotal = tegangan * hasilCtotal;

    //menghitung q1-q7
    float cs1 = 1 / ((1 / c6) + (1 / c7));
    float cp1 = cs1 + c5;
    float cs2 = 1 / ((1 / cp1) + (1 / c4));
    float cp2 = cs2 + c3;

    float q1 = (c2 / (c1 + c2 + hasilCtotal)) * qTotal;
    float q2 = (c1 / (c1 + c2 + hasilCtotal)) * qTotal;
    float qp2 = qTotal - (q1 +q2);
    float q4 = (cp1 / (cp1 + c4)) * qp2;
    float qp1 = q2 - qp2;
    float q6 = (c7 / (c6 + c7)) * qp1;
    float q7 = qp1 - q6;

    // Menampilkan hasil
    printf("Kapasitansi Total: %.2f Farad\n", hasilCtotal);
    printf("Q totalnya adalaj :%.2f Coulomb\n", qTotal);
    printf("Q1: %.2f Coulomb\n", q1);
    printf("Q2: %.2f Coulomb\n", q2);
    printf("Q3: %.2f Coulomb\n", qp2);
    printf("Q4: %.2f Coulomb\n", q4);
    printf("Q5: %.2f Coulomb\n", qp1);
    printf("Q6: %.2f Coulomb\n", q6);
    printf("Q7: %.2f Coulomb\n", q7);


    return 0;
}
