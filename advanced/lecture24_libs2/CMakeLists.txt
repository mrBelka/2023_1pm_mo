cmake_minimum_required(VERSION 3.15) # Проверка версии CMake.
									 # Если версия установленой программы
									 # старее указаной, произайдёт аварийный выход.

set(PROJECT_NAME libs) # задать значение PROJECT_NAME		 
project("${PROJECT_NAME}")           # установить имя проекта


set(CMAKE_CXX_STANDARD 17)			 # устанавливаем 17 стандарт языка
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories("./")
include_directories("MyLib/include")

# Создать статическую библиотеку
add_library(MyStaticLib STATIC 
	MyLib/include/func.hpp 
	MyLib/src/func.cpp
	MyLib/include/math.hpp 
	MyLib/src/math.cpp)

add_library(MyDynLib SHARED func.hpp func.cpp)

# Сказать программе, что должен быть исполняемый файл
add_executable("${PROJECT_NAME}" MyLib/app/main.cpp)

target_link_libraries("${PROJECT_NAME}" MyStaticLib)