---
marp: true
theme: uncover
header: Atelier debug
footer: ![width:5em](assets/tutor.svg)

style: |
    section {
        font-family: monospace;
    }
    footer {
        text-align: right;
    }
    section.slide li {
    font-size: 0.65em;
    }
    section.slide h1 {
    font-size: 0.8em;
    }
    section.slide h2 {
    font-size: 0.7em;
    }
    section.slide p {
    font-size: 0.55em;
    }
---
# Les bases du debug
gdb, valgrind & cie
![width:10em](assets/gnu.svg)

---
<!-- _class: slide -->
# Sommaire
0) Objectifs de cet atelier
1) Valgrind: 
    a. Compiler pour le debug (-g3 et ses amis)
    b. Command-line flags
    c. Lecture de l'output (backtrace, types de leaks et erreurs diverses)
    d. Integrer Valgrind a son workflow //TODO
    d. De l'importance des erreurs Valgrind
2) GDB: GNU Debugger
    a. Quand utiliser un debugger ?
    b. Demonstration & visualisation du workflow
3) Conclusion
--- 
<!-- _class: slide -->
# 0) Objectifs de cet atelier

- Mieux comprendre Valgrind et ses applications
- Decouvrir GDB et son workflow
- Avoir des outils pour diagnostiquer les problemes de conception logique


--- 
<!-- _class: slide -->
# 1) Valgrind
<!--- Valgrind c'est plus que seulement Memcheck -->
- Multitude d'outils: Memcheck, Helgrind, CacheGrind... 
- Execute le programme sur un CPU virtuel
- Desassemble le code, ajoute ses tests et recompile le tout
- Affiche les erreurs rencontree en basant sur les informations de debug generee par le flag -g[1, 2, 3]
- ⚠️ **Ralentit** les programmes (jusqu'a 50x plus lents)

```
# le meme programme avec et sans Valgrind:
-----------------------------------------
./btc inputs/input.txt          | 0.00s |
valgrind ./btc inputs/input.txt | 0.47s |
```


--- 
<!-- _class: slide -->
# 1) Valgrind / Compiler pour le debug
- Les flags de debug sont relatifs au **compilateur** :
```
gcc -Werror -Wextra -Wall -g3 | <= coucou !
```
- Permettent d'ajouter ou de retirer des informations au binaire.
- ⚠️ Ils **alourdissent** les programmes.

```
| FLAG                 | POIDS  | BINAIRE |
-------------------------------------------
| -g3 [maximum d'info] | 175664 |  btc    |
| -g0 [pas d'info]     | 80248  |  btc    |
| -0fast [optimise]    | 47496  |  btc    |
```
--- 
<!-- _class: slide -->
# 1) Valgrind / Command-line flags
```
# El famoso:
 --leak-check=full              | active la backtrace
 --show-leaks-kind=all          | active le suivi de tous les types de leak
 --trace-children=yes           | monitore les produits des forks
 --track-fds=yes                | monitore les fds utilises par le programme

# Utiles:
 --q & --v                      | quiet et verbose, pour avoir plus ou moins d'informations
 --log-file="filename"          | redirige l'output de Valgrind dans un fichier
 --suppressions=<filename>      | permet d'ignorer les leaks provenant de certains appels de fonction
 --gdb-attach=yes               | apres chaque message d'erreur, prompt a ouvrir GDB au point ou l'erreur est intervenue. 
                                | Reprend l'exec ou elle s'etait arretee apres la sortie de GDB
```

- Tous disponibles sur le [man de Valgrind](https://www.cs.cmu.edu/afs/cs/academic/class/15213-s03/labs-save/L4/share/doc/valgrind/manual.html#flags).

---
<!-- _class: slide -->
# 1) Valgrind / Lecture de l'output
## a. La backtrace
- Permet de suivre le cycle de vie de votre pointeur,
- Voir ou il recupere un retour de fonction ou est realloue,
- Se lit de bas en haut
```
|-----------------------------------------------------------------------------------------------------|
| PROCESS ID | STACK ADDRESS  | FUNCTION CALL                 | EXPLICATION                           |
|------------|----------------|-------------------------------|---------------------------------------|  ^
| ==43274==  | at 0x4848899:  | malloc (in /path/to/malloc)   | la memoire perdue a ete allouee ici...|  | 6
| ==43274==  |   by 0x10A387: | ft_calloc (in /path/to/this)  | par cet appel de fonction             |  | 5
| ==43274==  |   by 0x109D6B: | append_cmd (utils.c:87)       | qui a ete fait ici...                 |  | 4
| ==43274==  |   by 0x109525: | fetch_a_path (init_args.c:56) | qui a ete fait ici...                 |  | 3
| ==43274==  |   by 0x10981B: | main (main.c:27)              | qui a ete fait ici!                   |  | 2
|-----------------------------------------------------------------------------------------------------|  | 1
```
---
<!-- _class: slide -->
# 1) Valgrind / Lecture de l'output
## b. Les types de leak
```
==43274== LEAK SUMMARY:
==43274== definitely lost: 12 bytes in 1 blocks	| il n'y a pas de pointeur vers ce bloc de memoire
                                                | il ne peut donc pas etre free

==43274== indirectly lost: 0 bytes in 0 blocks 	| un pointeur existe, mais il n'est accessible que par un
                                                | bloc memoire definitely lost

==43274== possibly lost: 0 bytes in 0 blocks	| un pointeur en direction du bloc existe, 
                                                | mais il ne pointe pas vers le debut.

==43274== still reachable: 0 bytes in 0 blocks	| un pointeur vers le bloc existe mais il n'a pas ete free

==43274== suppressed: 0 bytes in 0 blocks	| leaks cachees par le fichier de suppression
```
⚠️ Un leak est un leak, meme s'il est still reachable ⚠️

---
<!-- _class: slide -->
# 1) Valgrind / Lecture de l'output
## c. Les autres erreurs de Valgrind
- `Invalid read of size n`: peut causer un segfault
- `Conditional jump or move depends on uninitialised value(s)`: le programme essaye d'evaluer une variable non-initialisee
- `Invalid free()` : le pointeur ne peut pas etre free (soit il l'a deja ete, soit il n'a pas ete alloue sur la heap)

---
<!-- _class: slide -->
# 1) Valgrind / De l'importance des erreur Valgrind

- Si Valgrind remonte une erreur, c'est qu'elle peut causer un probleme.
- Un invalid read est un segfault qui a eu de la chance.
- Un leak peut:
    - Ralentir l'application et le systeme, 
    - Causer des crashs et des comportements inattendus,
    - Permettre l'exploitation d'informations sensibles restees en memoire
- L'IT, c'est une histoire de scope: ce qui ne pose pas probleme sur GNL sera surement un soucis sur un Kernel ou une application Cloud utilisee par des milliers de personnes (voir: CrowdStrike crash)
