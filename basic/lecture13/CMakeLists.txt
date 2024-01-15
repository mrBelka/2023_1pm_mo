cmake_minimum_required(VERSION 3.15) # Проверка версии CMake.
									 # Если версия установленой программы
									 # старее указаной, произайдёт аварийный выход.

set(PROJECT_NAME example) # задать значение PROJECT_NAME		 
project("${PROJECT_NAME}")           # установить имя проекта


set(CMAKE_CXX_STANDARD 17)			 # устанавливаем 17 стандарт языка
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


# Подключить header-файлы
include_directories("inc")

# Сказать программе, что должен быть исполняемый файл
add_executable("${PROJECT_NAME}" main.cpp inc/func.hpp src/func.cpp)

# Копирование файла
file(COPY "input.txt" DESTINATION "/")