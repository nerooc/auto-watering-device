# Automatyczna podlewaczka do roślin z funkcją odczytywania poziomu wody w zbiorniku

Jakub Perlak, Tomasz Gajda

## 1. Projekt - wstęp
Początkowym założeniem projektu było utworzenie mechanizmu, który automatycznie podlewałby kwiat. Do jego wykorzystania zdecydowaliśmy się użyć Arduino razem z miernikiem wilgotności gleby oraz LabView do kontroli pompy wodnej. 
Jednakże, już w trakcie tworzenia układu napotkaliśmy trudności związane z implementacją naszych założeń. W związku z tym, postanowiliśmy zmienić nieco strukturę projektu - obsługę całego układu zrealizowaliśmy z wykorzystaniem Arduino (dodając przy tym obsługę poziomu wody w zbiorniku za pomocą odpowiedniego miernika), a samo LabView wykorzystaliśmy do generowania raportów związanych z podlewaniem.

## 2. Narzędzia projektowe

### 2.1 - Technologie 
Do stworzenia projektu wykorzystaliśmy Arduino oraz Labview. Arduino użyte zostało do obsługi mierników i pompki. Labview wykorzystaliśmy do stworzenia ogólnodostępnego raportowania o aktualnym stanie układu.


### 2.2 - Elementy główne

- **Laptop** - służy do połączenia Arduino z Labview oraz daje minimalne zasilanie, które potrzebne jest do działania modułu.

- **Płytka Arduino UNO** - mikrokontroler obsługujący wszystkie podłączone urządzenia, korzystając z napisanego przez nas kodu.

- **Przewody połączeniowe** - kable niezbędne do połączenia wszystkich modułów w projekcie.

- **Miernik wilgotności gleby** - czujnik, który podaje wartość wilgotności gleby w przedziale od X do Y.

- **Miernik poziomu cieczy** - czujnik, który mierzy poziom cieczy w zbiorniku.

- **Ekran LCD z modułem I2C** - komponent służący do komunikacji z użytkownikiem.

- **Pompa do cieczy 12V** - włączana warunkowo pompa służąca do dozowania cieczy.

### 2.3 - Elementy dodatkowe

- **Roślina** - obiekt testowy naszego układu.

- **Zbiornik z wodą** - zbiornik, z którego układ będzie pobierał wodę do podlewania.

## 3. Implementacja

### 3.1 - Schemat obwodu (bez pompki)

![obwod](https://github.com/nerooc/auto-watering-device/blob/main/images/circuit_schema.png)

**Rys. 1** - Schemat obwodu przedstawiający nasze urządzenie

### 3.2 - Zrealizowany układ

![uklad](https://user-images.githubusercontent.com/31045802/143782768-618ed63a-53f0-426e-b28f-a93bbcd93726.png)

**Rys. 2** - Zrealizowana przez nas automatyczna podlewaczka do roślin.

### 3.3 - Działanie mechanizmu

W zbiorniku podłączonym do pompki znajduje się miernik poziomu cieczy. Dane z tego urządzenia są przetwarzane i przedstawiane w przystępnej dla użytkownika formie na ekranie LCD.  
Mamy 2 rodzaje komunikatów:

- **Tank needs water!** - gdy wysokość wody w zbiorniku spada poniżej określonego poziomu.

- **Tank is fine!** - gdy poziom wody w zbiorniku jest wystarczająco wysoki.

Od przetworzonego statusu poziomu cieczy zależy również działanie modułu podlewającego, jako że bez wody w zbiorniku nie będzie on w stanie podlać rośliny.

Natomiast, miernik wilgoci gleby na bieżąco sprawdza stan nawodnienia i przekazuje dane pomiarowe do Arduino. Płytka przetwarza te dane, decydując, czy powinna włączyć pompkę i podlać roślinę, czy też nie. Jak wspomniano wcześniej, mechanizm ten zależy również od poziomu cieczy w zbiorniku.

W przypadku konieczności podlania kwiatu, dane są przekazywane do LabView, gdzie generowany jest odpowiedni raport.


### 3.4 - Labview -raporty
W Labview przyjmujemy dane z Arduino i prezentujemy je w formie raportu. Poniżej zaprezentowane zostały programy w LabView obsługujące zarówno przyjęcie danych z Arduino, jak i generowanie raportu.

![image](https://user-images.githubusercontent.com/31045802/143783042-6a9a8a87-6fc5-4da7-8bfc-dbd1a2f9a935.png)

**Rys. 3** - Program w LabView obsługujący dane przekazane z Arduino. 
Po lewej stronie Block Diagram, po prawej Front Panel.

![image](https://user-images.githubusercontent.com/31045802/143783054-1db3e714-b0c0-486f-9aa3-4dc292f104af.png)

**Rys. 4.** - Program w LabView obsługujący raporty. 
Po lewej stronie Block Diagram, po prawej Front Panel.

![image](https://user-images.githubusercontent.com/31045802/143783058-11fda8d3-5a60-44bd-a8ed-103c080c2a56.png)

**Rys. 5.** - Format przedstawienia raportu podlewania.

## 4. Testy

### 4.1 - Testy automatyczne 
Kod wykorzystany do obsługi Arduino został zweryfikowany w automatycznym testerze edytora Arduino. 

### 4.2 - Testy manualne 
Testy manualne zostały przeprowadzone w trakcie laboratoriów.
1. Gdy poziom wilgotności gleby był powyżej określonego, kwiat nie był podlewany.

2. Gdy poziom wilgotności gleby był poniżej określonego oraz w zbiorniku znajdowała się odpowiednia ilość wody, kwiat został podlany.
   a. Jeżeli poziom wilgotności ziemi zwiększył się do odpowiedniego poziomu, program nie uruchamiał już pompki.
   b. Jeżeli poziom wilgotności ziemi po podlaniu nadal nie osiągnął odpowiedniego poziomu, program ponownie uruchamiał pompkę.
Jednocześnie, program wygenerował raport o podlaniu.

3. Gdy poziom wilgotności gleby był poniżej określonego, ale w zbiorniku nie znajdowała się odpowiednia ilość wody, kwiat nie został podlany.
Jednocześnie, program wygenerował raport o braku możliwości podlania.

## 5. Potencjalny rozwój projektu

Przykładowymi pomysłami na potencjalny rozwój projektu w przyszłości są:
- utworzenie zorganizowanej i kompaktowej obudowy na cały mechanizm;
- dodanie diody LED i/lub głośnika, które informowałyby w bardziej zauważalny sposób użytkownika o konieczności uzupełnienia zbiornika;
- dodanie modułu łączącego Arduino z Wi-Fi.

## 6. Wnioski

1. Praca z Arduino jest prosta i intuicyjna.

2. LabView jest rozbudowanym narzędziem pozwalającym na tworzenie złożonych układów. Jest to jednak narzędzie o wysokim progu wejścia, któremu koniecznie trzeba poświęcić czas na zapoznanie się z jego możliwościami i mechanizmami.

3. Należy zadbać o odpowiednią obsługę błędów w LabView, szczególnie tych, na etapie połączenia z Arduino.
