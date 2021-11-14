# Automatyczna podlewaczka do roślin z funkcją odczytywania poziomu wody w zbiorniku

Jakub Perlak, Tomasz Gajda

## 1. Wstęp

Idea projektu powstała bazując na naszym zainteresowaniu działaniem Arduino i działających z nim mierników. Na początku chcieliśmy obsługiwać jedynie miernik wilgoci gleby, lecz szybko ten plan zmienił się w** plan minimum**. Aktualnie nasz moduł posiada kilka funkcjonalności więcej.


## 2. Projekt

### 2.1 - Technologie 
Do stworzenia projektu wykorzystaliśmy **Arduino** oraz **Labview**. Arduino użyte zostało do obsługi mierników i pompki, natomiast Labview wykorzystaliśmy do stworzenia ogólnodostępnego raportowania o aktualnym stanie układu. 


### 2.2 - Elementy
Do stworzenia projektu wykorzystane zostały:

- **Laptop** - służy do połączenia Arduino z Labview oraz daje minimalne zasilanie, które potrzebne jest do działania modułu, \

- **Płytka Arduino UNO** - mikrokontroler obsługujący wszystkie podłączone urządzenia korzystając z napisanego przez nas kodu,

- **Przewody połączeniowe**- kable niezbędne do połączenia wszystkich modułów w projekcie,

- **Miernik wilgotności gleby**- czujnik, który podaje wartość wilgotności gleby w przedziale od x do y,

- **Miernik poziomu cieczy**- czujnik, który mierzy na jakim poziomie znajduje się ciecz w zbiorniku - niestety powierzchnia sprawdzana jest mocno ograniczona,

- **Ekran LCD z modułem I2C**- komponent służący do komunikacji z użytkownikiem,

- **Pompa do cieczy 12V**- włączana warunkowo pompa służąca do podlewania rośliny.

Poza nimi, do poprawnego korzystania z urządzenia potrzebne są oczywiście:

- **Roślina**- obiekt testowy - do podlewania,

- **Zbiornik z wodą**- zbiornik, z którego układ będzie pobierał wodę do podlewania,


## 3. Implementacja

### 3.1 - Schemat obwodu (bez pompki)

![alt_text](https://github.com/nerooc/auto-watering-device/blob/main/images/circuit_schema.png)

**Rys. 11** - Schemat obwodu przedstawiający nasze urządzenie

### 3.2 - Działanie

Zasada działania układu jest prosta - miernik wilgoci gleby na bieżąco sprawdza stan nawodnienia i przekazuje dane do Arduino. Płytka przetwarza te dane decydując czy powinna włączyć pompkę i podlać roślinę, czy też nie.

Jednocześnie w zbiorniku podłączonym do pompki znajduje się miernik poziomu cieczy - dane z niego są przetwarzane i przedstawione w przystępnej dla użytkownika formie na ekranie LCD.

Mamy 4 rodzaje komunikatów:
- Water level: **HIGH**, 
- Water level: **MEDIUM**, 
- Water level: **LOW**, 
- Water level: **CRITICAL** 
   Replenish water in the tank! 

Od przetworzonego statusu poziomu cieczy zależy również działanie modułu podlewającego, jako że bez wody w zbiorniku, nie będzie on w stanie podlać rośliny.
Wszystkie dane zostają również przetworzone do formy raportu, który przesyłany jest do Labview.

### 3.3 - Labview
W Labview przyjmujemy dane z Arduino i prezentujemy je w formie raportu. Możemy je wtedy przeglądać w formie przedstawionej poniżej:

xxx

**Rys. 12** - Format przedstawienia raportu o stanie układu

## 4. Testy

### 4.1 - Testy automatyczne 
Kod wykorzystany do obsługi Arduino został zweryfikowany w automatycznym testerze edytora Arduino.  \


### 4.2 - Testy manualne 
Testy manualne zostały przeprowadzone na aloesie i szklance z wodą - system działał poprawnie, tak jak było to przez nas przewidywane. Nagrania z testów dostępne będą na Google Drive pod tym linkiem:  
xxx

## 5. Wnioski

Projekt sprawił nam bardzo dużo przyjemności, ponieważ praca z Arduino jest dość prosta i satysfakcjonująca.

## 6. Potencjalne ulepszenia

Gdyby nie ograniczona ilość czasu, którą mogliśmy poświęcić na ten projekt, z chęcią wdrożylibyśmy w życie pozostałe nasze pomysły na rozbudowę układu. Niestety jedyne co możemy zrobić, to podzielić się naszymi pomysłami:

- **Dodanie modułu łączącego Arduino z WI-FI** - xxx
- **Dodanie diody LED** - xxx
- **Dodanie głośnika** - xxx
