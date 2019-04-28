# Odchudzanie plików .eps

Do skompilowania projektu potrzebne są:

  - CMake v3.5+
  - kompilator c++ (niezbędny standard c++14)
  - make

Dodatkowo do testowania:

  - boost (sudo apt-get install libboost-all-dev)

# Instalacja CMake

W terminalu:

	$ sudo apt-get install build-essential
	$ sudo apt-get install cmake

# Uruchomienie aplikacji

W terminalu:
	
	$ mkdir bin
	$ cd bin
	$ cmake ..
	$ make
	$ ./CompressEPS <ścieżka do wejściowego pliku> <ścieżka do wyjściowego pliku> <docelowa szerokość obrazu>
