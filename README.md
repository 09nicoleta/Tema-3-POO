# Activitatea unui restaurant

Un restaurant are nevoie de un program care sa ii monitorizeze activitatea saptamanala. Prin urmare, programul realizeaza un rezumat al comenzilor restaurantului prin afisarea zilei cu cele mai multe vanzari, venitului total din vanzari(4) si numarului total de comenzi din fiecare tip de meniu (e2) atat zilnic cat si saptamanal.
Astfel, urmatoarele date sunt inregistrate in fisier: 
- Numarul de comenzi dintr-o zi
- Cate mese au fost ocupate in ziua respectiva
- Ce tipuri de meniuri au fost comandate la o masa specifica
- Ce masa a fost ocupata (id-ul mesei)
- Ora la care s-a luat comanda

*Pentru a testa programul, datele de intrare pot fi generate random (clasa SimulatorRestaurant). Astfel, la rularea programului, userul va decide ce date va analiza.*

Aceste informatii sunt prelucrate cu ajutorul claselor.
Clasa Meniu este clasa de baza pentru cele 3 tipuri de meniuri disponibile in restaurant: Meniul Principal, Meniul Special si Meniul cu Bauturi (2a). Aceasta modeleaza interfata derivatelor fiind o clasa abstracta (2c)
Clasa MasaRestaurant indexeaza date despre meniurile comandate, folosind un vector de pointeri (2e), id-ul mesei si timpul inregistrarii comenzii. Cu ajutorul pointerilor si polimorfismului, datele despre comenzi sunt prelucrate uniform. (2c)

Clasa Zi este folosita pentru a "uni" informatiile despre activitatea dintr-o zi specifica prin intermediul vectorului de tip MasaRestaurant.

*Voi face review lui Lica Daria - Pizza-Delivery*    

# Bibliografie:
  - https://www.geeksforgeeks.org/cpp/stdmt19937-class-in-cpp/ 
  - https://www.geeksforgeeks.org/dsa/stduniform_int_distribution-class-in-c/
  - https://www.geeksforgeeks.org/cpp/dynamic-_cast-in-cpp/
  - https://www.geeksforgeeks.org/cpp/exception-handling-c/
  - https://stackoverflow.com/questions/4303513/push-back-vs-emplace-back


