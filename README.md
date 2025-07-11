# Rocketsensors

## Descrizione

**Rocketsensors** è un progetto sviluppato per il corso di **Programmazione ad Oggetti** e rappresenta un'applicazione per la gestione dei sensori. Consente di visualizzare, modificare, simulare e cancellare sensori ambientali, di livello e di posizione. L'app offre un'interfaccia grafica intuitiva per gestire diversi tipi di sensori: temperatura, pressione, carburante e posizione.

## Funzionalità

- **Aggiungi sensore**: Crea un nuovo sensore selezionando il tipo e impostando le sue caratteristiche.
- **Modifica sensore**: Modifica le proprietà esistenti di un sensore (nome, descrizione, valori specifici).
- **Simula sensore**: Simula i dati del sensore e visualizza i grafici aggiornati in tempo reale.
- **Elimina sensore**: Rimuovi un sensore dal database.
- **Visualizzazione dei dati**: Mostra informazioni dettagliate e grafici per ciascun sensore.

## Tipi di sensori

1. **Temperatura**: Visualizza i valori minimo, massimo e medio della temperatura con monitoraggio delle soglie.
2. **Pressione**: Mostra la pressione corrente con indicatori di soglia.
3. **Carburante**: Monitora il livello del carburante, la capacità e il flusso.
4. **Posizione**: Visualizza altitudine, longitudine e latitudine.

## Prerequisiti

- **Qt Framework**: Utilizzato per l'interfaccia grafica (QWidget, QPushButton, QVBoxLayout, ecc.).
- **C++11**: Linguaggio principale usato per l'implementazione del progetto.

## Installazione

1. Clona il repository:
   ```bash
   git clone https://github.com/edgarcarlos/rocketsensors.git
2. Accedi alla cartella del progetto:
   ```bash
   cd rocketsensors/src
3. Compila il progetto:
   ```bash
   qmake
   make
4. Avvia l'applicazione:
   ```bash
   ./RocketSensors

## Utilizzo
- **Menu Home**: Dal menu Home puoi accedere alle opzioni per visualizzare i sensori.
- **Lista dei sensori**: Clicca su ciascun sensore per visualizzare i dettagli o modificarlo.
- **Simulazione**: Clicca sul pulsante "Simulate" per avviare una simulazione dei dati del sensore.

## Contesto del progetto
Questo progetto è stato realizzato come parte del corso di Programmazione ad Oggetti presso l'Università degli Studi di Padova. L'obiettivo è stato quello di applicare i principi di programmazione ad oggetti per la gestione di entità complesse (sensori) e interfacce grafiche utilizzando il framework Qt.


