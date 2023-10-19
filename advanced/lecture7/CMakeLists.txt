cmake_minimum_required(VERSION 3.15) # Проверка версии CMake.
									 # Если версия установленой программы
									 # старее указаной, произайдёт аварийный выход.

set(PROJECT_NAME test_cmake)	     # задать значение PROJECT_NAME		 
project("${PROJECT_NAME}")           # установить имя проекта


set(CMAKE_CXX_STANDARD 17)			 # устанавливаем 17 стандарт языка
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


# Добавим путь до директории inc
include_directories("inc/")

# Сказать программе, что должен быть исполняемый файл
add_executable("${PROJECT_NAME}" main.cpp 
				inc/functions.hpp src/functions.cpp
				inc/test.hpp)

# Скопировать директорию assets в корневую директорую проекта			  
file(COPY "assets" DESTINATION "/")