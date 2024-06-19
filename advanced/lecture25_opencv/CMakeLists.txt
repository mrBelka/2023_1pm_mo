cmake_minimum_required(VERSION 3.15) # Проверка версии CMake.
									 # Если версия установленой программы
									 # старее указаной, произайдёт аварийный выход.

set(PROJECT_NAME libs) # задать значение PROJECT_NAME		 
project("${PROJECT_NAME}")           # установить имя проекта


set(CMAKE_CXX_STANDARD 17)			 # устанавливаем 17 стандарт языка
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories("./")
include_directories("./ext/OpenCV490/include")
link_directories("./ext/OpenCV490/lib")

# Сказать программе, что должен быть исполняемый файл
add_executable("${PROJECT_NAME}" app.cpp)

target_link_libraries("${PROJECT_NAME}" opencv_core490d opencv_video490d
			opencv_highgui490d opencv_videoio490d opencv_imgproc490d)
			
#file(COPY "ext/OpenCV490/dll" DESTINATION "/")