**TBI2 - Zurück zu 0 und 1!**
=====================

-----------------------

##Kapitel dieses Tutorials:
* 0.1 Einführung
* 0.1.2 Der Interpreter
	* 0.1.2.1 Dateien öffnen
	* 0.1.2.2 Befehlszeileninterpreter
* 0.2 Zellen
* 0.3 Mov - Werte verschieben
* 0.4 Add - Addition
* 0.5 Mul - Multiplikation
* 0.6 Div - Division
* 0.7 Sub - Subraktion
* 0.8 DD - Zellen löschen
* 0.9 Inp - Input vom User
* 1.0 Out - Ausgabe
* 1.1 OutS - Zahlen in ASCII-Zeichen (Buchtsaben) umwandeln

###**0.1 Einführung**
TBI2 ist die fortsetzung zu dme ehemaligen TBI Interpreter. Verbessert und mit weniger Bugs kann sich der Triploit-Binary-Interpreter-V2 ruhig zeigen lassen. TBI war schon immer die einfachste möglichkeit in binär zu programmieren oder seine Freunde herauszufordern, das hat sich nicht geändert. TBI2 bietet dazu mehr Funktionen die es leichter machen mit den Zellen zu arbeiten und Input entgegenzunehmen.

Dieses Tutorial ist nicht an Anfänger gerichtet und schon gar nicht als erste Programmiersprache gedacht. Grundkenntnisse in Java, C++ oder anderen Programmiersprachen sind Vorraussetzung zum verständnis. Besonders Assembler-, Ny++-, Ny++5- oder TPL-Programmierer haben hierbei das große Los gezogen. Aber nun zum richtigen Start!

In diesem Tutorial werden Befehlsnamen wie...

	mov  = 110   = 6
	out  = 100   = 4
	outs = 101   = 5
	add  = 111   = 7
	mul  = 1000  = 8
	div  = 1001  = 9
	sub  = 1100  = 12
	inp  = 1010  = 10
	dd   = 1011  = 11
... verwendet. Diese Namen (Spalte 1) stehen für die dazugehörigen Dezimalzahlen (Spalte 3) und werden mit den Binärzahlen (Spalte 2) dargestellt.

Die dazugehörigen Zellen sind folgende:

	RXX = 11 = 3
	RYX = 1  = 1
	RZX = 10 = 2

Der Interpreter ist so aufgebaut, das er mit Argumenten arbeitet. Gehört eine Binärzahl zu keinem Befehl, wird sie in einem Argument abgespeichert. Beispiel an einem Input:

	> 01000101
Argument 2 wird auf `01000101` gesetzt. Danach gibt der User ...

	> 01101001
... ein. Argument 1 wird auf Argument 2 gesetzt und Argument 2 bekommt danach den Input. Danach sieht es also so aus:

	Argument1 = 01000101
	Argument2 = 01101001
Wenn der User jetzt `010010101` eingibt, sieht es dann wieder so aus:

	Argument1 = 01101001
	Argument2 = 010010101
Also wandert die Liste der Argumente immer mit der Eingabe mit.

###**0.1.2 Der Interpreter**

Der Interpreter ist in C++ geschrieben und für Windows erhältlich. Linux Portierungen kommen noch.

####**0.1.2.1 Dateien öffnen**

Das Dateiformat der zu ausführenden Datei sieht so aus:

	[Binärzahl1]
	[Binärzahl2]
	[Binärzahl3]
	...
Jede Binärzahl bekommt ihre eigene Zeile und wird daher auch mit einem Zeilenumbruch beendet.
Um so eine Datei auszuführen muss der Interpreter mit dem Argument als Datei aufgerufen werden:

	tbi2.exe [dateiname]
Die Dateiendung spielt dabei keine Rolle.

#### **0.1.2.2 Befehlszeileninterpreter**

Es ist auch möglich direkt mit dem Interpreter zu arbeiten. Dafür ruft man einfach nur die Anwendung mit einem Doppelklick auf.

Danach wird ein Input erwartet, dies wird mit einem `>` gekennzeichnet.

--------------------------------
###**0.2 Zellen**

Die Zellen in TBI, sind wie Variablen. Sie sind volle Integer und können mit ihrer Binärzahl repräsentiert werden. Diese wurden in der Einführung gezeigt.

--------------------------------
###**0.3 Mov - Werte verschieben**

Mov steht für "move" und kann Werte in Zellen verschieben. Das bedeutet das die Zelle erst gelöscht und danach einen neuen Wert erhält.

Mov hat diesen Aufbau:

	[Quelle(Wert)] [Ziel(Zelle)] MOV(110)
Wenn wir also nun beispielsweise eine 13 in die Zelle RXX schreiben wollen, tun wir dies so:

	 1101   11    110
	(Wert, Zelle, Mov)
Das sieht dann im Interpreter so aus:

	> 1101
	> 11
	> 110
Mov wurde dann erfolgreich ausgeführt und der Wert 13 steht in Zelle RXX.

**INFO: In Mov ist es nicht möglich Werte aus Zellen in Zellen zu verschieben.**

--------------------------------
###**0.4 Add - Addition**

Es ist möglich Zellen mit anderen Zellen zu Addieren. Der Aufbau ist wie bei Mov:

	[Quelle(Zelle)] [Ziel(Zelle)] ADD(111)

Wenn zum Beispiel Zelle RYX den Wert 17 und die Zelle RXX den Wert 13 hätte, dann würde nach diesem aufbau eine 30 in Zelle RXX stehen:

	    1    11    110
	(Zelle, Zelle, Add)
