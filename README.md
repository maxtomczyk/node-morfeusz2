# Bindingi Node.js dla biblioteki Morfeusz 2
Biblioteka umożliwia korzystanie z biblioteki Morfeusz2 w Node.js w sposób natywny.

## Kompatybilność
Kompatybilne platformy:
 * Mac OS 64-Bit (darwin_x64, testowane na macOS 10.15)
 * Linux 64-bit (linux_x64, tesotwane na ubuntu 19.04)

## Wersja oprogramowania Morfeusz 2
Ten projekt używa oprogramowania Morfeusz 2 w wersji **1.9.13**, z załączonym słownikiem SGJP.

## Instalacja
Instalacja przebiega jak dla innych modułów Node.JS.
```bash
  npm i https://github.com/maxtomczyk/node-morfeusz2 --save
```
W zależności od platformy na której uruchomiona jest instalacja mogą zosta wykonane dodatkowe czynnoście umożliwiające jak najłatwiejsze uruchomienie programu.

## Użycie
```javascript
// Przykładowy plik .js
const morfeusz = require('morfeusz2')
morfeusz.version() // 1.19.13
```
Wszystkie dostępne metody są opisane poniżej.

## Dostępne metody 
Już wkrótce

## Znane problemy
#### "Library not loaded, Reason: image not found"
Błąd ten dotyczy prawdopodobnie braku, lub błędnej wartości zmiennej środowiskowej **LD_LIBRARY_PATH** (dotyczy linux'a). W takim wypadku należy spróbować przeładowa terminal przy pomocy polecenia `source ~/.bashrc`, lub `. ~/.bashrc`. Jeśli to nie poskutkuje, należy sprawdzić, czy w pliku `~/.bashrc` znajduje się kod odpowiedzialny za utworzenie odpowiedniej wartości tej zmiennej.
Kod ten można wykonać ręcznie, lub wprowadzić go do powyższego pliku w celu automatyzacji tego procesu: `export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/path/to/morfeusz2/module`.

Można także uruchomić aplikacje wykorzystującą bibliotekę ze zdefiniowaną zmienną w następujący sposób: 
```bash
LD_LIBRARY_PATH=/path/to/morfeusz2/module node index.js
```
To rozwiązanie może okazać szczególnie przydatne przy dostarczaniu kodu wykorzystującego morfeusza2 na serwer.

#### Problemy z nvm
Po instalacji w na linux'ie, jeśli system korzysta z NVM (Node Version Manager), może zostać wyświetlony błąd o braku kompatybilności z 'npm config prefix'. Należy wtedy postępować zgodnie z poleceniami na ekranie, to jest: 
```bash
unset "npm_config_prefix"
nvm use 10.16.3 // Dowolna wersja wcześniej używana przez nvm
```

## Odpowiedzialność
Twórcy tego wrappera, podobnie jak właściciela praw autorskich do wszelkich zasobów programu Morfeusz 2 nie ponoszą żadnej odpowiedzialności za działanie programu, oraz nie udzielają na jego działanie żadnej gwarancji.

## Warunki udostępnienia programu Morfeusz 2
### Prawa autorskie
* Właścicielem praw autorskich programu Morfeusz 2 jest Instytut Podstaw Informatyki PAN.
* Autorami i właścicielami praw autorskich danych fleksyjnych SGJP są Zygmunt Saloni, Włodzimierz Gruszczyński, Marcin Woliński, Robert Wołosz i Danuta Skowrońska.
* Właścicielem praw autorskich danych fleksyjnych Polimorf jest Instytut Podstaw Informatyki PAN.

**Program i zawarte w nim dane fleksyjne zostają niniejszym nieodpłatnie udostępnione na tzw. dwuklauzulowej licencji BSD**

*Więcej informacji znajduje się w pliku LICENSE*