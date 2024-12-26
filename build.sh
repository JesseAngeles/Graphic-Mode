clear

# Limpiar directorio de compilación
mkdir -p build
rm -rf build/*

# Compilar los archivos fuente
g++ -c -std=c++17 -I./include main.cpp -o build/main.o

g++ -c -std=c++17 -I./include src/gui/MainWindow.cpp -o build/MainWindow.o
g++ -c -std=c++17 -I./include src/gui/Frame.cpp -o build/Frame.o
g++ -c -std=c++17 -I./include src/gui/Button.cpp -o build/Button.o
g++ -c -std=c++17 -I./include src/gui/TextBox.cpp -o build/TextBox.o
g++ -c -std=c++17 -I./include src/gui/ExampleFrame.cpp -o build/ExampleFrame.o
g++ -c -std=c++17 -I./include src/gui/ExampleButton.cpp -o build/ExampleButton.o
g++ -c -std=c++17 -I./include src/gui/ExampleTextBox.cpp -o build/ExampleTextBox.o

# Enlazar los objetos y generar el ejecutable
g++ build/main.o \
    build/MainWindow.o build/Frame.o build/Button.o build/TextBox.o \
    build/ExampleFrame.o build/ExampleButton.o build/ExampleTextBox.o \
    -o build/main.exe \
    -Iinclude -lsfml-graphics -lsfml-window -lsfml-system

# Ejecutar el programa
./build/main.exe