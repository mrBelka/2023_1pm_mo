#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <map>

namespace mt
{
#pragma pack(1)
    struct Node
    {
        Node* next; // 8
        char ch;    // 8 (выравнивание) -> 1
        Node* prev; // 8
    };
#pragma pack()


    class String
    {
    private:
        // поля
        char* m_str;                    // 8 + 1000
        unsigned long long m_length;    // 8

    public:
        // методы
        // Конструктор
        String(char* str)
        {
            std::cout << "Const" << std::endl;
            m_length = strlen(str);
            m_str = new char[m_length + 1];
            for (int i = 0; i < m_length; i++)
                m_str[i] = str[i];
            m_str[m_length] = '\0';
        }

        // Конструктор копирования
        // Оператор присваивания копированием

        // Деструктор
        ~String()
        {
            std::cout << "Destr" << std::endl;
            delete[] m_str;
        }

        unsigned long long length()
        {
            return m_length;
        }
    };

    template<typename T>
    class Vector
    {
    private:
        T* m_storage;
        unsigned long long m_size;

    public:
        Vector(T* storage, int n)
        {
            m_size = n;
            m_storage = new T[n];
            for (int i = 0; i < m_size; i++)
                m_storage[i] = storage[i];
        }

        int size()
        {
            return m_size;
        }

        ~Vector()
        {
            delete[] m_storage;
        }
    };
}

// 4 байта
void print(int x)
{

}

// константная ссылка
void countConsonant(const std::string& s)
{
    //s[10] = 'a';
    // s;
}

int main()
{
    std::string name[3] = { "CPU","GPU","RAM" };
    int mas[3] = { 10, 15, 20 };

    // n элементов (<100000), то кол-во операций (сложность) линейно зависит от длины массива
    // m - кол-во запросов (<100000)
    // 10^10 операций - массив
    // 20*100000 = 2*10^6 - std::map (красно-черное дерево, бинарное дерево поиска)

    // АСД

    std::map<std::string, int> m{ {"CPU", 10}, {"GPU", 15}, {"RAM", 20} };

    m.insert({ "Test", 10 });
    m["CPU"] = 15;
    std::cout << m["CPU"] << std::endl;

    if (m.find("CPU") != m.end())
    {
        std::cout << "11";
    }
    else
    {
        std::cout << "22";
    }

    auto tmp = m.find("CPU");
    tmp->first;
    tmp->second;



    //std::cout << m.find("CPU1") << std::endl;

    /*int n = 0;
    int mas[10];
    std::fill(mas, mas + 10, 2);


    std::array<int, 10> arr{1,2,3};
    arr.fill(2);
    std::cout << arr.size() << std::endl;
    std::cout << arr.max_size() << std::endl;*/

    // std::vector
    /*int* p = new int[10];
    

    int* q = new int[20];
    // копирование из p в q
    delete[] p;

    //q;*/

    /*int mas[10] = {1,2,3,4};
    mt::Vector<int> vec(mas, 4);

    std::vector<int> v = {1,2,3,4,5,6};
    v.reserve(1000);
    //v.resize(4, 0);
    for (int i = 0; i < 10; i++)
    {
        //std::cout << v[i] << std::endl;
        int x;
        std::cin >> x;
        v.push_back(x);
        std::cout << v.size() << " " << v.capacity() << std::endl;
        //v.shrink_to_fit();
    }*/

    /*v.size();
    v[1];
    v.at(1);
    v.erase(v.begin() + 1);
    v.insert(v.begin(), 12);*/


    //mt::String s("Hello, world");

    //s.length();


    // amd64
    // arm
    // mips

    // std::string
    /*std::string s1 = "Hello, world";
    std::string s2 = "Test";
    std::string s3 = s1 + s2;

    std::cout << s1[15] << std::endl;

    s1.c_str();
    s1.substr(0, 2);
    s1.erase(2, 1);
    s1.at(15) = 'a';
    s1.find('a', 10);
    s1.rfind('a');

    if (s1.find('a', 10) != std::string::npos)
    {

    }

    s1.length();
    
    if (s1 < s2)
    {

    }

    std::string s = "123.567123456789";
    float d = std::stod(s);*/



    return 0;
}