@echo off
g++ -std=c++17 main.cpp grid.cpp cell.cpp ab.cpp distance.cpp -o maze.exe
echo Build complete. Run with: maze.exe