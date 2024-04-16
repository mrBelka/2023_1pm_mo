#include <iostream>
#include <vector>
#include <cassert>

/*void swap(int& a, int& b)
{
    std::cout << "int" << std::endl;
    int tmp = a;
    a = b;
    b = tmp;
}

void swap(float& a, float& b)
{
    std::cout << "float" << std::endl;
    float tmp = a;
    a = b;
    b = tmp;
}

void swap(double& a, double& b)
{
    std::cout << "double" << std::endl;
    double tmp = a;
    a = b;
    b = tmp;
}*/

template<typename T>
void swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
class OtherMatrix
{
    T** m_mat;
    unsigned int m_n;
    unsigned int m_m;

public:
    OtherMatrix(unsigned int n, unsigned int m)
    {
        m_n = n;
        m_m = m;
        m_mat = new T*[m_n];
        for (int i = 0; i < m_n; i++)
            m_mat[i] = new T[m_m];
    }
    OtherMatrix(const OtherMatrix& other) : OtherMatrix(other.m_n, other.m_m)
    {
        for (int i = 0; i < m_n; i++)
            for (int j = 0; j < m_m; j++)
                m_mat[i][j] = other.m_mat[i][j];
    }
    OtherMatrix& operator=(const OtherMatrix& other)
    {
        for (int i = 0; i < m_n; i++)
            delete[] m_mat[i];
        delete[] m_mat;

        m_n = other.m_n;
        m_m = other.m_m;
        m_mat = new T*[m_n];
        for (int i = 0; i < m_n; i++)
            m_mat[i] = new T[m_m];

        for (int i = 0; i < m_n; i++)
            for (int j = 0; j < m_m; j++)
                m_mat[i][j] = other.m_mat[i][j];
    }
};

template<typename T, int N, int M>
class Matrix
{
    T m_mat[N][M];

public:
    Matrix()
    {
        srand(time(0));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                m_mat[i][j] = rand() % 10;
    }
    Matrix(const std::vector<std::vector<T>>& mat)
    {
        assert(mat.size() == N);
        for (int i = 0; i < N; i++)
            assert(mat[i].size() == M);

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                m_mat[i][j] = mat[i][j];
    }
    Matrix(const Matrix& other)
    {
        std::cout << "Copy constr" << std::endl;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                m_mat[i][j] = other.m_mat[i][j];
    }
    Matrix& operator=(const Matrix& other) = default;

    void Print()
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
                std::cout << m_mat[i][j] << " ";
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void set(unsigned int i, unsigned int j, T value)
    {
        m_mat[i][j] = value;
    }

    // Return value optimization
    Matrix operator*(const Matrix& other)
    {
        Matrix result;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                T sum = 0;
                for (int k = 0; k < M; k++)
                    sum += m_mat[i][k] * other.m_mat[k][j];
                result.set(i, j, sum);
            }
        return result;
    }

};

using Mat22i = Matrix<int, 2, 2>;
using Vec2i = Matrix<int, 2, 1>;


int main()
{
    Mat22i m1({{ 1, 2 },
               { 3, 4 }});

    Mat22i m2({ { 5, 6 },
                { 7, 8 } });
    
    m1.Print();
    m2.Print();

    //Mat22i m3 = m1.mult(m2); // C = A*B;

    Mat22i m3 = m1 * m2; // copy ellision
    //m3.Print();

    //std::cout << m1 << std::endl;

    //m2 = m1;

    //OtherMatrix<int> m3(2, 2);
    //OtherMatrix<int> m4(3, 3);
    //m3 = m4;

    /*float a = 2;
    int b = 3;
    swap(a, b);*/
    return 0;
}