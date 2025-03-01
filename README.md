PROGRAMMA CON INTERFACCIA DA LINA DI COMANDO PER CREARE, MODIFICARE ED ELIMINARE ATTIVITÀ DA SVOLGERE (TO-DOs)

-------- INPUT ACCETTATI (non sensibili alle maiuscole) -----------

"nuovo" -> per creare una nuova attività

"rimuovi" -> per rimuovere un'attività

"modifica" -> per cambiare la descrizione di un'attività

"completa" -> per contrassegnare un'attività come completata

"exit" -> per chiudere correttamente il programma

------- DESCRIZIONE DELLE CLASSI ----------

main.cpp

Istanzia un GestoreFile per la persistenza dei dati (salvare su disco alla chiusura e leggere da disco ad ogni avvio del programma), un ClickHandler (che gestisce gli input da tastiera dell'utente) e una ListaAttivita (struttura dati per la gestione di liste di attività).

Control/TipoInput.h

Enumerazione utilizzata per assegnare ad ogni comando da tastiera un valore. Utilizzato da InputHandler.h.

Control/InputHandler

Gestisce l'input da tastiera (convertito in forma di TipoInput). Possiede un riferimento al tipo ListaAttivita.

Domain/Attivita.h

Classe base, da cui derivano AttivitaSemplice e AttivitaImportante. Espone i metodi per convertire un oggetto in stringa da poter salvare su file e per istanziare un oggetto partendo da una stringa caricata da file.

Domain/ListaAttivita.h

Composta da un vettore di Attivita, si occupa di rappresentare un insieme di attività. Espone, tra l'altro, il metodo stampa(), per visualizzare sulla console la lista di attività rappresentata dall'oggetto in questione.

Persistence/GestoreFile.h

Carica le informazioni da file e si assume la responsabilità di salvare i cambiamenti, se richiesto.

test/*

All'interno della cartella sono contenuti i test di unità per le classi sopra e la libreria di Google Test.

-------- ALTRE INFORMAZIONI -------------

* Le attività sono salvate all'interno del file "prova.txt".
* Non è possibile inserire un'attività la cui descrizione contenga il carattere ";".
* L'organizzazione delle classi permette di poter creare e gestire più liste di attività salvate su più file diversi, ma non sono previsti comandi da tastiera per la creazione di nuove liste.
* Il salvataggio su file deve essere confermato alla chiusura, dopo che è stato mandato il comando "exit".
