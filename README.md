# ProjektGrafy
 część analityczna i analiza algorytmu:
[TeoriaGrafów_PiotrPyrczak.pdf](https://github.com/ppiotrekp/ProjektGrafy/files/6575862/TeoriaGrafow_PiotrPyrczak.pdf)
W zadaniu 7 wagi dobierałem losowo, również z tych samych wag korzystałem w części programistycznej.

#
część programistyczna:
Do uruchomienia programu potrzebne są 2 pliki. test.txt, z którego jest wczytywana macierz sąsiedztwa i main.cpp, w którym jest zaimplementowany algorytm wypisujący maksymalna przepustowość w grafie. Macierz sąsiedztwa działa w ten sposób, że w 0 wierszu są połączenia zerowego wierzchołka z resztą wierzchołków z odpowiednimi wagami. Dla przykładu w 0 wierszu mamy 0, 3, 2, 0, 0, 0, 0, 3, 3, 0, 4 - to oznacza, że zerowy wierzchołek jest połączony z samym sobą z wagą 0, z wierzchołkiem 1 z wagą 3, z wierzchołkiem 2 z wagą 2 itd. W 73 linii jest wczytanie macierzy z pliku, trzeba podać całą ścieżkę dostępu do niego. Pliki main.cpp i test.txt muszą być w tym samym folderze. Algorytm był implementowany w Clionie, więc może być też potrzebny plik CMakeLists.txt. 
#





