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

--- 
<!-- _class: slide -->
# 1) Valgrind / Compiler pour le debug
- Les flags de compilateurs peuvent ajouter des informations au binaire ou en retirer
- ⚠️ Valgrind et les debuggers **ralentissent** et **alourdissent** les programmes.

```
| FLAG   | POIDS  | BINAIRE |
-----------------------------
| -g3    | 175664 |  btc    |
| -g0    | 80248  |  btc    |
| -0fast | 47496  |  btc    |
```

--- 
<!-- _class: slide -->
# 1) Valgrind / Tools

