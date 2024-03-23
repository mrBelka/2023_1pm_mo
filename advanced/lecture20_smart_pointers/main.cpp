#include <iostream>
#include <fstream>
#include <memory>

// N < 256 и a_i < 256, для всех i=1..N
// .txt - массив данных в формате N и a_i, где i=1..N (ASCII)
// .bin - массив данных в формате N и a_i, где i=1..N (bin)

class DataReader
{
protected:
	std::ifstream m_in;
	std::string m_filename;
	uint8_t* m_data;
	uint8_t m_n;

public:
	DataReader(const std::string& filename) : 
		m_filename(filename), m_n(0), m_data(nullptr)
	{

	}

	virtual ~DataReader() {
		//m_in.close();
	}

	virtual bool Open() = 0;
	void Close()
	{
		m_in.close();
	}

	virtual void Read() = 0;
	virtual void Write() = 0;

	void GetData(uint8_t* buf, uint8_t& n)
	{
		n = m_n;
		for (int i = 0; i < m_n; i++)
			buf[i] = m_data[i];
	}
};

class TxtReader : public DataReader
{
public:
	TxtReader(const std::string& filename) : DataReader(filename) {}
	virtual ~TxtReader() 
	{
		if(m_data != nullptr)
			delete[] m_data;
	}

	bool Open() override
	{
		m_in.open(m_filename);
		if (!m_in.is_open())
			return false;
		return true;
	}

	void Read() override
	{
		int tmp;
		m_in >> tmp;
		m_n = tmp;
		m_data = new uint8_t[m_n];
		for (int i = 0; i < m_n; i++)
		{
			int tmp;
			m_in >> tmp;
			m_data[i] = tmp;
		}
	}

	void Write() override
	{

	}
};

class BinReader : public DataReader
{
public:
	BinReader(const std::string& filename) : DataReader(filename) {}
	virtual ~BinReader()
	{
		if (m_data != nullptr)
			delete[] m_data;
	}

	bool Open() override
	{
		m_in.open(m_filename, std::ios::binary);
		if (!m_in.is_open())
			return false;
		return true;
	}

	void Read() override
	{
		m_in.read((char*)&m_n, 1);
		m_data = new uint8_t[m_n];
		m_in.read((char*)m_data, m_n);
	}

	void Write() override
	{

	}
};

// Copy-and-swap
// RAII

template <typename T>
class SmartPointer
{
	T* m;
	static size_t m_cnt;

public:
	SmartPointer(T x)
	{
		m = new T;
		*m = x;
		m_cnt++;
	}

	SmartPointer(const SmartPointer& other)
	{
		m = other.m;
		m_cnt++;
	}

	~SmartPointer()
	{
		m_cnt--;
		if(m_cnt == 0)
			delete m;
	}

	size_t use_count()
	{
		return m_cnt;
	}

	T data()
	{
		return *m;
	}
};

template <typename T>
size_t SmartPointer<T>::m_cnt = 0;

// auto_ptr - не используется
// unique_ptr - если не нужно копировать
// shared_ptr - копирование
// weak_ptr - 



std::unique_ptr<DataReader> Factory(const std::string& filename)
{
	std::string extension = filename.substr(filename.find_last_of('.') + 1);

	if (extension == "txt")
		return std::make_unique<TxtReader>(filename);
	else if (extension == "bin")
		return std::make_unique<BinReader>(filename);
	return nullptr;
}

class Student;

class Teacher
{
	std::shared_ptr<Student> m_s;

public:
	~Teacher()
	{
		std::cout << "Teacher destr" << std::endl;
	}
	void setStudent(std::shared_ptr<Student>& s)
	{
		m_s = s;
	}

	void Print()
	{
		std::cout << "AAA" << std::endl;
	}
};

class Student
{
	std::weak_ptr<Teacher> m_t;

public:
	~Student()
	{
		auto tmp = m_t.lock();
		std::cout << tmp << std::endl;
		if (tmp)
			tmp->Print();
		std::cout << "Students destr" << std::endl;
	}
	void setTeacher(std::shared_ptr<Teacher> t)
	{
		m_t = t;
	}
};

int main()
{
	std::shared_ptr<Teacher> t = std::make_shared<Teacher>();
	std::shared_ptr<Student> s = std::make_shared<Student>();

	t->setStudent(s);
	s->setTeacher(t);



	return 0;




	SmartPointer<int> p(10); // не делать

	{
		auto q = p;
		std::cout << p.use_count() << std::endl;
	}

	std::cout << p.use_count() << std::endl;
	


	uint8_t n;
	uint8_t buf[100];

	std::unique_ptr<DataReader> Reader = Factory("input2.bin");
	if (Reader == nullptr)
		return -1;
	Reader->Open();
	Reader->Read();
	Reader->GetData(buf, n);

	std::cout << (int)n << std::endl;
	for (int i = 0; i < n; i++)
		std::cout << (int)buf[i] << std::endl;

	//delete Reader;


	
	/*std::ifstream in("input2.bin", std::ios::binary);
	uint8_t n;
	in.read((char*)&n, 1);

	uint8_t* buf = new uint8_t[n];
	in.read((char*)buf, n);

	std::cout << (int)n << std::endl;

	for (int i = 0; i < n; i++)
		std::cout << (int)buf[i] << std::endl;

	delete[] buf;*/

	/*//Создание бинарного файла
	std::ofstream out("input2.bin", std::ios::binary);
	uint8_t buf[6];
	buf[0] = 5;
	for (int i = 0; i < 5; i++)
	{
		buf[i+1] = i+127;
	}

	out.write((char*)buf, 6);*/
}

