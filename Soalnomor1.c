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

float hitungRtotal(float r1, float r2, float r3, float r4, float r5, float r6, float r7)
{
    float ra, rb, rc, rp1, rp2, rp3, rp4, rs1, rs2, rtotal;

    ra = r6 + r7 + ((r6 * r7) / r5);
    rb = r5 + r6 + ((r5 * r6) / r7);
    rc = r4 + r7 + ((r4 * r7) / r5);
    rp1 = 1 / ((1 / ra) + (1 / rb));
    rp2 = 1 / ((1 / rp1) + (1 / r3));
    rp3 = 1 / ((1 / rc) + (1 / r4));
    rp4 = 1 / ((1 / rp2) + (1 / rp1));
    rs1 = 1 / ((1 / rp4) + (1 / rp3));
    rs2 = 1 / ((1 / rs1) + (1 / r1) + (1 / r2));

    rtotal = rs2;
    return rtotal;
}

int main()
{
    int pilihan = 0;
    while (pilihan != 3)
    {
        printf("\nPilihan:\n1. Perhitungan Kapasitor\n2. Transformasi Resistor\n3. Selesai\n");
        printf("Masukkan pilihan Anda: ");
        scanf("%d", &pilihan);
        if (pilihan == 1)
        {
            // Nilai-nilai kapasitor
            float c1 = 10, c2 = 20, c3 = 10, c4 = 20, c5 = 10, c6 = 20, c7 = 10;
            float tegangan = 50;

            // Menghitung kapasitansi total
            float hasilCtotal = hitungCtotal(c1, c2, c3, c4, c5, c6, c7);

            // Menghitung Q total (muatan total)
            float qTotal = tegangan * hasilCtotal;

            // menghitung q1-q7
            float cs1 = 1 / ((1 / c6) + (1 / c7));
            float cp1 = cs1 + c5;
            float cs2 = 1 / ((1 / cp1) + (1 / c4));
            float cp2 = cs2 + c3;

            float q1 = (c2 / (c1 + c2 + hasilCtotal)) * qTotal;
            float q2 = (c1 / (c1 + c2 + hasilCtotal)) * qTotal;
            float qp2 = qTotal - (q1 + q2);
            float q4 = (cp1 / (cp1 + c4)) * qp2;
            float qp1 = q2 - qp2;
            float q6 = (c7 / (c6 + c7)) * qp1;
            float q7 = qp1 - q6;

            // Menghitung V1-V7
            float v1 = q1 * c1;
            float v2 = q2 * c2;
            float v3 = qp2 * c3;
            float v4 = q4 * c4;
            float v5 = qp1 * c5;
            float v6 = q6 * c6;
            float v7 = q7 * c7;

            // Hasil Ctotal
            printf("Kapasitansi Total: %.2f Farad\n", hasilCtotal);

            // Hasil Qtotal
            printf("Q totalnya adalaj :%.2f Coulomb\n", qTotal);

            // Hasil Q1-Q7
            printf("Q1: %.2f Coulomb\n", q1);
            printf("Q2: %.2f Coulomb\n", q2);
            printf("Q3: %.2f Coulomb\n", qp2);
            printf("Q4: %.2f Coulomb\n", q4);
            printf("Q5: %.2f Coulomb\n", qp1);
            printf("Q6: %.2f Coulomb\n", q6);
            printf("Q7: %.2f Coulomb\n", q7);

            // Hasil V1-V7
            printf("V1: %.2f Volt\n", v1);
            printf("V2: %.2f Volt\n", v2);
            printf("V3: %.2f Volt\n", v3);
            printf("V4: %.2f Volt\n", v4);
            printf("V5: %.2f Volt\n", v5);
            printf("V6: %.2f Volt\n", v6);
            printf("V7: %.2f Volt\n", v7);
        }
        else if (pilihan == 2)
        {
            float r1 = 10, r2 = 20, r3 = 10, r4 = 20, r5 = 10, r6 = 20, r7 = 10;
            float v = 50;

            // Menghitung Rtotal
            float hasilRtotal = hitungRtotal(r1, r2, r3, r4, r5, r6, r7);

            // Menghitung i total
            float itotal = v / hasilRtotal;

            // Menghitung i1-i7
            float i1 = itotal;
            float i2 = itotal; // disini hanya sampe i2 karna sisanya sudah kepakai di transfomasinya

            // Menghitung V1 dan V2
            float V1 = i1 * r1;
            float V2 = i2 * r2;

            // Menampilkan hasil perhitungan Rtotal
            printf("Rtotal: %.2f Ohm\n", hasilRtotal);
            printf("I1: %.2f Ampere\n", i1);
            printf("I2: %.2f Ampere\n", i2);
            printf("V1: %.2f Volt\n", V1);
            printf("V2: %.2f Volt\n", V2);
        }
        else if (pilihan == 3){
            printf("Terima kasih, program telah selesai.\n");
        }
        else {
            printf("Pilihan tidak valid.\n");
        }
    }

    return 0;
}
