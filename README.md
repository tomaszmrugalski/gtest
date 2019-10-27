# Podstawy
### wyświetlenie tego pliku

```console
cat info.txt
```

### Komendy można kopiować myszką. Zaznacz lewym przyciskiem, wklej środkowym

### Pobranie źródeł
### Pobierz repozytorium za pomocą gita i umieść lokalną kopię w
### katalogu lab4

```console
git clone https://github.com/tomaszmrugalski/gtest-demo lab4
```

### Pobranie CUnit

```console
wget -nd https://downloads.sourceforge.net/project/cunit/CUnit/2.1-3/CUnit-2.1-3.tar.bz2
```

### Rozpakowanie, kompilacja i instalacja

```console
tar xvf CUnit-2.1-3.tar.bz2
cd CUnit-2.1-3
autoreconf -i
./configure --prefix=/home/student/lab3/cunit
make -j5
make install
```

### Pobranie google test (gtest)
wget https://github.com/google/googletest/archive/release-1.8.1.tar.gz

### Rozpakowanie (kompilacja nie jest konieczna!)
tar xvf release-1.8.1.tar.gz

## Kompilacja
### Przejrzyj plik Makefile
cat Makefile

### Zbuduj testy gtests
make gtests

### Zbuduj testy ctests
make ctests

### Uruchom wszystkie testy
make check

# Zbuduj wszystko
make all

# Ogarnij ten syf
make clean

# Informacje o makrach gtest
https://github.com/google/googletest/blob/master/googletest/docs/primer.md

# Kilka użytecznych komend git

# Pokaż, które pliki się lokalnie zmieniły
git status

# Pokaż różnice wprowadzone lokalnie
git diff
git diff plik1.cc

# Jeżeli zmiany sa ok, możemy je wcheckinować
git add zmieniony-plik.cc
git commit -m "Poprawilem test na silnie"

# Jeżeli jednak zmiany nie są ok, to można je cofnąć
git status
git checkout zmieniony-plik.cc

# Jeżeli kompletnie wszystko zawiedzie, można całkowie odrzucić
# lokalne zmiany:
git reset --hard

# I do tego jeszcze wywalić wszystko, co nie jest pod kontrolą gita
git clean -fxd