Das sieht dann im Interpreter so aus:

	> 1
	> 11
	> 111

(Lustiger Zufall, 1, 11, 111)
Add wurde dann erfolgreich ausgeführt und der Wert 30 steht in Zelle RXX.
Ürigends können wir diese Rechnungen überprüfen in dem wir `i` eingeben (`i`  fügt zu den Argumenten eine 0 hinzu) und Enter drücken:

	> 1
	> 11
	> 111
	> i
	RXX: 30
	RYX: 17
	RZX: 0
	> _
Das wäre dann soweit korrekt.

--------------------------------
###**0.5 Mul - Multiplikation**
#####**0.6 Div - Division**
#####**0.7 Sub - Subtraktion**

Multiplikation, Division und Subtraktion funktionieren nach dem gleichen Prinzip wie die Addition und es wird dabei einfach jeweils der Befehl ersetzt, die Argumente und Funktionsweise bleibt komplett gleich.

	mul = 1000 = 8
	div = 1001 = 9
	sub = 1100 = 12

--------------------------------
###**0.8 DD - Zellen löschen**

Um Zellen zu löschen, wird als Argument 2 der Zellenname erwartet und dann wird der Befehl geschrieben.

Aufbau von DD:

	[Ziel(Zelle)] [DD(1011)]

Ein Beispiel das auf das Beispiel der Addition zurückführt. Die Zelle RYX enthält den Wert 17:

	> i
	RXX: 30
	RYX: 17
	RZX: 0
	> 1
	> 1
	> 1011
Mit den zwei `1` werden Argument1 und Argument2 auf `1` gesetzt, damit man Zelle RYX danach löschen kann.

--------------------------------
###**0.9 Inp - Input**

Ein Input wäre auch in TBI undenkbar, daher gibt es ihn nun in TBI2. Der Aufbau ist wie folgt:

	[Inp(1010)]

Es benötigt weder ein Argument, noch etwas ähnliches.
Der Input wird in RXX **immer** gespeichert.

Ein Beispiel:

	> 1010
	12
	> i
	RXX: 12
	RYX: 0
	RZX: 0
	> _
Die Eingegebene 12 wird ohne NAchricht in RXX gespeichert ud kann von da aus weitergegeben werden.

--------------------------------
###**1.0 Out - Ausgabe**

Der Befehl Out bewirkt das der Wert einer Zelle ausgegeben wird. Diese Zelle muss in Argument2 stehen.
Der Aufbau ist so:

	[Ziel(Zelle)] [Out(100)]
Ein Beispiel dazu basierend auf dem von Input:

	12
	> i
	RXX: 12
	RYX: 0
	RZX: 0
	> 11
	> 11
	> 100
	12> _
Es sollte danach die Eingegebene 12 erscheinen. Da kein Zeilenumbruch geschieht, steht sie vor dem `>`. Zeilenumbrüche können wir übrigends einfach mit einem `@` Zeichen hervorrufen, was aber nur in einer Datei sinnvoll wäre. Auch ein @ Befehl ist ein Einzelner Befehl.

--------------------------------

###**1.1 OutS - Zahlen in ASCII-Zeichen (Buchstaben) umwandeln**

Nur Zahlen auszugeben wäre schlecht. Man würde kein ordentliches Programm schreiben können. Jedoch gibt es eine Methode, statt Zahlen, Buchstaben auszugeben. Diese Methode Funktioniert komplett gleich wie die Out-Funktion, jedoch aht sie einen anderen Binärwert(101):

	> 0100101
	> 11
	> 110
	> i
	RXX: 37
	RYX: 0
	RZX: 0
	> 11
	> 11
	> 101
	%> _

Und schon wurde die 37 in ihr zugeordnetes ASCII Zeichen umgewandelt. Im Internet findet man ASCII Tabellen die jeden Dezimalwert eines Zeichens beinhalten.

-------------------------------
###**2.0 Spezialwissen für die Faulen: Inline-Befehle**

Einen Inline-Befehl haben wir schon kennengelernt: `i`. Er zeigt alle Zellen und deren Werte an. Sowas ist ziemlich nützlich um einfacher zu programmieren:

* `wd` Zeigt alle eingegebenen Binärzahlen in Dezimal an
* `w` Zeigt alle Eingegebenen Binärzahlen an
* `c` löscht die Liste der Eingegebenen Binär und Dezimalzahlen
* `q` Den Befehlszeileninterpreter beenden und speichern wenn man möchte

Es gibt einen Nachteil dabei: Jedes dieser Zeichen hinterlässt eine `0` in den Argumenten, so wird aus:

	> 0110101 (Arg1 = 0;    Arg2 = 0110101 )
	> 11      (Arg1 = 0110101; Arg2 = 11   )
	> 110     (Arg1 = 11;   Arg2 = 110 )
	> 11      (Arg1 = 110;  Arg2 = 11  )
	> i       (Arg1 = 11;   Arg2 = 0   )
	RXX: 53
	RYX: 0
	RZX: 0
	> 100     (Arg1 = 11;   Arg2 = 0   )

ganz schnell mal ein Fehler, da `i` die 0 hinterlassen hat, obwohl man `i` gerne ignoriert hätte. (Natürlich sollten das in den Klammern dort nicht stehen, sonnst gibt es einen Error!)






###DevGruppe - Die Challenge

Schreibt mir ein Programm in TBI2, das eine logische Funktion erfüllt und sogar von normalen Usern benutzt werden kann. Es muss nicht perfekt sein, sollte jedoch mindestens mit Ein- und Ausgabe funktionieren.
