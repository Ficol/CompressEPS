# Odchudzanie plików .eps

# Wymagania

Do skompilowania projektu potrzebne są:

  - CMake v3.5+ (sudo apt-get install cmake)
  - kompilator c++ (niezbędny standard c++14)
  - make (sudo apt-get install build-essential)

Dodatkowo do testowania:

  - boost (sudo apt-get install libboost-all-dev)

# Uruchomienie aplikacji

W terminalu:
	
	$ mkdir bin
	$ cd bin
	$ cmake ..
	$ make
	$ ./CompressEPS <ścieżka do wejściowego pliku> <ścieżka do wyjściowego pliku> <docelowa szerokość obrazu>
	$ ./CompressEPSTests #do uruchomienia testów
