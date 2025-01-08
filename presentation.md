---
marp: true
theme: uncover
header: Atelier debug
footer: ![width:6em](assets/tutor.svg)

style: |
    section {
        font-family: monospace;
    }
    footer {
        text-align: left;
    }
    section.slide li {
    font-size: 0.7em;
    }
    section.slide h1 {
    font-size: 1em;
    }
---
# Les bases du debug
gdb, valgrind & cie

---
<!-- _class: slide -->
# Programme
0) Introduction
1) Valgrind: 
    a. Compiler pour le debug (-g3 et ses amis)
    b. Tools, flags, lecture de l'output
    c. De l'importance des erreurs Valgrind
2) GDB: GNU Debugger
    a. Quand utiliser un debugger ?
    b. Demonstration & visualisation du workflow
3) Conclusion
--- 
<!-- _class: slide -->
# 0) Introduction
- Programmer c dur
- Pourquoi Valgrind & GDB ?
    - Pertinent pour votre cursus: natif a Linux et concu pour le C 
    - S'adapte a tous les IDE
    - Concept fondamental: savoir diagnostiquer des problemes de conception logique

![width:8em](assets/gnu.svg)

--- 
<!-- _class: slide -->
# 1) Valgrind

- Multitude d'outils: Memcheck, Helgrind, CacheGrind...
- Se base sur les informations de debug generee par le flag -g[1, 2, 3]
- ⚠️ Les flags de debug sont relatifs au **compilateur**

    `gcc -Werror -Wextra -Wall -g3 *.c`
--- 
<!-- _class: slide -->
# 1) Valgrind
a. Compiler pour le debug
- Optimisent ou ajoutent des informations au binaire

```
|   POIDS    |  DATE     |  HEURE    | NOM DU PROGRAMME
Avec -g3
    175664  |    Jan  8     |   12:49 |  btc
Sans -g3
80248 Jan  8 12:51 btc
```

