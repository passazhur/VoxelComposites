#include "test_derivative.h"

#include "FEM/staticconstants.h"

using namespace FEM;

void Test_Derivative::test_Derivative()
{
    Polynomial f = 2*L1*L1*L2 - 3*L1*L3 + 4*L1 - 1;
    Polynomial df_dL1 = d_dL1 * f;

    Polynomial True = 4*L1*L2 - 3*L3 + 4;

    QVERIFY(True.summands.size() == df_dL1.summands.size() &&
            True.summands.size() == 3 &&
            True.summands.front().compare(df_dL1.summands.front()) &&
            True.summands.back().compare(df_dL1.summands.back()));

    Polynomial dL4_dL1 = d_dL4 * L1;
    QVERIFY(dL4_dL1.summands.empty());
}

void Test_Derivative::test_DerivativeMapped()
{
    MathUtils::Matrix::StaticMatrix<Polynomial,1,4> N;
    N(0,0) = L1;
    N(0,1) = L2;
    N(0,2) = L3;
    N(0,3) = L4;
    MathUtils::Matrix::StaticMatrix<DerivativeMapped,3,1> L;
    L(0,0) = d_dx;
    L(1,0) = d_dy;
    L(2,0) = d_dz;

    auto B = L * N;

    QVERIFY(B(0,0).summands.front().coef == 1);
    QVERIFY(B(0,1).summands.empty());
    QVERIFY(B(0,2).summands.empty());
    QVERIFY(B(0,3).summands.front().coef == -1);

    QVERIFY(B(1,0).summands.empty());
    QVERIFY(B(1,1).summands.front().coef == 1);
    QVERIFY(B(1,2).summands.empty());
    QVERIFY(B(1,3).summands.front().coef == -1);

    QVERIFY(B(2,0).summands.empty());
    QVERIFY(B(2,1).summands.empty());
    QVERIFY(B(2,2).summands.front().coef == 1);
    QVERIFY(B(2,3).summands.front().coef == -1);
}

void Test_Derivative::test_WeakOperator()
{
    MathUtils::Matrix::StaticMatrix<Polynomial,1,4> N;
    N(0,0) = L1;
    N(0,1) = L2;
    N(0,2) = L3;
    N(0,3) = L4;

    auto B = grad * N;

    QVERIFY(B(0,0).summands.front().coef == 1);
    QVERIFY(B(0,1).summands.empty());
    QVERIFY(B(0,2).summands.empty());
    QVERIFY(B(0,3).summands.front().coef == -1);

    QVERIFY(B(1,0).summands.empty());
    QVERIFY(B(1,1).summands.front().coef == 1);
    QVERIFY(B(1,2).summands.empty());
    QVERIFY(B(1,3).summands.front().coef == -1);

    QVERIFY(B(2,0).summands.empty());
    QVERIFY(B(2,1).summands.empty());
    QVERIFY(B(2,2).summands.front().coef == 1);
    QVERIFY(B(2,3).summands.front().coef == -1);
}
